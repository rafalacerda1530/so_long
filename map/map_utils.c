#include "../so_long.h"

void free_map(t_map *map, char **map_var)
{
	int i = 0;
	i = 0;
	while (i <= map->count_lines)
		free(map_var[i++]);
	free(map_var);
}

int check_wall(t_map *map, char **map_var)
{
	int cont_line = 0;
	int cont_col = 0;

	while (cont_line < map->count_lines - 1)
	{
		if (map_var[cont_line][0] != '1' || map_var[cont_line][map->count_col - 1] != '1')
		{
			print_s("O mapa deve possuir paredes em volta\n");
			free_map(map, map_var);
			return 0;
		}
		if (map_var[0][cont_col] != '1' || map_var[map->count_lines - 1][cont_col] != '1')
		{
			print_s("O mapa deve possuir paredes em volta\n");
			free_map(map, map_var);
			return 0;
		}
		if (cont_col == map->count_col - 1)
		{
			cont_line++;
			cont_col = 0;
		}
		cont_col++;
	}
	return 1;
}

int check_all_map(t_map *map, char **map_var)
{
	int cont_line = 0;
	int cont_col = 0;

	while (cont_line < map->count_lines - 1)
	{
		if (map_var[cont_line][cont_col] != '1' && (map_var[cont_line][cont_col] != '0' &&
		(map_var[cont_line][cont_col]) != 'P') && map_var[cont_line][cont_col] != 'C' &&
		(map_var[cont_line][cont_col] != 'E'))
		{
			print_s("Mapa Inválido\n");
			free_map(map, map_var);
			return 0;
		}
		if (cont_col == map->count_col - 1)
		{
			cont_line++;
			cont_col = 0;
		}
		cont_col++;
	}
	return 1;	
}

char **check_number_map(t_map *map, char *argv)
{
	char **map_var;
	int fd1;
	int i = 0;

	map_var =  malloc(sizeof(char *) * map->count_lines + 8);
	if (!map_var)
		return 0;
	fd1 = open(argv, O_RDONLY);
	if (!fd1)
	{
		free_map(map, map_var);
		return 0;
	}
	while (get_next_line(fd1, &map_var[i++]))
		;
	if (!check_all_map(map, map_var))
		return 0;
	if (!check_wall(map, map_var))
		return 0;
	return map_var;
}

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
		{
			print_s("Extensão do mapa inválido\n");
			return (0);
		}
	}
	return (1);
}
