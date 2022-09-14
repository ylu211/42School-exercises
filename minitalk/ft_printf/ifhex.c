/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:14:47 by ylam              #+#    #+#             */
/*   Updated: 2022/02/05 16:15:33 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handlep(unsigned int p, const char f)
{
	if (p >= 16)
	{
		handlep(p / 16, f);
		handlep(p % 16, f);
	}
	else
	{
		if (p < 10)
			ft_putchar_fd('0' + p, 1);
		else
		{
			if (f == 'x')
				ft_putchar_fd(p - 10 + 'a', 1);
			if (f == 'X')
				ft_putchar_fd(p - 10 + 'A', 1);
		}
	}
}

int	numhex(unsigned int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		len++;
		i /= 16;
	}
	return (len);
}

int	ifhex(unsigned int i, const char f)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		handlep(i, f);
	return (numhex(i));
}
