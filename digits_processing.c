/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:12:31 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 14:10:11 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digits_cast_processing(t_printlist *buffer, va_list arguments)
{
	int			num;
	intmax_t	length;

	num = 0;
	length = ft_s_cast(buffer, arguments);
	num = ft_d_convertion(buffer, length);
	return (num);
}

int		ft_d_convertion(t_printlist *buffer, long long int num)
{
	char	*number;
	char	*output;
	int		filled;

	number = ft_strnew(20);
	output = ft_strnew(1);
	number = ft_itoa_base(num, number, 10);
	if (number[0] == '0')
		output = ft_zeroproc(output, number, buffer);
	else
		output = ft_dig_output(output, number, buffer);
	ft_putstr(output);
	filled = (ft_strlen(output));
	return (filled);
}

char	*ft_dig_output(char *output, char *number, t_printlist *buffer)
{
	char	*temp;

	temp = ft_strnew(0);
	ft_f_ignore_checker_digit(buffer, number);
	if (buffer->p_flag)
		output = ft_bufiller(output, '+');
	if (buffer->s_flag)
		output = ft_bufiller(output, ' ');
	output = ft_precision_filler(buffer, output, number);
	ft_sign_swap(output, number);
	output = ft_strjoin(output, number);
	temp = ft_space_filler(buffer, output, temp);
	if (buffer->m_flag == 1)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	return (output);
}

char	*ft_space_filler(t_printlist *buffer, char *output, char *temp)
{
	int		o_length;

	o_length = 0;
	o_length = buffer->min_width - ((ft_strlen(output)));
	if (o_length > 0)
	{
		while (o_length-- > 0)
			temp = ft_bufiller(temp, ' ');
	}
	return (temp);
}

char	*ft_precision_filler(t_printlist *buffer, char *out, char *number)
{
	int		o_len;

	if (buffer->h_flag && (buffer->ct == 'o' || buffer->ct == 'O'))
		o_len = buffer->precision - (ft_strlen(number) + ft_strlen(out));
	else if (number[0] == '-')
		o_len = buffer->precision - ft_strlen(number + 1);
	else
		o_len = buffer->precision - ft_strlen(number);
	while (o_len-- > 0)
		out = ft_bufiller(out, '0');
	if (buffer->z_flag == 1)
	{
		if (out[0] == '\0' && buffer->ct == 'c' && ft_strlen(number) == 0)
			o_len = buffer->min_width - 1 - (ft_strlen(out)
					+ ft_strlen(number));
		else if (out[0] == '\0' && buffer->ct == 'c' && buffer->precision == 0)
			o_len = buffer->min_width - 1 - (ft_strlen(out)
					+ ft_strlen(number));
		else
			o_len = buffer->min_width - (ft_strlen(out)
					+ ft_strlen(number));
		while (o_len-- > 0)
			out = ft_bufiller(out, '0');
	}
	return (out);
}
