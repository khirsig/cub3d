/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:46:35 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 13:49:12 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Helper function 2
*/
void	fill_player_helper_2(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.planeX = 0.66;
		data->player.dirY = -1;
	}
	else if (c == 'S')
	{
		data->player.planeX = -0.66;
		data->player.dirY = 1;
	}
	else if (c == 'E')
	{
		data->player.planeY = 0.66;
		data->player.dirX = 1;
	}
	else
	{
		data->player.planeY = -0.66;
		data->player.dirX = -1;
	}
}

/*
Helper function 1
*/
void	fill_player_helper_1(t_data *data, int h, int w)
{
	if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S'
		|| data->maze.map[h][w] == 'E' || data->maze.map[h][w] == 'W')
	{
		data->player.x_pos = w + 0.5;
		data->player.y_pos = h + 0.5;
		fill_player_helper_2(data, data->maze.map[h][w]);
	}
}

/*
Loops through map and fills position, direction and plane.
*/
void	fill_player(t_data *data)
{
	int	w;
	int	h;

	h = 0;
	while (data->maze.map[h])
	{
		w = 0;
		while (data->maze.map[h][w])
		{
			fill_player_helper_1(data, h, w);
			w++;
		}
		h++;
	}
}
