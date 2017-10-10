/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:55:10 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 13:41:24 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processing(t_printlist *buffer, va_list arguments)
{
	int		num;

	num = 0;
	if (buffer->ct == 'd' || buffer->ct == 'D' || buffer->ct == 'i')
		num = ft_digits_cast_processing(buffer, arguments);
	if (buffer->ct == 'u' || buffer->ct == 'U' || buffer->ct == 'o'
		|| buffer->ct == 'O' || buffer->ct == 'x' || buffer->ct == 'X'
		|| buffer->ct == 'p')
		num = ft_unsigned_digits_processing(buffer, arguments);
	if (buffer->ct == 'c' || buffer->ct == 'C'
		|| buffer->ct == 's' || buffer->ct == 'S')
		num = ft_letters_processing(buffer, arguments);
	if (buffer->ct == '%')
		num = ft_percent_processing(buffer);
	return (num);
}

int		ft_percent_processing(t_printlist *buffer)
{
	int		num;
	char	*output;
	char	*temp;

	output = ft_strnew(1);
	output[0] = '%';
	ft_f_ignore_checker_digit(buffer, output);
	temp = ft_strnew(1);
	if (buffer->min_width && buffer->z_flag == 1 && !buffer->m_flag)
		temp = ft_precision_filler(buffer, temp, output);
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
