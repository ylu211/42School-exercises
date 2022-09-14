#include "minitalk.h"

static void handler(int sig)
{
  static int  bit;
  static char c;

  if (sig == SIGUSR1)
    c |= 1;
  bit++;
  if (bit != 8)
    c <<= 1;
  else
  {
    write(1, &c, 1);
    bit = 0;
    c = 0;
  }
}

int main(void)
{
  struct sigaction  sig;

  ft_printf("PID : %u\n", getpid());
  sig.sa_handler = &handler;
  sigemptyset(&sig.sa_mask); //initie le sa_mask a vide, tous les signaux seront recu
  //sa_mask est le bitwise OR d'un set de constantes qui indique de bloquer tous les signaux pendant que le handler tourne
  //utile car sans elle le handler peut etre interrompu par un autre signal
  sig.sa_flags = 0; //pas de flags
  while (1)
  {
    sigaction(SIGUSR1, &sig, NULL); //signal, action, ancienne action
    sigaction(SIGUSR2, &sig, NULL); //signal = celui qu'on veut modifier
    pause(); //on utilise pause() qui suspend l'execution du programme jusqu'a ce qu'un signal soit attraper
  }
  return (0);
}
