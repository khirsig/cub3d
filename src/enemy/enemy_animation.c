/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 11:10:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
				data->enemy[i].animstep = 15.0000;
			else if (data->enemy[i].animstep >= 15.0000 && data->enemy[i].animstep <= 17.0000)
				data->enemy[i].animstep += 0.10;
		}
		i++;
	}
}
