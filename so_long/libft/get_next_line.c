/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:57:50 by ylam              #+#    #+#             */
/*   Updated: 2022/03/08 10:07:09 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*save_line(int fd, char *stash)
{
	char	*line;
	int	j;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	j = 1;
	while (!ft_strchr(stash, '\n') && j != 0)
	{
		j = read(fd, line, BUFFER_SIZE);
		if (j == -1)
		{
			free(line);
			return (0);
		}
		line[j] = '\0';
		stash = ft_strjoin(stash, line);
	}
	free(line);
	return (stash);
}

char	*get_line_to_return(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_new_stash(char *stash)
{
	char	*new;
	int	i;
	int	j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new)
		return (0);
	i++;
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = save_line(fd, stash);
	if (!stash)
		return (0);
	line = get_line_to_return(stash);
	stash = get_new_stash(stash);
	return (line);
}
