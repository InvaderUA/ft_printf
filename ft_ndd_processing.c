/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndd_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:56:12 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 13:12:19 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dig_output_uo(char *output, char *number, t_printlist *buffer)
{
	char	*temp;
	int		i;

	i = -1;
	temp = ft_strnew(0);
	ft_f_ignore_checker_digit(buffer, number);
	if (buffer->h_flag || buffer->ct == 'p')
		output = ft_dies_proc(buffer, output, number);
	output = ft_precision_filler(buffer, output, number);
	output = ft_strjoin(output, number);
	temp = ft_space_filler(buffer, output, temp);
	if (buffer->m_flag == 1)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	if (buffer->ct == 'x' || buffer->ct == 'p')
	{
		while (output[++i] != '\0')
			output[i] = ft_tolower(output[i]);
	}
	return (output);
}

char	*ft_dies_proc(t_printlist *buffer, char *output, char *number)
{
	if ((buffer->ct == 'x' && number[0] == '0')
		|| (buffer->ct == 'X' && number[0] == '0'))
		return (output);
	output = ft_bufiller(output, '0');
	if (buffer->ct == 'X')
		output = ft_bufiller(output, 'X');
	else if (buffer->ct == 'x' || buffer->ct == 'p')
		output = ft_bufiller(output, 'x');
	return (output);
}

char	*ft_zeroproc(char *output, char *number, t_printlist *buffer)
{
	char	*temp;
	int		zerospaces;

	temp = ft_strnew(0);
	ft_f_ignore_checker_digit(buffer, number);
	if (buffer->p_flag && (buffer->ct == 'd' || buffer->ct == 'i'))
		output = ft_bufiller(output, '+');
	if (buffer->s_flag)
		output = ft_bufiller(output, ' ');
	if (buffer->ct == 'p')
		output = ft_dies_proc(buffer, output, number);
	if (buffer->h_flag && buffer->precision == 0 && (buffer->ct == 'o'
				|| buffer->ct == 'O'))
		output = ft_bufiller(output, '0');
	if (buffer->z_flag == 0 && buffer->precision == -1)
		output = ft_bufiller(output, '0');
	output = ft_zeroprecision(buffer, output);
	zerospaces = buffer->min_width - ((ft_strlen(output)));
	while (zerospaces-- > 0)
		temp = ft_bufiller(temp, ' ');
	if (buffer->m_flag == 1)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	return (output);
}

char	*ft_zeroprecision(t_printlist *buffer, char *output)
{
	int		o_length;

	o_length = buffer->precision;
	if (buffer->precision == 0)
		return (output);
	while (o_length-- > 0)
		output = ft_bufiller(output, '0');
	if (buffer->z_flag == 1)
	{
		o_length = buffer->min_width - ft_strlen(output);
		while (o_length-- > 0)
			output = ft_bufiller(output, '0');
	}
	return (output);
}
