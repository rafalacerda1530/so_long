#include "../so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int print_sprite(t_map *map, t_program *program, int col, int line,char *path)
{
	void *image;

	image = mlx_xpm_file_to_image(program->mlx, path, &program->sprite_position.x, &program->sprite_position.y);
	mlx_put_image_to_window(program->mlx, program->window, image, col * 64, line * 64);

	return 1;
}

int init_game(t_program *program, t_map *map)
{
	program->mlx = mlx_init();
	program->window = mlx_new_window(program->mlx, map->count_col * 64, map->count_lines * 64, "ESCAPING FROM ATLANTA");
	
	
	print_map(map, program);

	mlx_loop(program->mlx);
	return 1;
}
