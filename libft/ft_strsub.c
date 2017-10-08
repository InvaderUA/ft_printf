/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:45:04 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 18:29:37 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (s1 != NULL)
	{
		i = 0;
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			while (i < len)
			{
				ptr[i] = s1[i + start];
				++i;
			}
			ptr[i] = '\0';
		}
		return (ptr);
	}
	return (NULL);
}
