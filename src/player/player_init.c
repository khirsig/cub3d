/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:51:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 10:06:14 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_player(t_data *data)
{
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
	return (0);
}