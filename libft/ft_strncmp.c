/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:57:46 by klut              #+#    #+#             */
/*   Updated: 2016/12/22 18:41:44 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	i = 0;
	first = (unsigned char *)s1;
	second = (unsigned	char *)s2;
	while (n > i && first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return ((unsigned int)(first[i] - second[i]));
		i++;
	}
	if ((first[i] == 0 || second[i] == 0) && (i != n))
		return ((unsigned int)(first[i] - second[i]));
	return (0);
}
