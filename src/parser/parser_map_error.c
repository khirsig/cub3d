/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:13:23 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 13:58:03 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Checks if the walkable space is surrounded by walls.
** Returns 1 if it finds and error.
*/
static int	is_error_map(t_data *data, char **map, int x, int y)
{
	if (((y == 0 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (y != 0 && (map[y][x] != '1'
	&& map[y][x] != ' ') && map[y - 1][x] == ' '))
	|| ((y == data->y_length - 1 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (y != data->y_length - 1
	&& (map[y][x] != '1' && map[y][x] != ' ') && map[y + 1][x] == ' '))
	|| ((x == 0 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (x != 0 && (map[y][x] != '1'
	&& map[y][x] != ' ') && map[y][x - 1] == ' '))
	|| ((x == data->x_length - 1 && (map[y][x] != '1' && map[y][x] != ' '))
	|| (x != data->x_length - 1
	&& (map[y][x] != '1' && map[y][x] != ' ') && map[y][x + 1] == ' ')))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

/*
** Iterates through the map and checks for errors.
** Returns 1 if it finds an error.
*/
int	parser_map_error(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (is_error_map(data, map, x, y) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
