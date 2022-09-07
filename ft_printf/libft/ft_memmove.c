/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:03:50 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:04:33 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = len;
	d = (char *) dst;
	s = (char *) src;
	if (dst == src)
		return (dst);
	if (s < d)
		while (i-- > 0)
			*(d + i) = *(s + i);
	else
		while (i-- > 0)
			*d++ = *s++;
	return (dst);
}
