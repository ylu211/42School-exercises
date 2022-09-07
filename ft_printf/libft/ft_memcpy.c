/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:03:16 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:03:42 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c;
	const char	*d;
	size_t		i;

	i = 0;
	if ((dst == src) || n == 0)
		return (dst);
	c = (char *) dst;
	d = (const char *) src;
	while (i < n)
	{
		c[i] = d[i];
		i++;
	}
	return (dst);
}
