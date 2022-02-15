/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:40:23 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:34:41 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Updates the map char ** with the changing position of each enemy.
*/
static void	enemy_update_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (data->maze.map[data->enemy[i].last_y][data->enemy[i].last_x]
			!= data->maze.map[(int)data->enemy[i].sprite.y]
			[(int)data->enemy[i].sprite.x])
		{
			data->maze.map[data->enemy[i].last_y][data->enemy[i].last_x] = '0';
			if (data->enemy[i].type == GOBLIN)
				data->maze.map[(int)data->enemy[i].sprite.y]
				[(int)data->enemy[i].sprite.x] = 'G';
			if (data->enemy[i].type == RAT)
				data->maze.map[(int)data->enemy[i].sprite.y]
				[(int)data->enemy[i].sprite.x] = 'R';
			data->enemy[i].last_x = (int)data->enemy[i].sprite.x;
			data->enemy[i].last_y = (int)data->enemy[i].sprite.y;
		}
		i++;
	}
}

/*
** Moves the enemy in player direction.
*/
static void	enemy_walk(t_data *data, int i)
{
	data->enemy[i].status = WALK;
	if (data->enemy[i].sprite.y > data->player.y_pos)
		data->enemy[i].sprite.y -= data->player.y_pos
			* data->enemy[i].move_speed;
	if (data->enemy[i].sprite.y < data->player.y_pos)
		data->enemy[i].sprite.y += data->player.y_pos
			* data->enemy[i].move_speed;
	if (data->enemy[i].sprite.x > data->player.x_pos)
		data->enemy[i].sprite.x -= data->player.x_pos
			* data->enemy[i].move_speed;
	if (data->enemy[i].sprite.x < data->player.x_pos)
		data->enemy[i].sprite.x += data->player.x_pos
			* data->enemy[i].move_speed;
}

/*
** Changes the enemies actions and status.
** Checks for the distance to player to do so.
*/
void	enemy_actions(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (data->enemy[i].health <= 0.000)
			data->enemy[i].status = DEAD;
		if (data->enemy[i].sprite.distance <= 100.0000
			&& data->enemy[i].sprite.distance > data->enemy[i].min_distance
			&& data->enemy[i].status != COMBAT && data->enemy[i].status != DEAD)
		{
			enemy_walk(data, i);
		}
		else if (data->enemy[i].sprite.distance > data->enemy[i].min_distance
			&& data->enemy[i].status == COMBAT && data->enemy[i].status != DEAD)
			data->enemy[i].status = WALK;
		else if (data->enemy[i].sprite.distance <= data->enemy[i].min_distance
			&& data->enemy[i].status != DEAD)
			data->enemy[i].status = COMBAT;
		else if (data->enemy[i].sprite.distance > 100.0000
			&& data->enemy[i].status != DEAD)
			data->enemy[i].status = IDLE;
		i++;
	}
	enemy_update_map(data);
}
