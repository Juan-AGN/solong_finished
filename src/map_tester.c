/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:02:34 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:14:39 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_test_one(t_so_value *so_info, size_t y, size_t x)
{
	if (so_info->map[y][x] == 'P')
	{
		if (so_info->spawn_found != 0)
			return (-1);
		so_info->spawn_x = x;
		so_info->spawn_y = y;
		so_info->spawn_found = 1;
	}
	if (so_info->map[y][x] == 'E')
	{
		if (so_info->exit_found != 0)
			return (-1);
		so_info->exit_x = x;
		so_info->exit_y = y;
		so_info->exit_found = 1;
	}
	if (so_info->map[y][x] == '\0')
	{
		if (so_info->map[y + 1] != NULL)
			return (map_test_one(so_info, y + 1, 0));
		return (0);
	}
	return (map_test_one(so_info, y, x + 1));
}

int	map_test_two(t_so_value *so_info)
{
	size_t	i;

	i = 0;
	while (i != so_info->rows)
	{
		if (i != so_info->rows - 1)
		{
			if (ft_strlen(so_info->map[i]) != so_info->cols)
				return (-1);
		}
		else if (ft_strlen(so_info->map[i]) != so_info->cols - 1)
			return (-1);
		i ++;
	}
	if (i < 3 || so_info->cols < 3)
		return (-1);
	if ((i > 2 && so_info->cols > 4) || (so_info->cols > 2 && i > 4))
		return (0);
	return (-1);
}

int	map_test_three(t_so_value *so_info, size_t y, size_t x)
{
	if (y == 0 || y == so_info->rows - 1)
	{
		while (so_info->map[y][x] != '\n' && so_info->map[y][x] != '\0')
		{
			if (so_info->map[y][x] != '1')
				return (-1);
			x ++;
		}
	}
	else if (so_info->map[y][0] != '1' ||
	so_info->map[y][ft_strlen(so_info->map[y]) - 2] != '1')
		return (-1);
	if (y != so_info->rows -1)
		return (map_test_three(so_info, y + 1, 0));
	return (0);
}

int	map_test_four(t_so_value *so_info, size_t y, size_t x)
{
	if (so_info->map[y][x] != 'P' && so_info->map[y][x] != '1' &&
	so_info->map[y][x] != '0' && so_info->map[y][x] != 'E' &&
	so_info->map[y][x] != '\n' && so_info->map[y][x] != '0' &&
	so_info->map[y][x] != '\0' && so_info->map[y][x] != 'C')
	{
		return (-1);
	}
	if (so_info->map[y][x] == '\0')
	{
		if (so_info->map[y + 1] != NULL)
			return (map_test_four(so_info, y + 1, 0));
		return (0);
	}
	return (map_test_four(so_info, y, x + 1));
}

int	map_test_five(t_so_value *so_info, size_t y, size_t x)
{
	if (so_info->map_clone[y][x] == 'C')
		so_info->collectables ++;
	if (so_info->map_clone[y][x] == 'E')
		so_info->exit_found = 2;
	so_info->map_clone[y][x] = '8';
	if (so_info->map_clone[y + 1][x] != '8' && so_info->map_clone[y + 1]
		[x] != '1')
		map_test_five(so_info, y + 1, x);
	if (so_info->map_clone[y][x + 1] != '8' && so_info->map_clone[y]
		[x + 1] != '1')
		map_test_five(so_info, y, x + 1);
	if (so_info->map_clone[y][x - 1] != '8' && so_info->map_clone[y]
		[x - 1] != '1')
		map_test_five(so_info, y, x - 1);
	if (so_info->map_clone[y - 1][x] != '8' && so_info->map_clone[y - 1]
		[x] != '1')
		map_test_five(so_info, y - 1, x);
	return (0);
}
