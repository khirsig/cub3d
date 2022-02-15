/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:35:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:35:25 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Returns the enemy ID which the cursor is on top of if there is any.
** If not, the function returns -1.
*/
static int	attack_which_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (data->mouse_on_enemy[i] == 1)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Handles all possible mouse buttons by the user if they are released.
*/
int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 && (data->mouse_variant == 2 || data->mouse_variant == 1))
		data->mouse_rotation = 0;
	return (0);
}

/*
** Handles all possible mouse buttons and movement by the user.
** Any click does damage if enemy is close enough and below the cursor.
*/
int	mouse_press(int button, int x, int y, t_data *data)
{
	int	num_enemy;

	(void)x;
	(void)y;
	if (button == 1 && data->mouse_variant == 2)
	{
		data->mouse_rotation = 1;
		data->player.rotation_direction = LEFT;
	}
	if (button == 1 && data->mouse_variant == 1)
	{
		data->mouse_rotation = 1;
		data->player.rotation_direction = RIGHT;
	}
	num_enemy = attack_which_enemy(data);
	if (button == 1 && data->mouse_variant == 0
		&& num_enemy != -1 && data->enemy[num_enemy].sprite.distance < 20.0000)
	{
		data->enemy[num_enemy].health -= data->player.damage;
	}
	return (0);
}
