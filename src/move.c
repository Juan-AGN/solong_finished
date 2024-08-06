/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:59:20 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:15:32 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *screen)
{
	if (screen->so_info->map[screen->so_info->character_y + 1]
		[screen->so_info->character_x] != '1')
	{
		screen->so_info->character_y ++;
		screen->img_character->instances->y = 64 * screen->so_info->character_y;
		screen->movements ++;
		ft_printf("\n Movements done: %u \n", screen->movements);
		collectable_check(screen);
	}
}

void	move_up(t_game *screen)
{
	if (screen->so_info->map[screen->so_info->character_y - 1]
		[screen->so_info->character_x] != '1')
	{
		screen->so_info->character_y --;
		screen->img_character->instances->y = 64 * screen->so_info->character_y;
		screen->movements ++;
		ft_printf("\n Movements done: %u \n", screen->movements);
		collectable_check(screen);
	}
}

void	move_left(t_game *screen)
{
	if (screen->so_info->map[screen->so_info->character_y]
		[screen->so_info->character_x - 1] != '1')
	{
		screen->so_info->character_x --;
		screen->img_character->instances->x = 64 * screen->so_info->character_x;
		screen->movements ++;
		ft_printf("\n Movements done: %u \n", screen->movements);
		collectable_check(screen);
	}
}

void	move_right(t_game *screen)
{
	if (screen->so_info->map[screen->so_info->character_y]
		[screen->so_info->character_x + 1] != '1')
	{
		screen->so_info->character_x ++;
		screen->img_character->instances->x = 64 * screen->so_info->character_x;
		screen->movements ++;
		ft_printf("\n Movements done: %u \n", screen->movements);
		collectable_check(screen);
	}
}
