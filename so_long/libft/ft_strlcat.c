/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:20:12 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:21:47 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (dstsize == 0)
		return (b);
	if (dstsize <= a)
		return (b + dstsize);
	while (a + i < dstsize - 1 && src[i] != '\0')
	{
		dst[a + i] = src[i];
		i++;
	}
	dst[a + i] = '\0';
	return (a + b);
}
