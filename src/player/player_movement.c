/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:31:31 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:23:08 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	player_movement_left_right(t_data *data)
{
	int	x;
	int	y;

	y = (data->player.y_pos + data->player.plane_y * data->player.speed * 1.35);
	x = (data->player.x_pos + data->player.plane_x * data->player.speed * 1.35);
	if (data->player.walk_right == 1
		&& data->maze.map[y][x] != '1' && data->maze.map[y][x] != '2')
	{
		data->player.x_pos += data->player.plane_x * data->player.speed;
		data->player.y_pos += data->player.plane_y * data->player.speed;
	}
	y = (data->player.y_pos - data->player.plane_y * data->player.speed * 1.35);
	x = (data->player.x_pos - data->player.plane_x * data->player.speed * 1.35);
	if (data->player.walk_left == 1
		&& data->maze.map[y][x] != '1' && data->maze.map[y][x] != '2')
	{
		data->player.x_pos -= data->player.plane_x * data->player.speed;
		data->player.y_pos -= data->player.plane_y * data->player.speed;
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

	y = (data->player.y_pos + data->player.dir_y * data->player.speed * 1.35);
	x = (data->player.x_pos + data->player.dir_x * data->player.speed * 1.35);
	if (data->player.walk_up == 1
		&& data->maze.map[y][x] != '1' && data->maze.map[y][x] != '2')
	{
		data->player.y_pos += data->player.dir_y * data->player.speed;
		data->player.x_pos += data->player.dir_x * data->player.speed;
	}
	y = (data->player.y_pos - data->player.dir_y * data->player.speed * 1.35);
	x = (data->player.x_pos - data->player.dir_x * data->player.speed * 1.35);
	if (data->player.walk_down == 1
		&& data->maze.map[y][x] != '1' && data->maze.map[y][x] != '2')
	{
		data->player.y_pos -= data->player.dir_y * data->player.speed;
		data->player.x_pos -= data->player.dir_x * data->player.speed;
	}
	player_movement_left_right(data);
}

static void	player_rotation_right(t_data *data)
{
	double	temp;

	if ((data->player.is_rotating == 1 || data->mouse_rotation == 1)
		&& data->player.rotation_direction == RIGHT)
	{
		temp = data->player.dir_x;
		data->player.dir_x = data->player.dir_x
			* cos(-0.05) - data->player.dir_y * sin(-0.05);
		data->player.dir_y = temp
			* sin(-0.05) + data->player.dir_y * cos(-0.05);
		temp = data->player.plane_x;
		data->player.plane_x = data->player.plane_x
			* cos(-0.05) - data->player.plane_y * sin(-0.05);
		data->player.plane_y = temp
			* sin(-0.05) + data->player.plane_y * cos(-0.05);
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
		temp = data->player.dir_x;
		data->player.dir_x = data->player.dir_x
			* cos(0.05) - data->player.dir_y * sin(0.05);
		data->player.dir_y = temp
			* sin(0.05) + data->player.dir_y * cos(0.05);
		temp = data->player.plane_x;
		data->player.plane_x = data->player.plane_x
			* cos(0.05) - data->player.plane_y * sin(0.05);
		data->player.plane_y = temp
			* sin(0.05) + data->player.plane_y * cos(0.05);
	}
	player_rotation_right(data);
}
