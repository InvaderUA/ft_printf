/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportive_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:54:14 by klut              #+#    #+#             */
/*   Updated: 2017/10/02 15:54:16 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_f_ignore_checker_digit(t_printlist *buffer, char *number)
{
	if (number[0] == '-')
	{
		buffer->p_flag = 0;
		buffer->s_flag = 0;
	}
	if (buffer->p_flag)
		buffer->s_flag = 0;
	if (buffer->precision != -1 || buffer->m_flag)
		buffer->z_flag = 0;
}

void		ft_sign_swap(char *output, char *number)
{
	char tmp;

	if (number[0] == '-' && output[0] == '0')
	{
		tmp = *output;
		*output = *number;
		*number = tmp;
	}
}

char 		*ft_strprecision(t_printlist *buffer, char *output)
{
	char *new;
	int i;

	i = 0;
	if (buffer->precision > -1)
	{
		new = ft_strnew(buffer->precision);
		while (buffer->precision-- > 0)
		{
			new[i] = output[i];
			i++;
		}
		return (new);
	}
	return (output);
}

char	*ft_wproc2(char *wchar, char *temp1, wchar_t *output)
{
	int iter;

	iter = 0;
	if (!output)
		temp1 = ft_strdup("(null)");
	else
	{
		while(output[iter])
		{
			wchar = ft_whitechar_convertion(output[iter]);
			temp1 = ft_strjoin(temp1, wchar);
			iter++;
		}
		return (temp1);
	}
	return (temp1);
}

char	*ft_whitechar_convertion(int character)
{
	char *string;

	string = ft_strnew(4);
	if (character <= 0x0000007F)
		string[0] = character;
	else if (character <= 0x000007FF)
	{
		string[1] = (character & 0b00111111) | 0b10000000;
		string[0] = ((character >> 6) & 0b00011111) | 0b11000000;
	}
	else if (character <= 0x0000FFFF)
	{
		string[2] = (character & 0b00111111) | 0b10000000;
		string[1] = ((character >> 6) & 0b00111111) | 0b10000000;
		string[0] = ((character >> 12) & 0b00001111) | 0b11100000;
	}
	else if (character <= 0x001FFFFF)
	{
		string[3] = (character & 0b00111111) | 0b10000000;
		string[2] = ((character >> 6) & 0b00111111) | 0b10000000;
		string[1] = ((character >> 12) & 0b00111111) | 0b10000000;
		string[0] = ((character >> 18) & 0b00000111) | 0b11110000;
	}
	return (string);
}