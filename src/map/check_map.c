# include "../../so_long.h"

int more_one( char *argv)
{
	int size;
	char buffer;
	int count;
	int  fd1;
	int	verify;

	fd1 = open(argv, O_RDONLY);
		if (!fd1)
			return 0;
	count = 0;
	verify = 0;
	while (true)
	{
		size = read(fd1, &buffer, 1);
		if ((buffer == 'P' || buffer == 'E') && size > 0)
		{
			count++;
			if (count > 2)
				return (print_s("Map inválido, deve ter apenas uma saida e um player"));
		}
		if ((buffer == 'P' || buffer == 'E' || buffer == 'C') && size > 0)
			verify++;
		if (size == 0)
			break;
	}
	if (verify != 3)
		return (print_s("Deve possuir um player e saida e um coletavel no minimo"));
	close(fd1);
	return 1;
}

int cont_col(t_map *map, int fd1, char *argv)
{
	int size;
	char buffer_c;

	fd1 = open(argv, O_RDONLY);

	while (true)
	{
		size = read(fd1, &buffer_c, 1);
		if (buffer_c == '\n')
			break;
		if (buffer_c != '\n')
			map->count_col++;
	}
	if (map->count_col < 5)
	{
		print_s("Mapa deve conter pelo menos 5 colunas");
		return 0;
	}
	close(fd1);
	return 1;
}

int cont_line(t_map *map, int fd1)
{
	int size;
	char buffer;
	map->count_lines++;
	while (true)
	{
		size = read(fd1, &buffer, 1);
		if (buffer == '\n')
			map->count_lines++;
		if (buffer != '\n' && size > 0)
		{
			map->count_arq++;
			if (buffer == 'C')
				map->game->qnt_collect++;
		}
		if (size == 0)
			break;
	}
	if (map->count_lines < 4)
	{
		print_s("Mapa deve conter mais de 3 espaços");
		return 0;
	}
	close(fd1);
	return 1;
}

int check_map_struct(t_map *map,char *argv)
{
	int fd1;

	fd1 = open(argv, O_RDONLY);
	if (!fd1)
		return 0;
	if (!cont_line(map, fd1))
		return 0;
	if (!cont_col(map, fd1, argv))
		return 0;
	close(fd1);
	if (map->count_arq  / map->count_col != map->count_lines)
	{
		print_s("Linhas e colunas incorretos\n");
		return 0;
	}
	else
		return 1;
}

int check_map_valid(t_map *map, int argc, char **argv)
{
	if (argc == 1)
	{
		print_s("Nenhum argumento utilizado\n");
		return 0;
	}
	if (argc > 2)
		print_s("Será utilizado apenas o primeiro arquivo\n");
	if (!check_extension(argv[1], ".ber"))
		return 0;
	if (!check_map_struct(map, argv[1]))
		return 0;
	if (!more_one(argv[1]))
		return 0;
	map->map_all = check_number_map(map, argv[1]);
	if (map->map_all == 0)
		return 0;

	return 1;
}