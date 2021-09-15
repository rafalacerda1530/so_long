#include "../so_long.h"

void free_mapvar(t_map *map, char **map_var)
{
	int i;
	i = 0;
	while (i < map->count_lines)
		free(map_var[i++]);
	free(map_var);
}

int print_s(char *string)
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
	return 0;	
}
