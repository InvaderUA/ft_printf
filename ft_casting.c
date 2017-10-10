/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:56:59 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 12:35:53 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_u_cast(t_printlist *buffer, va_list arguments)
{
	uintmax_t	num;

	num = va_arg(arguments, intmax_t);
	if (buffer->specificator == 1)
		num = (size_t)num;
	else if (buffer->specificator == 2)
		num = (uintmax_t)num;
	else if (buffer->specificator == 3)
		num = (unsigned long long int)num;
	else if (buffer->specificator == 4 || buffer->ct == 'U'
			|| buffer->ct == 'O' || buffer->ct == 'p')
		num = (unsigned long int)num;
	else if (buffer->specificator == 5)
		num = (unsigned short int)num;
	else if (buffer->specificator == 6)
		num = (unsigned char)num;
	else
		num = (unsigned int)num;
	return (num);
}

intmax_t	ft_s_cast(t_printlist *buffer, va_list arguments)
{
	intmax_t	num;

	num = va_arg(arguments, intmax_t);
	if (buffer->specificator == 1)
		num = (size_t)num;
	else if (buffer->specificator == 2)
		num = (intmax_t)num;
	else if (buffer->specificator == 3)
		num = (long long int)num;
	else if (buffer->specificator == 4 || buffer->ct == 'D')
		num = (long int)num;
	else if (buffer->specificator == 5)
		num = (short int)num;
	else if (buffer->specificator == 6)
		num = (signed char)num;
	else
		num = (int)num;
	return (num);
}
