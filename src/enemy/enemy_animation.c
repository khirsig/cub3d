/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:39:52 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	enemy_anim_cycle_death(t_data *data, int i)
{
	if (data->enemy[i].animstep <= 13.0000)
	{
		data->maze.map[(int)data->enemy[i].sprite.y]
		[(int)data->enemy[i].sprite.x] = '0';
		if (data->enemy[i].type == GOBLIN)
		{
			data->enemy[i].tex_height = 68;
			data->enemy[i].tex_width = 115;
		}
		if (data->enemy[i].type == RAT)
		{
			data->enemy[i].tex_height = 53;
			data->enemy[i].tex_width = 77;
		}
		data->enemy[i].animstep = 15.0000;
	}
	else if (data->enemy[i].animstep >= 15.0000
		&& data->enemy[i].animstep <= 17.0000)
		data->enemy[i].animstep += 0.10;
}

static void	enemy_anim_cycle_idle(t_data *data, int i)
{
	data->enemy[i].status = IDLE;
	data->enemy[i].animstep = 0.0000;
	data->enemy[i].idlestep = 5.0000;
}

static void	enemy_anim_cycle_combat(t_data *data, int i)
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

/*
** Slowly iterates through the different animation steps depending on status.
** Each time a new full number is reached the next texture gets drawn.
*/
void	enemy_anim_cycle(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (data->enemy[i].animstep == 0.0000 && data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].animstep < 6.0000
			&& data->enemy[i].animstep > 0.0000
			&& data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].status == COMBAT
			&& data->enemy[i].idlestep < 5.0000)
			data->enemy[i].idlestep += 0.10 * data->enemy[i].attack_speed;
		else if (data->enemy[i].status == COMBAT
			&& data->enemy[i].idlestep >= 5.0000)
			enemy_anim_cycle_combat(data, i);
		else if (data->enemy[i].status != DEAD)
			enemy_anim_cycle_idle(data, i);
		else
			enemy_anim_cycle_death(data, i);
		i++;
	}
}
