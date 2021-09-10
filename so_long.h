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
	int		qnt_move;
	char	move_up;
	char	move_down;
	char	move_left;
	char	move_right;
} t_game;

typedef struct	s_program {
	int			start;
	int  		x;
	int  		y;
	t_game		game;

}				t_program;

typedef struct s_map
{
	void		*mlx;
	void		*window;
	void		*image;
	int		valid_map;
	int		count_lines;
	int		count_col;
	int		count_arq;
	char **map_all;
	t_game *game;
	t_program *program;

}	t_map;

int check_map_valid(t_map *map, int argc, char **argv);
int init_game(t_map *map);
void print_s(char *string);
int	check_extension(char *str, char *extension);
char **check_number_map(t_map *map, char *argv);
int print_map(t_map *map);
int print_sprite(t_map *map, int col, int line,char *path);
int move_up(t_map *map);
int move_left(t_map *map);
int move_right(t_map *map);
int move_down(t_map *map);
void zero_move(t_map *map);
void init_struct(t_program *program, t_map *map, t_game *game);
void free_map(t_map *map);
int endgame(void *banana);
#endif