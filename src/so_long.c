#include "../so_long.h"

void init_struct(t_program *program, t_map *map)
{
	program->start = 0;
	map->valid_map = 0;
	map->count_lines = -1;
	map->count_col = 0;;
	map->count_arq = 0;
	map->game.qnt_collect = 0;
	map->game.qnt_move = 0;
}

int main(int argc, char **argv)
{
	t_program program;
	t_map map;
	int i = 0;

	map.program->argv = argv;
	init_struct(&program, &map);
	map.valid_map = check_map_valid(&map, argc, argv);
	
	if (map.valid_map > 0)
		init_game(&map);
	else
		return 0;

	i = 0;
	while (i <= map.count_lines)
	{
		free(map.map_all[i++]);
		//free(map.map_bkp[i++]);
	}
	free(map.map_all);
	//free(map.map_bkp);

	return 1;
}
