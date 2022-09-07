/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:09:14 by ylam              #+#    #+#             */
/*   Updated: 2022/01/25 09:51:40 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	unsigned int	i;
	int				words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (words);
}

static char	**ft_free(char **str)
{
	while (*str)
	{
		free(str);
		str++;
	}
	free(str);
	return (NULL);
}

static char	*ft_cpy(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a;
	char	**str;

	if (!s)
		return (NULL);
	a = ft_count(s, c);
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (a--)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_cpy(s, c);
		if (!(str[i]))
			return (ft_free(str));
		s += ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
