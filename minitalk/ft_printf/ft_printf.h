/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:25:55 by ylam              #+#    #+#             */
/*   Updated: 2022/02/05 17:30:59 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *c, ...);
int		ifchar(char c);
int		ifstr(char *c);
int		ifpointer(unsigned long int p);
int		ifdcm(int i);
int		ifhex(unsigned int i, const char f);
int		ifunsigned(unsigned int i);
void	handlepg(unsigned long int p);
void	handlep(unsigned int p, const char f);
int		ifpercent(void);

#endif
