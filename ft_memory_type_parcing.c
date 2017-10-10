/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_type_parcing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:53:44 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 14:03:01 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_memory_type_parc1(t_printlist *buffer, int i)
{
	if (ft_isalpha(buffer->f_array[i]))
	{
		if (buffer->f_array[i] == 'z')
		{
			buffer->specificator = 1;
			buffer->priority = 6;
		}
		if (buffer->f_array[i] == 'j' && buffer->priority < 6)
		{
			buffer->specificator = 2;
			buffer->priority = 5;
		}
		i = ft_memory_type_parc2(buffer, i);
	}
	return (i);
}

int		ft_memory_type_parc2(t_printlist *buffer, int i)
{
	int		num;

	num = 1;
	if (buffer->f_array[i] == 'l' && buffer->priority < 5)
	{
		while (buffer->f_array[++i] == 'l')
			num++;
		i--;
		ft_hl(buffer, num, 'l');
	}
	num = 1;
	if (buffer->f_array[i] == 'h' && buffer->priority < 3)
	{
		while (buffer->f_array[++i] == 'h')
			num++;
		ft_hl2(buffer, num, 'h');
		i--;
	}
	return (i);
}

void	ft_hl(t_printlist *buffer, int num, char c)
{
	if (c == 'l' && buffer->priority < 5)
	{
		if (num % 2 == 0)
		{
			buffer->specificator = 3;
			buffer->priority = 4;
		}
		else if (buffer->priority < 4)
		{
			buffer->specificator = 4;
			buffer->priority = 3;
		}
	}
}

void	ft_hl2(t_printlist *buffer, int num, char c)
{
	if (c == 'h' && buffer->priority < 3)
	{
		if (num % 2 != 0)
		{
			buffer->specificator = 5;
			buffer->priority = 2;
		}
		else if (buffer->priority < 2)
		{
			buffer->specificator = 6;
			buffer->priority = 1;
		}
	}
}
