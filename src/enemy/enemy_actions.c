/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:40:23 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 10:30:09 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	enemy_update_map(t_data *data)
{
	int i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->maze.map[data->enemy[i].last_y][data->enemy[i].last_x]
			!= data->maze.map[(int)data->enemy[i].sprite.y][(int)data->enemy[i].sprite.x])
		{
			data->maze.map[data->enemy[i].last_y][data->enemy[i].last_x] = '0';
			if (data->enemy[i].type == GOBLIN)
				data->maze.map[(int)data->enemy[i].sprite.y][(int)data->enemy[i].sprite.x] = 'G';
			if (data->enemy[i].type == RAT)
				data->maze.map[(int)data->enemy[i].sprite.y][(int)data->enemy[i].sprite.x] = 'R';
			data->enemy[i].last_x = (int)data->enemy[i].sprite.x;
			data->enemy[i].last_y = (int)data->enemy[i].sprite.y;
		}
		i++;
	}
}

static void	enemy_death(t_data *data, int i)
{
	data->enemy[i].status = DEAD;
	data->maze.map[(int)data->enemy[i].sprite.y][(int)data->enemy[i].sprite.x] = '0';
	if (data->enemy[i].type == GOBLIN)
	{
		data->enemy[i].texHeight = 68;
		data->enemy[i].texWidth = 115;
	}
	if (data->enemy[i].type == RAT)
	{
		data->enemy[i].texHeight = 53;
		data->enemy[i].texWidth = 77;
	}
}

void	enemy_actions(t_data *data)
{
	int i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->enemy[i].health <= 0.000)
			enemy_death(data, i);
		if (data->enemy[i].sprite.distance <= 100.0000 && data->enemy[i].sprite.distance > data->enemy[i].min_distance && data->enemy[i].status != COMBAT && data->enemy[i].status != DEAD)
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
		else if (data->enemy[i].sprite.distance > data->enemy[i].min_distance && data->enemy[i].status == COMBAT && data->enemy[i].status != DEAD)
			data->enemy[i].status = WALK;
		else if (data->enemy[i].sprite.distance <= data->enemy[i].min_distance && data->enemy[i].status != DEAD)
			data->enemy[i].status = COMBAT;
		else if (data->enemy[i].sprite.distance > 100.0000 && data->enemy[i].status != DEAD)
			data->enemy[i].status = IDLE;
		i++;
	}
	enemy_update_map(data);
}
