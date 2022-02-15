/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:29:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 20:50:01 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	clean_memory(t_data *data)
{
	free(data->maze.north_texture);
	free(data->maze.south_texture);
	free(data->maze.west_texture);
	free(data->maze.east_texture);
}

/*
** Error function
*/
void	ft_putstr_error(char *str)
{
	ft_putstr_fd(str, 2);
	system("leaks cub3D");
	exit(EXIT_FAILURE);
}

/*
** Organizes all the parsing functions.
*/
void	parser(t_data *data, char *file)
{
	ft_bzero(data, sizeof(t_data));
	data->file = open(file, O_RDONLY);
	if (data->file == -1)
	{
		ft_putstr_error("Error: Map not found.\n");
		exit(EXIT_FAILURE);
	}
	parser_color_wall(data, 0);
	parser_map(data, file);
}
