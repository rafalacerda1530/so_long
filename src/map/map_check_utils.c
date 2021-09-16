#include "../../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->ct_line)
		free(map->map_all[i++]);
	free(map->map_all);
}

int	check_wall(t_map *map, char **map_var)
{
	int	cl;
	int	c_col;

	cl = 0;
	c_col = 0;
	while (cl < map->ct_line)
	{
		if (map_var[cl][0] != '1' || map_var[cl][map->ct_col - 1] != '1')
		{
			free_mapvar(map, map_var);
			return (print_s("O mapa deve possuir paredes em volta\n"));
		}
		if (map_var[0][c_col] != '1' || map_var[map->ct_line - 1][c_col] != '1')
		{
			free_mapvar(map, map_var);
			return (print_s("O mapa deve possuir paredes em volta\n"));
		}
		if (c_col == map->ct_col - 1)
		{
			cl++;
			c_col = 0;
		}
		c_col++;
	}
	return (1);
}

int	check_all_map(t_map *map, char **map_var)
{
	int	cl;
	int	c_col;

	cl = 0;
	c_col = 0;
	while (cl < map->ct_line - 1)
	{
		if (map_var[cl][c_col] != '1' && (map_var[cl][c_col] != '0' &&
		(map_var[cl][c_col]) != 'P') && map_var[cl][c_col] != 'C' &&
		(map_var[cl][c_col] != 'V' && map_var[cl][c_col] != 'E'))
		{
			print_s("Mapa Inválido\n");
			free_mapvar(map, map_var);
			return (0);
		}
		if (c_col == map->ct_col - 1)
		{
			cl++;
			c_col = 0;
		}
		c_col++;
	}
	return (1);
}

char	**check_number_map(t_map *map, char *argv)
{
	char	**map_var;
	int		fd1;
	int		i;

	i = 0;
	map_var = malloc(sizeof(char *) * map->ct_line);
	if (!map_var)
		return (0);
	fd1 = open(argv, O_RDONLY);
	if (!fd1)
	{
		free_mapvar(map, map_var);
		return (0);
	}
	while (get_next_line(fd1, &map_var[i++]))
		;
	if (!check_all_map(map, map_var))
		return (0);
	if (!check_wall(map, map_var))
		return (0);
	return (map_var);
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
