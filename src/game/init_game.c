#include "../../so_long.h"

int	key_hook(int keycode, t_program *program, t_map *map)
{
	printf("caracter %c\n", keycode);

	if (keycode == 'w')
	{
		map->map_all[program->game.pos_line][program->game.pos_col] = '0';
		map->map_all[program->game.pos_line - 1][program->game.pos_col] = 'P';
		print_map(map, program);
	}

}

int init_game(t_program *program, t_map *map)
{
	program->mlx = mlx_init();
	program->window = mlx_new_window(program->mlx, map->count_col * 64, map->count_lines * 64, "ESCAPING FROM ATLANTA");
	print_map(map, program);
	//printf("arq = %c\n", map->map_all[program->x][program->y]);
	//printf("arq = %c\n", map->map_all[program->x - 1][program->y]);
	mlx_key_hook(program->window, key_hook, program);
	mlx_loop(program->mlx);
	return 1;
}
