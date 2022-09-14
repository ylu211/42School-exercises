/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:31:36 by ylam              #+#    #+#             */
/*   Updated: 2022/01/25 11:32:06 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	j;

	if (s == NULL)
		return (0);
	j = 0;
	if (start < ft_strlen(s))
		j = ft_strlen(s) - start;
	if (j > len)
		j = len;
	a = malloc(sizeof(char) * (j + 1));
	if (!a)
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	ft_strlcpy(a, s + start, j + 1);
	return (a);
}
