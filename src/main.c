/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:15:06 by juan-ant          #+#    #+#             */
/*   Updated: 2024/08/06 17:15:16 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int num_arg, char **args)
{
	t_so_value	*so_list;
	int			fd;

	if (argument_handler(num_arg, args[1]) != 0)
		return (-1);
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("\nOpen error\n"));
	so_list = mapper(fd, args[1]);
	if (so_list == NULL)
		return (ft_printf("\nRead error or empty map\n"));
	so_list->exit_found = 0;
	so_list->spawn_found = 0;
	if (testing_phase(so_list) != 0)
		return (ft_failed_test(so_list));
	so_list->character_x = so_list->spawn_x;
	so_list->character_y = so_list->spawn_y;
	screen(so_list);
	ft_failed_test(so_list);
	return (0);
}

int	argument_handler(int num_arg, char *args)
{
	if (num_arg < 2)
		return (ft_printf("\nMap needed.\n"));
	if (num_arg > 2)
		return (ft_printf("\nOnly one map at a time.\n"));
	if (ft_strncmp(args + ft_strlen(args) - 4, ".ber", 4) != 0)
		return (ft_printf("\nMap needs to be a '.ber'.\n"));
	return (0);
}

int	testing_phase(t_so_value *so_list)
{
	if (collectables(so_list, 0, 0) == 0)
		return (ft_printf("\nNo collectables found, at least 1 needed (C).\n"));
	map_test_one(so_list, 0, 0);
	if (so_list->spawn_found == 0 || so_list->exit_found == 0)
	{
		return (ft_printf("\nMissing or excesive Exit(E) or Spawn(P).\n"));
	}
	if (map_test_two(so_list) == -1)
		return (ft_printf("\n\nMap needs to be rectangular and beatable.\n\n"));
	if (map_test_three(so_list, 0, 0) == -1)
		return (ft_printf("\n\nMap needs to be sorounded in walls.\n\n"));
	if (map_test_four(so_list, 0, 0) == -1)
		return (ft_printf("\n\nMap contains an not valid character.\n\n"));
	map_test_five(so_list, so_list->spawn_y, so_list->spawn_x);
	if (so_list->collectables != so_list->collectables_max
		|| so_list->exit_found != 2)
		return (ft_printf("\n\nImposible map\n\n"));
	return (0);
}
