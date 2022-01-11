/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:05:12 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 13:45:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Handles all possible keystrokes by the user if they are released.
** Unsets move directions and sprinting.
*/
int	key_release(int keystroke, t_data *data)
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

/*
** Handles the keys for sprinting and rotating the camera.
** Sprinting only works if stamina > 0.
*/
static void	secondary_movement(int keystroke, t_data *data)
{
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
}

/*
** Handles all possible keystrokes by the user if they are pressed.
** Saves movement direction or exits the program.
*/
int	key_press(int keystroke, t_data *data)
{
	if (keystroke == 2)
		data->player.walk_right = 1;
	if (keystroke == 0)
		data->player.walk_left = 1;
	if (keystroke == 13)
		data->player.walk_up = 1;
	if (keystroke == 1)
		data->player.walk_down = 1;
	secondary_movement(keystroke, data);
	if (keystroke == 53 || keystroke == 12)
	{
		printf("exit\n");
		exit(0);
	}
	return (0);
}
