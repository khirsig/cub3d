/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:31:31 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/14 10:45:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
int	player_movement(t_data *data)
{
	if (data->player.walk_up == 1)
	{
		data->player.y_pos += data->player.dirY * 0.10;
		data->player.x_pos += data->player.dirX * 0.10;
	}
	if (data->player.walk_down == 1)
	{
		data->player.y_pos -= data->player.dirY * 0.10;
		data->player.x_pos -= data->player.dirX * 0.10;
	}
	if (data->player.walk_right == 1)
		data->player.x_pos +=  data->player.planeX * 0.10;
	if (data->player.walk_left == 1)
		data->player.x_pos -= data->player.planeX * 0.10;
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

int	keyhook(int keystroke, t_data *data)
{
	if (keystroke == 53 || keystroke == 12)
	{
		mlx_destroy_window(data->vars.mlx, data->vars.mlx_win);
		exit(0);
	}
	return (0);
}
