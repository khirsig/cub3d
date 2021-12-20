/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:51:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 16:17:35 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Helper function
*/
void	fill_player_helper(t_data *data, int h, int w)
{
	if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S' || data->maze.map[h][w] == 'E' || data->maze.map[h][w] == 'W')
	{
		data->player.x_pos = w + 0.5;
		data->player.y_pos = h + 0.5;
		if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S')
		{
			if (data->maze.map[h][w] == 'N')
			{
				data->player.planeX = -0.66;
				data->player.dirY = -1;
			}
			else
			{
				data->player.planeX = 0.66;
				data->player.dirY = 1;
			}
		}
		else
		{
			if (data->maze.map[h][w] == 'E')
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
			fill_player_helper(data, h, w);
			w++;
		}
		h++;
	}
}

void	init_player(t_data *data)
{
	fill_player(data);
	data->player.speed = 0.03;
	data->player.health = 100;
	data->player.stamina = 100;
	data->player.damage = 20;
	data->player.is_sprinting = 0;
	data->player.walk_left = 0;
	data->player.walk_right = 0;
	data->player.walk_down = 0;
	data->player.walk_up = 0;
	data->player.is_rotating = 0;
	data->player.rotation_direction = LEFT;
}
