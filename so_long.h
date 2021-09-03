#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "./utils/minilbx/mlx.h"
# include "./utils/libft/libft.h"
# include "./utils/gnl/get_next_line.h"



typedef  struct  	s_game
{
	int  	qnt_collect;
	int  	pos_col;
	int  	pos_line;
} t_game;

typedef struct	s_image {
	void		*reference;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map
{
	int valid_map;
	int count_lines;
	int count_col;
	int count_arq;
	char **map_all;
	t_game game;
}	t_map;

typedef struct	s_program {
	void		*mlx;
	void		*window;
	int			start;
	int  	x;
	int  	y;
	t_image		sprite;
	t_map		map_program;
	t_game		game;

}				t_program;

int check_map_valid(t_map *map, int argc, char **argv);
int init_game(t_program *program, t_map *map);
void print_s(char *string);
int	check_extension(char *str, char *extension);
char **check_number_map(t_map *map, int argc, char *argv);
int print_map(t_map *map, t_program *program);
int print_sprite(t_map *map, t_program *program, int col, int line,char *path);
#endif