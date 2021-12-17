/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:31:31 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 19:42:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
int	player_movement(t_data *data)
{
	int	temp_x;
	int	temp_y;

	temp_y = data->player.y_pos + data->player.dirY * data->player.speed + 0.02;
	temp_x = data->player.x_pos + data->player.dirX * data->player.speed + 0.02;
	if (data->player.walk_up == 1 && data->maze.map[temp_y][temp_x] != '1')
	{
		data->player.y_pos += data->player.dirY * data->player.speed;
		data->player.x_pos += data->player.dirX * data->player.speed;
	}
	temp_y = data->player.y_pos - data->player.dirY * data->player.speed + 0.02;
	temp_x = data->player.x_pos - data->player.dirX * data->player.speed + 0.02;
	if (data->player.walk_down == 1 && data->maze.map[temp_y][temp_x] != '1')
	{
		data->player.y_pos -= data->player.dirY * data->player.speed;
		data->player.x_pos -= data->player.dirX * data->player.speed;
	}
	temp_y = data->player.y_pos + data->player.planeY * data->player.speed + 0.02;
	temp_x = data->player.x_pos + data->player.planeX * data->player.speed + 0.02;
	if (data->player.walk_right == 1 && data->maze.map[temp_y][temp_x] != '1')
	{
		data->player.x_pos +=  data->player.planeX * data->player.speed;
		data->player.y_pos +=  data->player.planeY * data->player.speed;
	}
	temp_y = data->player.y_pos - data->player.planeY * data->player.speed + 0.02;
	temp_x = data->player.x_pos - data->player.planeX * data->player.speed + 0.02;
	if (data->player.walk_left == 1 && data->maze.map[temp_y][temp_x] != '1')
	{
		data->player.x_pos -= data->player.planeX * data->player.speed;
		data->player.y_pos -= data->player.planeY * data->player.speed;
	}
	return (0);
}

int	player_rotation(t_data *data)
{
	double temp;

	if (data->player.is_rotating == 1 && data->player.rotation_direction == LEFT)
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(0.05) - data->player.dirY * sin(0.05);
		data->player.dirY = temp * sin(0.05) + data->player.dirY * cos(0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(0.05) - data->player.planeY * sin(0.05);
		data->player.planeY = temp * sin(0.05) + data->player.planeY * cos(0.05);
	}
	if (data->player.is_rotating == 1 && data->player.rotation_direction == RIGHT)
	{
		temp = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-0.05) - data->player.dirY * sin(-0.05);
		data->player.dirY = temp * sin(-0.05) + data->player.dirY * cos(-0.05);
		temp = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.05) - data->player.planeY * sin(-0.05);
		data->player.planeY = temp * sin(-0.05) + data->player.planeY * cos(-0.05);
	}
	return (0);
}

int	player_release(int keystroke, t_data *data)
{
	if (keystroke == 257 && data->player.is_sprinting == 1)
	{
		data->player.is_sprinting = 0;
		data->player.speed = 0.03;
	}
	if (keystroke == 2)
		data->player.walk_right = 0;
	if (keystroke == 0)
		data->player.walk_left = 0;
	if (keystroke == 13)
		data->player.walk_up = 0;
	if (keystroke == 1)
		data->player.walk_down = 0;
	if (keystroke == 123 || keystroke == 124)
		data->player.is_rotating = 0;
	return (0);
}

int	player_press(int keystroke, t_data *data)
{
	if (keystroke == 2)
		data->player.walk_right = 1;
	if (keystroke == 0)
		data->player.walk_left = 1;
	if (keystroke == 13)
		data->player.walk_up = 1;
	if (keystroke == 1)
		data->player.walk_down = 1;
	if (keystroke == 257 && data->player.stamina > 0)
	{
		data->player.is_sprinting = 1;
		data->player.speed = 0.10;
	}
	if (keystroke == 124)
	{
		data->player.is_rotating = 1;
		data->player.rotation_direction = LEFT;
	}
	if (keystroke == 123)
	{
		data->player.is_rotating = 1;
		data->player.rotation_direction = RIGHT;
	}
	return (0);
}
