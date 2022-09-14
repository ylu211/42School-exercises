/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:03:11 by ylam              #+#    #+#             */
/*   Updated: 2022/08/02 14:35:20 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *string, char *extension)
{
	int i;
	int j;
	int k;

	i = ft_strlen(string);
	j = ft_strlen(extension);
	k = 0;
	while (k < j)
	{
		if (string[i - k] != extension[j - k])
			return (1);
		k++;
	}
	return (0);
}

void	check_parameters(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("Wrong number of parameters\n");
		exit(1);
	}
	if (check_extension(argv, ".ber") == 1)
	{
		ft_printf("Wrong extension : must be a .ber\n");
		exit(1);
	}
}
/*
void	 check_rectangular(t_data *data)
{
	int	i;

	i = 0;
	data->height = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == '\n')
			data->height += 1;
		i++;
	}
	int	j;
	j = 0;
	data->width = 0;
	while (data->map[j] != '\n')
	{
		data->width += 1;
		j++;
	}
	//to do : verifier que toutes les lignes ont la meme longueur
	ft_printf("%d %d\n", data->height, data->width);
	if (data->height == data->width)
	{
		ft_printf("Error : not a rectangle");
		exit(1);
	}
}*/
//malloc la map avec le nombre de ligne

int check_map(char *map, t_data *data)
{
//	int i = 0;
	int fd;
	fd = open(map, O_RDONLY);
	if (!fd)
		return(0);
	data->map = malloc(sizeof(char *)*data->width+1);
	if(!data->map)
		exit(1); //to do : penser a free et pas exit directement
	int i = 0;

	while ((data->map[i] = get_next_line(fd)))
	{
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
	close(fd);
	return (0);
}

void	check_size(char *map, t_data *data)
{
	int fd;
	char *str;

	fd = open(map, O_RDONLY);
	if (!fd)
	{
		ft_printf("Error\n");
		exit(1);
	}
	//src[i] = gnl i++;
	data->height = 0;
	data->width = 0;
	while ((str = get_next_line(fd)))
	{
		data->height++;
		data->width = ft_strlen(str);
		free(str);
	}
	close(fd);
	ft_printf("\n%d %d\n", data->height, data->width);
	if (data->height == data->width)
	{
		ft_printf("Error : not a rectangle");
		exit(1);
	}
}

int free_data(t_data *data)
{
	int i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}

//reste : checker si la map est rectangle
//checker qu'il y ait bien chaque element
//associer les elements de la carte au data
int main(int argc, char **argv)
{
	t_data data;

	check_parameters(argc, argv[1]);
	check_size(argv[1], &data);

	check_map(argv[1], &data);
	free_data(&data);
	return (0);
}
