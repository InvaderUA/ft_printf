/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:29:18 by klut              #+#    #+#             */
/*   Updated: 2017/09/24 15:29:20 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_processing(t_printlist *buffer, va_list arguments)
{
	int num;

	num = 0;
	if (buffer->convertion_type == 'd' || buffer->convertion_type == 'D' ||
		buffer->convertion_type == 'i')
		num = ft_digits_cast_processing(buffer, arguments);
	if (buffer->convertion_type == 'u' || buffer->convertion_type == 'U'
		|| buffer->convertion_type == 'o' || buffer->convertion_type == 'O'
		|| buffer->convertion_type == 'x' || buffer->convertion_type == 'X'
		|| buffer->convertion_type == 'p')
		num = ft_unsigned_digits_processing(buffer, arguments);
	if (buffer->convertion_type == 'c' || buffer->convertion_type == 'C'
		|| buffer->convertion_type == 's' || buffer->convertion_type == 'S')
		num = ft_letters_processing(buffer, arguments);
	if (buffer->convertion_type == '%')
		num = ft_percent_processing(buffer);
	return (num);
}

int		ft_percent_processing(t_printlist *buffer)
{
	int num;
	char *output;
	char *temp;

	output = ft_strnew(1);
	output[0] = '%';
	ft_f_ignore_checker_digit(buffer, output);
	temp = ft_strnew(1);
	if (buffer->min_width && buffer->z_flag == 1)
		output = ft_precision_filler(buffer, output, temp);
	else
		temp = ft_space_filler(buffer, output, temp);
	if (buffer->m_flag)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	num = ft_strlen(output);
	ft_putstr(output);
	return (num);
}
