/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 10:41:04 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 15:54:39 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *str, const char *substr)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	a = (char *)str;
	b = (char *)substr;
	i = 0;
	j = 0;
	if (b[i] == '\0')
		return ((char *)str);
	while (a[i] != '\0')
	{
		while (a[i + j] == b[j])
		{
			j++;
			if (b[j] == '\0')
				return (&a[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
