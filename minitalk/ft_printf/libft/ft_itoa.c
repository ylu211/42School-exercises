/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:46:16 by ylam              #+#    #+#             */
/*   Updated: 2022/01/25 11:35:04 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_count_int(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			b;
	long int	nbr;

	nbr = n;
	b = ft_count_int(n);
	a = malloc(sizeof(char) * (b + 1));
	if (!a)
		return (NULL);
	if (n < 0)
		nbr *= -1;
	a[b] = 0;
	while (b--)
	{
		a[b] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}
