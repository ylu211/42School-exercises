/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:00:25 by ylam              #+#    #+#             */
/*   Updated: 2022/08/01 17:07:53 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_exit(char **map)
{
  int exit;
  int line;
  int column;

  exit = 0;
  line = 0;
  column = 0;
  while (map[line][column])
  {
    while (map[line][column])
    {
      if (map[line][column] == 'E')
        exit++;
      column++;
    }
    line++;
  }
  if (exit > 0)
    return 1;
}

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    char **str = argv;
    int i = check_exit(str);
    printf("%d\n", i);
  }
}
