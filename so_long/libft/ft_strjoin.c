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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	int	i;
	int	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!a)
		return (0);
	a[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	i = -1;
	if (s1)
	{
		while (s1[++i] != '\0')
			a[i] = s1[i];
		free(s1);
	}
	j = 0;
	while (s2[j] != '\0')
		a[i++] = s2[j++];
	return (a);
}
