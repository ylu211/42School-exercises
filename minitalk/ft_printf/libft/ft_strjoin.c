/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:18:21 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:20:02 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!a)
		return (NULL);
	a[ft_strlen(s1)+ft_strlen(s2)] = '\0';
	while (*s1)
		a[i++] = *s1++;
	while (*s2)
		a[i++] = *s2++;
	return (a);
}
