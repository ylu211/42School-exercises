/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:58:47 by ylam              #+#    #+#             */
/*   Updated: 2022/01/28 16:02:22 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *stash);
char	*save_line(int fd, char *stash);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*trim_line(char	*stash);

#endif
