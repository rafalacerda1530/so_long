#include "../../so_long.h"

int	endgame(void *teste)
{
	t_map	*map;

	map = teste;
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free_map(map);
	free(map->mlx);
	exit(0);
}

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
	if (keycode == 65307)
		endgame(map);
	if (keycode == 'q')
		endgame(map);
	print_steps(map);
	return (keycode);
}

int	init_game(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->ct_col * 64,
			map->ct_line * 64, "ESCAPING FROM ATLANTA");
	print_map(map);
	mlx_key_hook(map->window, key_hook, map);
	mlx_hook(map->window, 9, 1L << 21, &print_map, map);
	mlx_hook(map->window, 33, 1L << 2, &endgame, map);
	mlx_loop(map->mlx);
	return (1);
}
