#include "../so_long.h"

void destroy_map(t_map *map)
{
	int i;
	i = 0;
	while (i <= map->count_lines)
	{
		free(map->map_all[i++]);
	}
	free(map->map_all);

	map->map_all = map->map_bkp;

	init_game(map); // ajustar, possivelmente zerar as structs para reiniciar o jogo
	return;
}

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