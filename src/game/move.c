#include "../../so_long.h"

int move_up(t_map *map)
{
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == '1')
		return 0;
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'E' && map->game->qnt_collect > 0)
		return 0;
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line - 1][map->game->pos_col] == 'E' && map->game->qnt_collect == 0)
	{
		endgame(map);
		return 1;
	}
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line - 1][map->game->pos_col] = 'P';
	map->game->move_up = 'w';
	print_map(map);
	zero_move(map);
	return 1;
}

int move_left(t_map *map)
{
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == '1')
		return 0;
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'E' && map->game->qnt_collect > 0)
		return 0;
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line][map->game->pos_col - 1] == 'E' && map->game->qnt_collect == 0)
	{
		endgame(map);
		return 1;
	}
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line][map->game->pos_col - 1] = 'P';

	map->game->move_left = 'a';
	print_map(map);
	zero_move(map);
	return 1;
}

int move_right(t_map *map)
{
	printf("colect = %d", map->game->qnt_collect);
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == '1')
		return 0;
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'E' && map->game->qnt_collect > 0)
		return 0;
	if (map->map_all[map->game->pos_line][map->game->pos_col + 1] == 'E' && map->game->qnt_collect == 0)
	{
		endgame(map);
		return 1;
	}
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line][map->game->pos_col + 1] = 'P';

	map->game->move_right = 'd';
	print_map(map);
	zero_move(map);
	return 1;
}

int move_down(t_map *map)
{
	printf("colect = %d", map->game->qnt_collect);
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == '1')
		return 0;
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'E' && map->game->qnt_collect > 0)
		return 0;
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'C')
		map->game->qnt_collect--;
	if (map->map_all[map->game->pos_line + 1][map->game->pos_col] == 'E' && map->game->qnt_collect == 0)
	{
		endgame(map);
		return 1;
	}
	map->map_all[map->game->pos_line][map->game->pos_col] = '0';
	map->map_all[map->game->pos_line + 1][map->game->pos_col] = 'P';

	map->game->move_right = 's';
	print_map(map);
	zero_move(map);
	return 1;
}
