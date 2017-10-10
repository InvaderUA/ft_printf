/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:35:49 by klut              #+#    #+#             */
/*   Updated: 2017/10/10 12:34:18 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_bufiller(const char *s1, char s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_strnew(ft_strlen(s1) + 2);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = s2;
	dest[i + 1] = '\0';
	return (dest);
}
