/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:08:54 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:14:58 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_maps(char **map)
{
	size_t	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
	return (NULL);
}

void	*mass_free(void *value1, void *value2, void *value3, void *value4)
{
	if (value1 != NULL)
		free(value1);
	if (value2 != NULL)
		free(value2);
	if (value3 != NULL)
		free(value3);
	if (value4 != NULL)
		free(value4);
	return (NULL);
}

int	ft_failed_test(t_so_value *so_list)
{
	if (so_list != NULL)
	{
		if (so_list->map != NULL)
			free_maps(so_list->map);
		if (so_list->map_clone != NULL)
			free_maps(so_list->map_clone);
		free(so_list);
	}
	return (-1);
}
