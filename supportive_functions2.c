/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportive_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 19:20:16 by klut              #+#    #+#             */
/*   Updated: 2017/10/08 19:21:22 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_invalid_processing(t_printlist *buffer)
{
	char *temp;
	int num;

	temp = ft_strnew(1);
	if (buffer->z_flag && !buffer->m_flag)
		temp = ft_precision_filler(buffer, temp, buffer->data);
	else
		temp = ft_space_filler(buffer, buffer->data, temp);
	if (buffer->m_flag)
		buffer->data = ft_strjoin(buffer->data, temp);
	else
		buffer->data = ft_strjoin(temp, buffer->data);
	ft_putstr(buffer->data);
	num = ft_strlen(buffer->data);
	return (num);
}