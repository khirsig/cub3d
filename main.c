/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/09 15:04:25 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data data;

	data.file = open(argv[1], O_RDONLY);
	// Parsing
	parse_part_1(data.file, &data);
	printf("Print F: %i, %i, %i\n", data.maze.floor.r, data.maze.floor.g, data.maze.floor.b);
	printf("Print C: %i, %i, %i\n", data.maze.ceiling.r, data.maze.ceiling.g, data.maze.ceiling.b);

	printf("Print NO path: %s\n", data.maze.north_texture);
	printf("Print SO path: %s\n", data.maze.south_texture);
	printf("Print WE path: %s\n", data.maze.west_texture);
	printf("Print EA path: %s\n", data.maze.east_texture);
	
	close(data.file);
	return (argc);
}