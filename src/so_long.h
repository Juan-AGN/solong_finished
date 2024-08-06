/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:48:28 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:23:30 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct t_so_value
{
	char		**map;
	char		**map_clone;
	size_t		collectables_max;
	size_t		collectables;
	size_t		character_x;
	size_t		character_y;
	size_t		exit_x;
	size_t		exit_y;
	size_t		spawn_x;
	size_t		spawn_y;
	size_t		exit_found;
	size_t		spawn_found;
	size_t		rows;
	size_t		cols;
}	t_so_value;

typedef struct t_game
{
	mlx_t			*current_stance;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_spawn;
	mlx_image_t		*img_collectable;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_character;
	t_so_value		*so_info;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_collectable;
	mlx_texture_t	*texture_character;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_spawn;
	size_t			movements;
}	t_game;

t_so_value	*mapper(int fd, char *args);

int			map_test_one(t_so_value *so_info, size_t y, size_t x);

int			map_test_two(t_so_value *so_info);

int			map_test_three(t_so_value *so_info, size_t y, size_t x);

int			map_test_five(t_so_value *so_info, size_t y, size_t x);

int			collectables(t_so_value *so_info, size_t y, size_t x);

void		create_map(t_so_value *so_info, char *args);

int			delete_textures_img(t_game *screen);

int			map_test_four(t_so_value *so_info, size_t y, size_t x);

int			collectable_banish(t_game *screen, int i);

t_game		*screen(t_so_value *so_info);

int			alloc_maps(t_so_value *so_info, int counter);

int			argument_handler(int num_arg, char *args);

void		move_down(t_game *screen);

void		move_left(t_game *screen);

void		move_right(t_game *screen);

void		move_up(t_game *screen);

void		gameplay(mlx_key_data_t keydata, void *param);

void		collectable_check(t_game *screen);

void		*mass_free(void *value1, void *value2, void *value3, void *value4);

int			show_map(t_game *screen, t_so_value *so_info, size_t y, size_t x);

void		*free_maps(char **map);

int			ft_failed_test(t_so_value *so_list);

int			testing_phase(t_so_value *so_list);

int			load_textures_img(t_game *screen);

#endif