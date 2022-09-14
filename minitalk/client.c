#include "minitalk.h"

/*
Le client envoie octet par octet le message au pid du serveur
pour chaque lettre de la string
pour chaque octet
si la lettre est >> a l'octet : on envoie sigusr2 sinon SIGUSR1

ensuite on utilise kill pour envoyer le signal au serveur avec le PID
on utilise usleep pour suspendre l'execution pendant qq microseconde
pour que le signal ne soit pas perdue

table de verite :
& : 7 & 4 = 4 -> 0111 & 0100 = 0100
-> 0 et 0 = 0, 0 et 1 = 0, 1 et 0 = 0, 1 et 1 = 1

| : 7 & 4 = 7 -> 0111 | 0100 = 0111
-> 0 ou 0 = 0, 0 ou 1 = 1, 1 ou 0 = 1, 1 ou 1 = 1

<< : first (celui dont les bits sont changer) << second (decide du nombre de place a shift)
3 : 0000 0011
3 << 1 va bouger a gauche d'une position
-> 0000 0110
on rajoute 0 a gauche
cette representation binaire correspond a 6
c'est equivalent a la multplication de 2^second
6 = 3 x 2^1

3 << 4 = 48 car 3 x 2^4

>> : meme principe que <<
3 = 0000 0011
3 >> 1 : 0000 0001 = 1
c'est equivalent a la division de 2^second
3 >> 1 -> 3 / 2^1 = 1
32 >> 4 -> 32 / 2^4 = 2

on encode en utilisant le decalage circulaire des bits
on decoupe les donnees binaire en blocks de taille 8 bits
et pour chaque bloque on fait une rotation circulaire de n bits
+1 = decalage a gauche, -1 = decalage a droite
*/

static void client_handler(int pid, char *msg)
{
	int	i;
	int j;

	j = 0;
	while (msg[j])
	{
		i = 8;
		while (i--)
		{
			if (msg[j] >> i & 1)
					kill(pid, SIGUSR1); //la fonction kill est utilise afin d'envoyer un signal a un autre processus
			else
					kill(pid, SIGUSR2);
			usleep(50);
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Must have 3 arguments.\n");
		return(0);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == 0)//si le processus existe et tourne actuellement
		client_handler(pid, argv[2]);
	ft_printf("%d\n", pid);
	return (0);
}
