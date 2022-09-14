/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:25:45 by ylam              #+#    #+#             */
/*   Updated: 2022/02/05 17:53:27 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handleformat(va_list args, const char f)
{
	int	p;

	p = 0;
	if (f == 'c')
		p += ifchar(va_arg(args, int));
	else if (f == 's')
		p += ifstr(va_arg(args, char *));
	else if (f == 'p')
		p += ifpointer(va_arg(args, unsigned long int));
	else if (f == 'd' || f == 'i')
		p += ifdcm(va_arg(args, int));
	else if (f == 'u')
		p += ifunsigned(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		p += ifhex(va_arg(args, unsigned int), f);
	else if (f == '%')
		p += ifpercent();
	return (p);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		p;

	va_start(args, str);
	p = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			p += handleformat(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			p += 1;
		}
		i++;
	}
	va_end(args);
	return (p);
}
