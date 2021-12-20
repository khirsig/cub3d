/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 12:17:04 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	enemy_death(t_data *data, int i)
{
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

void	enemy_anim_cycle(t_data *data)
{
	int i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->enemy[i].animstep == 0.0000 && data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].animstep < 6.0000 && data->enemy[i].animstep > 0.0000 && data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].status == COMBAT && data->enemy[i].idlestep < 5.0000)
			data->enemy[i].idlestep += 0.10 * data->enemy[i].attack_speed;
		else if (data->enemy[i].status == COMBAT && data->enemy[i].idlestep >= 5.0000)
		{
			if ((int) data->enemy[i].animstep == 10)
				data->player.health -= data->enemy[i].damage * 0.50;
			if (data->enemy[i].animstep >= 12.0000)
			{
				data->enemy[i].idlestep = 0.0000;
				data->enemy[i].animstep = 7.0000;
			}
			data->enemy[i].animstep += 0.10;
		}
		else if (data->enemy[i].status != DEAD)
		{
			data->enemy[i].status = IDLE;
			data->enemy[i].animstep = 0.0000;
			data->enemy[i].idlestep = 5.0000;
		}
		else
		{
			if (data->enemy[i].animstep <= 13.0000)
			{
				enemy_death(data, i);	
				data->enemy[i].animstep = 15.0000;
			}
			else if (data->enemy[i].animstep >= 15.0000 && data->enemy[i].animstep <= 17.0000)
				data->enemy[i].animstep += 0.10;
		}
		i++;
	}
}
