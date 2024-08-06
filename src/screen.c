/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:03:38 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:19:31 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*screen(t_so_value *so_info)
{
	t_game	*screen;

	screen = malloc(sizeof(t_game));
	screen->movements = 0;
	screen->current_stance = mlx_init((so_info->cols - 1) * 64,
			so_info->rows * 64, "so_long", false);
	load_textures_img(screen);
	screen->so_info = so_info;
	show_map(screen, so_info, 0, 0);
	mlx_key_hook(screen->current_stance, &gameplay, screen);
	mlx_loop(screen->current_stance);
	delete_textures_img(screen);
	mlx_terminate(screen->current_stance);
	free(screen);
	return (screen);
}

int	load_textures_img(t_game *screen)
{
	screen->texture_floor = mlx_load_png("./img/so_long_placeholder_floor.png");
	screen->texture_wall = mlx_load_png("./img/so_long_placeholder.png");
	screen->texture_collectable = mlx_load_png("./img/collectable.png");
	screen->texture_character = mlx_load_png("./img/character.png");
	screen->texture_exit = mlx_load_png("./img/exit1.png");
	screen->texture_spawn = mlx_load_png("./img/spawn.png");
	screen->img_floor = mlx_texture_to_image(screen->current_stance,
			screen->texture_floor);
	screen->img_wall = mlx_texture_to_image(screen->current_stance,
			screen->texture_wall);
	screen->img_collectable = mlx_texture_to_image(screen->current_stance,
			screen->texture_collectable);
	screen->img_character = mlx_texture_to_image(screen->current_stance,
			screen->texture_character);
	screen->img_exit = mlx_texture_to_image(screen->current_stance,
			screen->texture_exit);
	screen->img_spawn = mlx_texture_to_image(screen->current_stance,
			screen->texture_spawn);
	return (1);
}

int	delete_textures_img(t_game *screen)
{
	mlx_delete_texture(screen->texture_floor);
	mlx_delete_texture(screen->texture_wall);
	mlx_delete_texture(screen->texture_character);
	mlx_delete_texture(screen->texture_collectable);
	mlx_delete_texture(screen->texture_exit);
	mlx_delete_texture(screen->texture_spawn);
	return (1);
}

int	show_map(t_game *screen, t_so_value *so_info, size_t y, size_t x)
{
	if (so_info->map[y][x] == '\0' || so_info->map[y] == NULL)
	{
		mlx_image_to_window(screen->current_stance, screen->img_character,
			so_info->character_x * 64, so_info->character_y * 64);
		return (1);
	}
	if (so_info->map[y][x] == '\n')
		return (show_map(screen, so_info, y + 1, 0));
	mlx_image_to_window(screen->current_stance,
		screen->img_floor, 64 * x, 64 * y);
	if (so_info->map[y][x] == 'E')
		mlx_image_to_window(screen->current_stance,
			screen->img_exit, 64 * x, 64 * y);
	if (so_info->map[y][x] == 'P')
		mlx_image_to_window(screen->current_stance,
			screen->img_spawn, 64 * x, 64 * y);
	if (so_info->map[y][x] == 'C')
		mlx_image_to_window(screen->current_stance,
			screen->img_collectable, 64 * x, 64 * y);
	if (so_info->map[y][x] == '1')
		mlx_image_to_window(screen->current_stance,
			screen->img_wall, 64 * x, 64 * y);
	return (show_map(screen, so_info, y, x + 1));
}
