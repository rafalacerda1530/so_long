#include "../../so_long.h"

int print_map(t_map *map, t_program *program)
{
	int col = 0;
	int line = 0;

	while(line < map->count_lines)
	{
		while(col < map->count_col)
		{
			if (map->map_all[line][col] == '1')
				print_sprite(map, program, col, line, "./utils/sprite/wall.xpm");
			if (map->map_all[line][col] == 'P')
				print_sprite(map, program, col, line, "./utils/sprite/hero_front.xpm");
			if (map->map_all[line][col] == '0')
				print_sprite(map, program, col, line, "./utils/sprite/floor.xpm");
			if (map->map_all[line][col] == 'C')
				print_sprite(map, program, col, line, "./utils/sprite/colect.xpm");
			if (map->map_all[line][col] == 'E')
				print_sprite(map, program, col, line, "./utils/sprite/exit.xpm");
			col++;
		}
		col = 0;
		line++;
	}
	return 1;
}