/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:16:03 by ylam              #+#    #+#             */
/*   Updated: 2022/02/05 17:40:48 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoau(unsigned int n)
{
	char				*a;
	unsigned int		b;
	unsigned long int	nbr;

	nbr = n;
	b = 0;
	while (n != 0)
	{
		b++;
		n /= 10;
	}
	a = (char *)malloc(sizeof(char) * (b + 1));
	if (!a)
		return (NULL);
	a[b] = '\0';
	while (b--)
	{
		a[b] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (a);
}

int	ifunsigned(unsigned int i)
{
	char	*str;
	int		len;

	len = 0;
	if (i == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_itoau(i);
		len += ifstr(str);
		free(str);
	}
	return (len);
}
