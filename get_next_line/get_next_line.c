/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:23:40 by ylam              #+#    #+#             */
/*   Updated: 2022/01/28 15:27:59 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read line va lire fd et stocker buffer size de caractere dans stash
//va renvoyer null ou la chaine de caractere totale
//des qu'on a un retour a la ligne, on va arreter et renvoyer la chaine stash
//on cherchera le retour a la ligne qu'on stockera avec la chaine dans line
//stash garde les caracteres apres le retour a la ligne
//mais va free les caracteres avant puisque c'est les caracteres qui vont etre renvoyes.
#include "get_next_line.h"

//fonction qui lit BUFFER SIZE d'un fd
//s'arrete au premier '\n'
//on met au dernier caractere de line un '\0'
//on le concatene ensuite avec stash
//free line et renvoyer stash
char	*save_line(int fd, char *stash)
{
	char	*line;
	int	j;

	j = 1;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	while (!ft_strchr(stash, '\n') && j != 0)
	{
		j = read(fd, line, BUFFER_SIZE); //nombre de byte lue, -1 si pour erreur ou fin
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

//fonction qui cherche la ligne a renvoyer (avant le '\n')
//on va malloc la taille de la ligne a renvoyer
//stocker la ligne en incluant le '\n'
//rajouter un '\0' a lin de la ligne et renvoyer cette derniere
char	*get_line(char *stash)
{
	char *line;
	int i;

	i = 0;
	if(!stash[i])
		return (0);
	while(stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
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

//fonction qui va
//s'il n'y a pas de caractere apres le '\n' on free directement la stash
//sinon on creer une variable trim de taille stash - la taille de la premiere ligne + 1
//il s'agit de la ligne qui restera a la fin et qui n'est pas renvoyer
//on traverse stash on met dans trim tout ce qu'il y a apres le '\n'/tout ce qu'on ne va pas renvoyer
//on rajoute le '\0'
//on free stash puisqu'on en a plus besoin et on renvoie ce qui reste
char	*trim_line(char	*stash)
{
	char	*trim;
	int	i;
	int j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	trim = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!trim)
		return (0);
	i++;
	j = 0;
	while(stash[i])
		trim[j++] = stash[i++];
	trim[j] = '\0';
	free(stash); //free ce qu'il y a dans stash
	return (trim);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = save_line(fd, stash);
	if(!stash)
		return (0);
	line = get_line(stash);
	stash = trim_line(stash);
	return (line);
}
