#include "ft_printf.h"

int	main(void)
{
	printf("\nTEST DE POINTER\n");
	int i = ft_printf("%p", NULL);
	printf("%d\n", i);
	int j = printf("%p", NULL);
	printf("%d\n", j);
	
	printf("\nTEST DE CHAR\n");
	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');

	printf("\nTEST DE X MIN\n");
	ft_printf("%x\n", 0x82AbC);
	printf("%x\n", 0x82AbC);

	printf("\nTEST DE X MAJ\n");
	ft_printf("%X\n", 0x82aCc);
	printf("%X\n", 0x82aCc);

	printf("\nTEST DE POURCENTAGE\n");
	ft_printf("ij%%iao%%\n");
	printf("ij%%iao%%\n");
	return (0);
}
