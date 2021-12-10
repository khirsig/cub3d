/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/10 13:51:35 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		index;

	(void)argc;
	data.file = open(argv[1], O_RDONLY);
	if (data.file == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	parse_part_1(data.file, &data);
	
	if (parse_map(&data, argv[1]) == 0)
		return (1);
	index = 0;
	if (error_map(&data, data.maze.map) == 0)
		return (1);
	while (data.maze.map[index] != NULL)
	{
		printf("|%s|\n", data.maze.map[index]);
		index++;
	}
	close(data.file);
	return (0);
}