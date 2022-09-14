# ifndef SO_LONG_H
#define SO_LONG_H
#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
/*
Fonction utile
mlx_new_image creer une nouvelle image en memoire
Retourne un void * id qui permet de manipuler cette image plus tard.
Param : mlx_ptr ; int width ; int height

Pour dessiner a l'interieur de cette image et mettre l'image a l'interieur
d'une fenetre a n'importe quelle moment pour l'afficher sur l'ecran
Pour cela on utilise : mlx_put_image_to_window
Param : mlx_ptr ; win_ptr ; img_ptr ; x ; y
x et y definissent ou l'image sera place sur la fenetre

Pour modifier l'image plus tard on utilise mlx_get_data_addr
endian : dit si la couleur de pixel sur l'image doit etre 0 ou 1
grand ou petit
Retourne une tableau de string addr

mlx_destroy_image : detruit l'image avec img_ptr

Hook
pour recevoir des events, il faut utilise mlx_loop
On peut assigner des fonctions differentes
- une cle est pressee : mlx_key_hook
- un bouton de souris est clique : mlx_mouse_hook
- une partie de la fenetre change : mlx_expose_hook


*/

typedef struct t_player
{
  int x;
  int y;
} t_player;

typedef struct t_data
{
  t_player position;
  int width; //ok
  int height; //ok
  int coins;
  int exit;
  int player;
  int move;
  char **map; //~~
  void *mlx_pointer;
  void *win_pointer;
} t_data;

void	check_parameters(int argc, char *argv);
#endif
