/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_regime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:58:00 by klut              #+#    #+#             */
/*   Updated: 2017/09/20 10:58:03 by klut             ###   ########.fr       */
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
			buffer->convertion_type = arg_data[i];
			return (i);
		}
		i++;
	}
	return (i);
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
