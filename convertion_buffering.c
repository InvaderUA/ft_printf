/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_buffering.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 16:36:26 by klut              #+#    #+#             */
/*   Updated: 2017/09/22 17:02:19 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_buffering(const char *arg_data, int i,t_printlist *buffer)
{
	while (ft_flagcheck(arg_data, i) && arg_data[i] != '\0')
	{
		buffer->f_array = ft_bufiller(buffer->f_array, arg_data[i]);
		i++;
	}
	return (i);
}

int 	ft_convletter(const char *arg_data, int i)
{
	if (arg_data[i] == 'd' || arg_data[i] == 'c' || arg_data[i] == 's' ||
		arg_data[i] == 'x' || arg_data[i] == 'X' || arg_data[i] == 'p'
		|| arg_data[i] == 'n' || arg_data[i] == 'o' || arg_data[i] == 'O'
		|| arg_data[i] == 'u' || arg_data[i] == '%' || arg_data[i] == 'i'
		|| arg_data[i] == 'D' || arg_data[i] == 'U' || arg_data[i] == 'C'
			|| arg_data[i] == 'S')
		return (1);
	return (0);
}

int 	ft_flagcheck(const char *arg_data, int i)
{
	if (arg_data[i] == ' ' || arg_data[i] == '.'|| arg_data[i] == '+'
		|| arg_data[i] == '-' || arg_data[i] == '0' || arg_data[i] == '#'||
			arg_data[i] == 'l' || arg_data[i] == 'L' || arg_data[i] == 'j'
			|| arg_data[i] == 'h' || arg_data[i] == 'z' || arg_data[i] == 't')
		return (1);
	if (ft_isdigit(arg_data[i]))
		return (1);
	return (0);
}