#include "../../so_long.h"

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 'w')
		move_up(map);
	if (keycode == 'a')
		move_left(map);
	if (keycode == 'd')
		move_right(map);
	if (keycode == 's')
		move_down(map);
	map->game.qnt_move++;
	return (keycode);
}

int init_game(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->count_col * 64, map->count_lines * 64, "ESCAPING FROM ATLANTA");
	print_map(map);
	mlx_key_hook(map->window, key_hook, map);
	mlx_loop(map->mlx);
	return 1;
}
