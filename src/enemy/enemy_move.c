/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:40:23 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 20:41:56 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	enemy_movement(t_data *data)
{
	int i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->enemy[i].sprite.distance <= 100.0000 && data->enemy[i].sprite.distance > data->enemy[i].min_distance && data->enemy[i].status != COMBAT)
		{
			data->enemy[i].status = WALK;
			if (data->enemy[i].sprite.y > data->player.y_pos)
				data->enemy[i].sprite.y -= data->player.y_pos * data->enemy[i].move_speed;
			if (data->enemy[i].sprite.y < data->player.y_pos)
				data->enemy[i].sprite.y += data->player.y_pos * data->enemy[i].move_speed;
			if (data->enemy[i].sprite.x > data->player.x_pos)
				data->enemy[i].sprite.x -= data->player.x_pos * data->enemy[i].move_speed;
			if (data->enemy[i].sprite.x < data->player.x_pos)
				data->enemy[i].sprite.x += data->player.x_pos * data->enemy[i].move_speed;
		}
		else if (data->enemy[i].sprite.distance > data->enemy[i].min_distance && data->enemy[i].status == COMBAT)
			data->enemy[i].status = WALK;
		else if (data->enemy[i].sprite.distance <= data->enemy[i].min_distance)
			data->enemy[i].status = COMBAT;
		else if (data->enemy[i].sprite.distance > 100.0000)
			data->enemy[i].status = IDLE;
		i++;
	}
}