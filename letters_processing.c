/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:17:15 by klut              #+#    #+#             */
/*   Updated: 2017/10/06 20:17:25 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_letters_processing(t_printlist *buffer, va_list arguments)
{
	int num;
	char *output;
	wchar_t *output_w;

	num = 0;
	if (buffer->convertion_type == 'c' || buffer->convertion_type == 'C')
		num = ft_charproc(buffer, va_arg(arguments, int));
	else if (buffer->convertion_type == 's' || buffer->convertion_type == 'S')
	{
		if (buffer->convertion_type == 's' && buffer->specificator != 4)
		{
			output = va_arg(arguments, char *);
			num = ft_strprocessing(buffer, output);
		}
		else
		{
			output_w = va_arg(arguments, wchar_t *);
			num = ft_wstringprocessing(buffer, output_w);
		}
	}
	return (num);
}

int 	ft_charproc(t_printlist *buffer, int character)
{
	int num;
	char *tmp;
	char *output;

	output = ft_strnew(1);
	tmp = ft_strnew(1);
	output = ft_whitechar_convertion(character);
	if (buffer->z_flag == 1)
		tmp = ft_precision_filler(buffer, tmp, output);
	else
		tmp = ft_cspace_filler(buffer, output, tmp, character);
	if (buffer->m_flag == 1 && buffer->z_flag == 0)
		output = ft_strjoin(output, tmp);
	else
		output = ft_strjoin(tmp, output);
	ft_putstr(output);
	num = ft_strlen(output);
	if (character == 0)
	{
		write(1, &character, 1);
		num++;
	}
	return (num);
}

char	*ft_cspace_filler(t_printlist *buffer, char *output, char *temp, int character)
{
	int o_length;

	o_length = 0;
	if (character == 0)
		o_length = buffer->min_width - 1 - ((ft_strlen(output)));
	else
		o_length = buffer->min_width - ((ft_strlen(output)));
	if (o_length > 0)
	{
		while (o_length-->0)
			temp = ft_bufiller(temp, ' ');
	}
	return (temp);
}

int		ft_strprocessing(t_printlist *buffer, char *output)
{
	int num;
	char *temp;

	temp = ft_strnew(1);
	if (!output)
		output = ft_strdup("(null)");
	ft_f_ignore_checker_digit(buffer, output);
	output = ft_strprecision(buffer, output);
	if (buffer->z_flag)
		temp = ft_precision_filler(buffer, temp, output);
	else
		temp = ft_space_filler(buffer, output, temp);
	if (buffer->m_flag == 1 && buffer->z_flag == 0)
		output = ft_strjoin(output, temp);
	else
		output = ft_strjoin(temp, output);
	num = ft_strlen(output);
	ft_putstr(output);
	return (num);
}

int		ft_wstringprocessing(t_printlist *buffer, wchar_t *output)
{
	int num;

	char *temp1;
	char *temp2;
	char *wchar;

	wchar = ft_strnew(1);
	temp1 = ft_strnew(1);
	temp2 = ft_strnew(2);
	temp1 = ft_wproc2(wchar, temp1, output);
	ft_f_ignore_checker_digit(buffer, temp1);
	temp1 = ft_strprecision(buffer, temp1);
	if (buffer->z_flag == 1)
		temp2 = ft_precision_filler(buffer, temp2, temp1);
	else
		temp2 = ft_space_filler(buffer, temp1, temp2);
	if (buffer->m_flag == 1 && buffer->z_flag == 0)
		temp1 = ft_strjoin(temp1, temp2);
	else
		temp1 = ft_strjoin(temp2, temp1);
	num = ft_strlen(temp1);
	ft_putstr(temp1);
	return (num);
}