#include "../so_long.h"

void print_s(char *string)
{
	int i;
	int cont;

	i = 0;
	cont = -1;
	while (string[i] != '\0')
		i++;
	
	while (++cont < i)
	{
		write(1, &string[cont], 1);
	}	
}