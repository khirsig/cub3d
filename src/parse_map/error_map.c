/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:13:23 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/10 10:06:56 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	error_map(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if ((y == 0 && (map[y][x] != '1' && map[y][x] != ' '))
				|| (y != 0 && (map[y][x] != '1' && map[y][x] != ' ') && map[y - 1][x] == ' '))
			{
				ft_putstr_fd("Error\n", 2);
				// printf("|%c| with value |%i| at [%i][%i]\n", map[y][x], map[y][x], y, x);
				return (0);
			}
			if ((y == data->y_length - 1 && (map[y][x] != '1' && map[y][x] != ' '))
				|| (y != data->y_length - 1 && (map[y][x] != '1' && map[y][x] != ' ') && map[y + 1][x] == ' '))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if ((x == 0 && (map[y][x] != '1' && map[y][x] != ' '))
				|| (x != 0 && (map[y][x] != '1' && map[y][x] != ' ') && map[y][x - 1] == ' '))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if ((x == data->x_length - 1 && (map[y][x] != '1' && map[y][x] != ' '))
				|| (x != data->x_length - 1 && (map[y][x] != '1' && map[y][x] != ' ') && map[y][x + 1] == ' '))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}