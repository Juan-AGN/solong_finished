/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:56:46 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:16:28 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_so_value	*mapper(int fd, char *args)
{
	t_so_value		*so_info;
	size_t			counter;
	char			*forgnl;

	so_info = malloc(sizeof(t_so_value));
	counter = 0;
	forgnl = get_next_line(fd);
	if (forgnl == NULL || so_info == NULL)
		return (mass_free(so_info, forgnl, NULL, NULL));
	while (forgnl != NULL)
	{
		free(forgnl);
		forgnl = get_next_line(fd);
		counter ++;
	}
	if (alloc_maps(so_info, counter) == -1)
		return (NULL);
	close(fd);
	so_info->rows = counter;
	create_map(so_info, args);
	so_info->cols = ft_strlen(so_info->map[0]);
	return (so_info);
}

int	alloc_maps(t_so_value *so_info, int counter)
{
	so_info->map = malloc(sizeof(char *) * counter + 1);
	if (so_info->map == NULL)
	{
		free(so_info);
		return (-1);
	}
	so_info->map_clone = malloc(sizeof(char *) * counter + 1);
	if (so_info->map_clone == NULL)
	{
		free_maps(so_info->map);
		free(so_info);
		return (-1);
	}
	return (1);
}

void	create_map(t_so_value *so_info, char *args)
{
	size_t	i;
	size_t	fd;
	size_t	fd2;

	fd = open(args, 0);
	fd2 = open(args, 0);
	i = 0;
	so_info->map[0] = get_next_line(fd);
	while (so_info->map[i] != NULL)
	{
		i ++;
		so_info->map[i] = get_next_line(fd);
	}
	i = 0;
	so_info->map_clone[0] = get_next_line(fd2);
	while (so_info->map_clone[i] != NULL)
	{
		i ++;
		so_info->map_clone[i] = get_next_line(fd2);
	}
	close(fd);
	close(fd2);
}

int	collectables(t_so_value *so_info, size_t y, size_t x)
{
	if (so_info->map[y][x] == 'C')
		so_info->collectables_max ++;
	if (so_info->map[y][x] == '\0')
	{
		if (so_info->map[y + 1] != NULL)
			return (collectables(so_info, y + 1, 0));
		return (so_info->collectables_max);
	}
	return (collectables(so_info, y, x + 1));
}
