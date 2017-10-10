/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:52:42 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 13:51:09 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_digits_processing(t_printlist *buffer, va_list arguments)
{
	int			num;
	uintmax_t	length;

	num = 0;
	length = ft_u_cast(buffer, arguments);
	num = ft_du_convertion(buffer, length);
	return (num);
}

int		ft_du_convertion(t_printlist *buffer, unsigned long int num)
{
	char	*number;
	char	*output;
	int		readed;

	number = ft_strnew(20);
	output = ft_strnew(1);
	if (buffer->ct == 'u' || buffer->ct == 'U')
		number = ft_itoa_base_u(num, number, 10);
	if (buffer->ct == 'o' || buffer->ct == 'O')
		number = ft_itoa_base_u(num, number, 8);
	if (buffer->ct == 'x' || buffer->ct == 'X'
		|| buffer->ct == 'p')
		number = ft_itoa_base_u(num, number, 16);
	if (number[0] == '0')
		output = ft_zeroproc(output, number, buffer);
	else if (buffer->ct == 'u' || buffer->ct == 'U')
		output = ft_dig_output_u(output, number, buffer);
	else if (buffer->ct == 'o' || buffer->ct == 'O' || buffer->ct == 'x'
			|| buffer->ct == 'X' || buffer->ct == 'p')
		output = ft_dig_output_uo(output, number, buffer);
	ft_putstr(output);
	return (readed = ft_strlen(output));
}

char	*ft_dig_output_u(char *output, char *number, t_printlist *buffer)
{
	char *temp;

	temp = ft_strnew(0);
	ft_f_ignore_checker_digit(buffer, number);
	output = ft_precision_filler(buffer, output, number);
	output = ft_strjoin(output, number);
	temp = ft_space_filler(buffer, output, temp);
	if (buffer->m_flag == 1)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	return (output);
}
