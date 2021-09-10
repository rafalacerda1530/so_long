#include "../../so_long.h"

int endgame(t_map *map)
{
	mlx_destroy_window(map->mlx, map->window);
	printf("mlx = %p\n", map->mlx);
	mlx_destroy_display(map->mlx);
	//free_map(map);
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
	map->game->qnt_move++;
	return (keycode);
}

int init_game(t_map *map)
{
	map->mlx = mlx_init();
	printf("mlx = %p\n", map->mlx);
	map->window = mlx_new_window(map->mlx, map->count_col * 64, map->count_lines * 64, "ESCAPING FROM ATLANTA");
	print_map(map);
	mlx_key_hook(map->window, key_hook, map);
	mlx_expose_hook(map->mlx, print_map, map);
	mlx_hook(map->window, 33, 1L << 2, endgame, map);
	mlx_loop(map->mlx);
	return 1;
}
