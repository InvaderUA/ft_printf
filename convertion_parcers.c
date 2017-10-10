/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_parcers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:03:26 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 14:01:16 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_parcing(t_printlist *buffer, int i)
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

int		ft_width_parcing(t_printlist *buffer, int i)
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

int		ft_precision_parcing(t_printlist *buffer, int i)
{
	if (buffer->f_array[i] == '.')
	{
		if (ft_isdigit(buffer->f_array[i + 1]) && buffer->f_array[i + 1])
		{
			i++;
			while (ft_isdigit(buffer->f_array[i])
					&& buffer->f_array[i] != '\0')
			{
				buffer->preci_array = ft_bufiller(buffer->preci_array,
						buffer->f_array[i]);
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
		else if (buffer->precision)
			buffer->precision = 0;
	}
	return (i);
}
