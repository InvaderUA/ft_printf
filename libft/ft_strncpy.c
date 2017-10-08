/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:12:29 by klut              #+#    #+#             */
/*   Updated: 2016/12/20 15:44:43 by klut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dest;

	dest = dst;
	while (len > 0 && *src != '\0')
	{
		*dest++ = *src++;
		--len;
	}
	ft_bzero(dest, len);
	return (dst);
}
