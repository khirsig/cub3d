/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:35:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 13:27:19 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	attack_which_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->mouse_on_enemy[i] == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	int	numEnemy;

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
	numEnemy = attack_which_enemy(data);
	if (button == 1 && data->mouse_variant == 0
		&& numEnemy != -1 && data->enemy[numEnemy].sprite.distance < 20.0000)
	{
		data->enemy[numEnemy].health -= data->player.damage;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 && (data->mouse_variant == 2 || data->mouse_variant == 1))
		data->mouse_rotation = 0;
	return (0);
}
