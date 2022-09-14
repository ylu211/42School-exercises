/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:28:53 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 18:31:27 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*a;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] != '\0' && ft_strchr(set, s1[j]))
		j++;
	i = ft_strlen(s1);
	while (i > j && ft_strchr(set, s1[i - 1]))
		i--;
	a = malloc(sizeof(char) * (i - j + 1));
	if (!a)
		return (NULL);
	k = 0;
	while (j < i)
		a[k++] = s1[j++];
	a[k] = '\0';
	return (a);
}
