#include "../../so_long.h"

void zero_move(t_map *map)
{
	map->game->move_up = 0;
	map->game->move_down = 0;
	map->game->move_left = 0;
	map->game->move_right = 0;
}

int print_sprite(t_map *map, int col, int line, char *path)
{
	map->image = mlx_xpm_file_to_image(map->mlx, path, &map->program->x, &map->program->y);
	mlx_put_image_to_window(map->mlx, map->window, map->image, col * 64, line * 64);
	mlx_destroy_image(map->mlx, map->image);
	return 1;
}

int print_map(t_map *map)
{
	int col;
	int line;

	col = 0;
	line = 0;
	while(line < map->count_lines)
	{
		while(col < map->count_col)
		{
			if (map->map_all[line][col] == '1')
				print_sprite(map, col, line, "./utils/sprite/wall.xpm");
			if (map->map_all[line][col] == 'P')
			{
				map->game->pos_line = line;
				map->game->pos_col = col;
				if (map->game->move_up == 'w')
					print_sprite(map, col, line, "./utils/sprite/hero_up.xpm");
				else if (map->game->move_left == 'a')
					print_sprite(map, col, line, "./utils/sprite/hero_left.xpm");
				else if (map->game->move_right == 'd')
					print_sprite(map, col, line, "./utils/sprite/hero_right.xpm");
				else if (map->game->move_down == 's')
					print_sprite(map, col, line, "./utils/sprite/hero_down.xpm");
				else
					print_sprite(map, col, line, "./utils/sprite/hero_front.xpm");
			}
			if (map->map_all[line][col] == '0')
				print_sprite(map, col, line, "./utils/sprite/floor.xpm");
			if (map->map_all[line][col] == 'C')
				print_sprite(map, col, line, "./utils/sprite/colect.xpm");
			if (map->map_all[line][col] == 'E')
				print_sprite(map, col, line, "./utils/sprite/exit.xpm");
			col++;
		}
		col = 0;
		line++;
	}
	return 1;
}
