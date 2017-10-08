/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_parcers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:03:26 by klut              #+#    #+#             */
/*   Updated: 2017/09/22 15:03:39 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_flag_parcing(t_printlist *buffer, int i)
{
	if (buffer->f_array[i] == '-')
		return (buffer->m_flag = 1);
	if (buffer->f_array[i] == '0')
		return (buffer->z_flag = 1);
	if (buffer->f_array[i] == '+')
		return (buffer->p_flag = 1);
	if (buffer->f_array[i] == ' ')
		return (buffer->s_flag = 1);
	if (buffer->f_array[i] == '#')
		return (buffer->h_flag = 1);
	return (0);
}

int 	ft_width_parcing(t_printlist *buffer, int i)
{
	if (ft_isdigit(buffer->f_array[i]) && buffer->f_array[i] != '0')
	{
		while (ft_isdigit(buffer->f_array[i]))
		{
			buffer->width_array = ft_bufiller(buffer->width_array,
											  buffer->f_array[i]);
			i++;
		}
		if (!ft_isdigit(buffer->f_array[i]))
		{
			buffer->min_width = ft_atoi(buffer->width_array);
			buffer->width_array = ft_bzero(buffer->width_array,
										   ft_strlen(buffer->width_array));
			return (i - 1);
		}
	}
	return (i);
}

int 	ft_precision_parcing(t_printlist *buffer, int i)
{
	if (buffer->f_array[i] == '.')
	{
		if (ft_isdigit(buffer->f_array[i + 1]) && buffer->f_array[i + 1])
		{
			i++;
			while (ft_isdigit(buffer->f_array[i])
				   && buffer->f_array[i] != '\0')
			{
				buffer->preci_array = ft_bufiller(buffer->preci_array, buffer->f_array[i]);
				if (!ft_isdigit(buffer->f_array[i + 1]))
				{
					buffer->precision = ft_atoi(buffer->preci_array);
					buffer->preci_array = ft_bzero(buffer->preci_array,
												   ft_strlen(buffer->preci_array));
				}
				i++;
			}
			return (i - 1);
		}
		else
			buffer->precision = 0;
	}
	return (i);
}

int 	ft_memory_type_parc1(t_printlist *buffer, int i)
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

int 	ft_memory_type_parc2(t_printlist *buffer, int i)
{
	int num;

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
		ft_hl(buffer, num, 'h');
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
