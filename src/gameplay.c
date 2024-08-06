/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:29:43 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:21:47 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gameplay(mlx_key_data_t keydata, void *param)
{
	t_game	*screen;

	screen = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(screen->current_stance);
	}
	else if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
	{
		move_up(screen);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
	{
		move_down(screen);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
	{
		move_left(screen);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
	{
		move_right(screen);
	}
}

void	collectable_check(t_game *screen)
{
	int	shortcut_y;
	int	shortcut_x;

	shortcut_y = screen->so_info->character_y;
	shortcut_x = screen->so_info->character_x;
	if (screen->so_info->map[shortcut_y][shortcut_x] == 'C')
	{
		screen->so_info->map[shortcut_y][shortcut_x] = '0';
		screen->so_info->collectables_max --;
		collectable_banish(screen, 0);
	}
	if (screen->so_info->map[shortcut_y][shortcut_x] == 'E'
		&& screen->so_info->collectables_max == 0)
	{
		mlx_close_window(screen->current_stance);
		ft_printf(
			"\n Congrats! You scaped in %u movements.\n", screen->movements);
	}
}

int	collectable_banish(t_game *screen, int i)
{
	int	shortcut_y;
	int	shortcut_x;
	int	shortcuti_y;
	int	shortcuti_x;

	shortcut_y = screen->img_character->instances->y;
	shortcut_x = screen->img_character->instances->x;
	shortcuti_y = screen->img_collectable->instances[i].y;
	shortcuti_x = screen->img_collectable->instances[i].x;
	if (shortcut_y == shortcuti_y && shortcut_x == shortcuti_x)
	{
		screen->img_collectable->instances[i].enabled = false;
		return (1);
	}
	return (collectable_banish(screen, i + 1));
}
