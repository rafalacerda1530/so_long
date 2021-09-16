#include "../so_long.h"

void	init_struct(t_program *program, t_map *map, t_game *game)
{
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
	map->game = game;
	map->program = program;
	program->start = 0;
	map->valid_map = 0;
	map->ct_line = 0;
	map->ct_col = 0;
	map->count_arq = 0;
	map->game->qnt_collect = 0;
	map->game->qnt_move = 0;
	program->x = 0;
	program-> y = 0;
}

int	main(int argc, char **argv)
{
	t_program	program;
	t_map		map;
	t_game		game;

	init_struct(&program, &map, &game);
	map.valid_map = check_map_valid(&map, argc, argv);
	if (map.valid_map > 0)
		init_game(&map);
	else
		return (0);
	return (1);
}
