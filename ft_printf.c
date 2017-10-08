/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:12:21 by klut              #+#    #+#             */
/*   Updated: 2017/09/13 17:12:33 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printlist		*ft_printlist_create(void)
{
	t_printlist		*lst;

	lst = (t_printlist *)malloc((sizeof(t_printlist)));
	lst->data = ft_strnew(1);
	lst->next = NULL;

	return(lst);
}

t_printlist		ft_lst_refresher(t_printlist *lst)
{
	lst->f_array = ft_strnew(1);
	lst->width_array = ft_strnew(1);
	lst->preci_array = ft_strnew(1);
	lst->convertion_type = 0;
	lst->min_width = 0;
	lst->precision = -1;
	lst->size = 0;
	lst->specificator = 0;
	lst->priority = 0;
	lst->s_flag = 0;
	lst->m_flag = 0;
	lst->z_flag = 0;
	lst->h_flag = 0;
	lst->p_flag = 0;
	return (*lst);
}

int				starting_sequence(const char *arg_data, va_list arguments)
{
	int i;
	int num;
	t_printlist *buffer;

	i = -1;
	num = 0;
	buffer = ft_printlist_create();
	while (arg_data[++i] != '\0')
	{
		*buffer = ft_lst_refresher(buffer);
		if (arg_data[i] != '%' && arg_data[i] != '\0')
		{
			write(1, &arg_data[i], 1);
			num++;
		}
		else if (arg_data[i] != '\0')
		{
			i = ft_format_regime(arg_data, i, buffer);
			if (buffer->convertion_type)
				num = num + ft_processing(buffer, arguments);
		}
	}
	ft_putstr(buffer->data);
	return (num);
}

int 	ft_printf(const char *arg_data, ...)
{
	int num;
	va_list arguments;

	va_start(arguments, arg_data);
	num = starting_sequence(arg_data, arguments);
	va_end(arguments);
	return (num);
}