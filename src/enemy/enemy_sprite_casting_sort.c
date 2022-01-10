/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:03:10 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 16:16:10 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_sprite_num(t_data *data, int needle)
{
	int	i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->enemy[i].sprite.order == needle)
			return (i);
		i++;
	}
	return (0);
}

static int	enemy_sprite_casting_sort_it(t_data *data, int i, int sort_actions)
{
	int	count;
	int	next_count;
	int	temp;

	count = get_sprite_num(data, i);
	if (count + 1 < data->numEnemies)
		next_count = get_sprite_num(data, count + 1);
	if (count + 1 < data->numEnemies
		&& data->enemy[count].sprite.distance
		< data->enemy[next_count].sprite.distance)
	{
		temp = data->enemy[count].sprite.order;
		data->enemy[count].sprite.order = data->enemy[next_count].sprite.order;
		data->enemy[next_count].sprite.order = temp;
		sort_actions++;
	}
	return (sort_actions);
}

void	enemy_sprite_casting_sort_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numEnemies)
	{
		data->enemy[i].sprite.order = i;
		data->enemy[i].sprite.distance = ((data->player.x_pos
					- data->enemy[i].sprite.x) * (data->player.x_pos
					- data->enemy[i].sprite.x) + (data->player.y_pos
					- data->enemy[i].sprite.y) * (data->player.y_pos
					- data->enemy[i].sprite.y));
		data->mouse_on_enemy[i] = 0;
		i++;
	}
}

void	enemy_sprite_casting_sort(t_data *data)
{
	int	i;
	int	sort_actions;

	enemy_sprite_casting_sort_init(data);
	sort_actions = 1;
	while (sort_actions != 0)
	{
		sort_actions = 0;
		i = 0;
		while (i < data->numEnemies)
		{
			sort_actions = enemy_sprite_casting_sort_it(data, i, sort_actions);
			i++;
		}
	}
}
