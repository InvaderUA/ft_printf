/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:07:51 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 15:57:03 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;
	char	*b;

	a = (char *)str;
	b = (char *)substr;
	i = 0;
	j = 0;
	if (b[j] == '\0' || (!b))
		return ((char *)str);
	while (i < len && a[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && a[i + j] == b[j])
		{
			j++;
			if (b[j] == '\0')
				return (&a[i]);
		}
		i++;
	}
	return (NULL);
}
