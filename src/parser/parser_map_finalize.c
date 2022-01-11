/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_finalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:33:23 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 13:18:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	parser_map_check_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0' || c == 'R' || c == 'G'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	else
		return (1);
}

static int	parser_map_finalize_map_fill(t_data *data, char **temp, int y)
{
	int	x;
	int	strlen;

	x = 0;
	strlen = ft_strlen(temp[y]);
	data->maze.map[y] = malloc(sizeof(char) * data->x_length + 1);
	data->maze.map[y][data->x_length] = '\0';
	while (x < strlen)
	{
		if (temp[y][x] == '\n')
			break ;
		if (parser_map_check_char(temp[y][x]) == 1)
			return (1);
		data->maze.map[y][x] = temp[y][x];
		x++;
	}
	while (x < data->x_length)
	{
		data->maze.map[y][x] = ' ';
		x++;
	}
	return (0);
}

int	parser_map_finalize_map(t_data *data, char **temp)
{
	int	y;

	data->maze.map = malloc(sizeof(char *) * data->y_length + 1);
	data->maze.map[data->y_length] = NULL;
	y = 0;
	while (y < data->y_length)
	{
		if (parser_map_finalize_map_fill(data, temp, y) == 1)
			return (1);
		y++;
	}
	return (0);
}
