/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:31:31 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/17 15:06:13 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	player_movement_left_right(t_data *data)
{
	int	x;
	int	y;

	y = (data->player.y_pos + data->player.planeY * data->player.speed) + 0.08;
	x = (data->player.x_pos + data->player.planeX * data->player.speed) + 0.08;
	if (data->player.walk_right == 1 && data->maze.map[y][x] != '1')
	{
		data->player.x_pos += data->player.planeX * data->player.speed;
		data->player.y_pos += data->player.planeY * data->player.speed;
	}
	y = (data->player.y_pos - data->player.planeY * data->player.speed) + 0.08;
	x = (data->player.x_pos - data->player.planeX * data->player.speed) + 0.08;
	if (data->player.walk_left == 1 && data->maze.map[y][x] != '1')
	{
		data->player.x_pos -= data->player.planeX * data->player.speed;
		data->player.y_pos -= data->player.planeY * data->player.speed;
	}
}

/*
** Checks if the player is currently moving up, down, left or right.
** If yes, moves the player to those positions.
*/
void	player_movement(t_data *data)
{
	int	x;
	int	y;

	y = (data->player.y_pos + data->player.dirY * data->player.speed) + 0.08;
	x = (data->player.x_pos + data->player.dirX * data->player.speed) + 0.08;
	if (data->player.walk_up == 1 && data->maze.map[y][x] != '1')
	{
		data->player.y_pos += data->player.dirY * data->player.speed;
		data->player.x_pos += data->player.dirX * data->player.speed;
	}
	y = (data->player.y_pos - data->player.dirY * data->player.speed) + 0.08;
	x = (data->player.x_pos - data->player.dirX * data->player.speed) + 0.08;
	if (data->player.walk_down == 1 && data->maze.map[y][x] != '1')
	{
		data->player.y_pos -= data->player.dirY * data->player.speed;
		data->player.x_pos -= data->player.dirX * data->player.speed;
	}
	player_movement_left_right(data);
}

static void	player_rotation_right(t_data *data)
{
	double	temp;

	if ((data->player.is_rotating == 1 || data->mouse_rotation == 1)
		&& data->player.rotation_direction == RIGHT)
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX
			* cos(-0.05) - data->player.dirY * sin(-0.05);
		data->player.dirY = temp
			* sin(-0.05) + data->player.dirY * cos(-0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX
			* cos(-0.05) - data->player.planeY * sin(-0.05);
		data->player.planeY = temp
			* sin(-0.05) + data->player.planeY * cos(-0.05);
	}
}

/*
** Checks if the player is currently rotating with any input.
** If yes, rotates the camera either left or right.
*/
void	player_rotation(t_data *data)
{
	double	temp;

	if ((data->player.is_rotating == 1 || data->mouse_rotation == 1)
		&& data->player.rotation_direction == LEFT)
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX
			* cos(0.05) - data->player.dirY * sin(0.05);
		data->player.dirY = temp
			* sin(0.05) + data->player.dirY * cos(0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX
			* cos(0.05) - data->player.planeY * sin(0.05);
		data->player.planeY = temp
			* sin(0.05) + data->player.planeY * cos(0.05);
	}
	player_rotation_right(data);
}
