/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_regime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:56:37 by klut              #+#    #+#             */
/*   Updated: 2017/10/09 15:56:38 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_format_regime(const char *arg_data, int i, t_printlist *buffer)
{
	i = ft_conv_buffering(arg_data, i + 1, buffer);
	ft_conv_init(buffer);
	while (arg_data[i] != '\0')
	{
		if (ft_convletter(arg_data, i) == 1)
		{
			buffer->ct = arg_data[i];
			return (i);
		}
		else if (ft_isprint(arg_data[i]))
			buffer->data = ft_bufiller(buffer->data, arg_data[i]);
		return (i);
	}
	return (i - 1);
}

void	ft_conv_init(t_printlist *buffer)
{
	int i;

	i = 0;
	while (buffer->f_array[i] != '\0')
	{
		ft_flag_parcing(buffer, i);
		i = ft_width_parcing(buffer, i);
		i = ft_precision_parcing(buffer, i);
		i = ft_memory_type_parc1(buffer, i);
		i++;
	}
}
