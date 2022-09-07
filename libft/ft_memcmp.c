/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:01:35 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:03:06 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*a != *b)
			return (*a - *b);
		n--;
		a++;
		b++;
	}
	return (0);
}
