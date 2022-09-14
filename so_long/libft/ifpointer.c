/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:41 by ylam              #+#    #+#             */
/*   Updated: 2022/02/05 18:25:52 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handlepg(unsigned long int p)
{
	if (p >= 16)
	{
		handlepg(p / 16);
		handlepg(p % 16);
	}
	else if (p < 10)
		ft_putchar_fd('0' + p, 1);
	else
		ft_putchar_fd(p - 10 + 'a', 1);
}

int	ifpointer(unsigned long int p)
{
	int						i;
	int						a;
	unsigned long int		j;

	i = 0;
	a = 0;
	j = p;
	while (j != 0)
	{
		a++;
		j /= 16;
	}
	i += write(1, "0x", 2);
	if (p == 0)
		i += write(1, "0", 1);
	else
	{
		handlepg(p);
		i += a;
	}
	return (i);
}
