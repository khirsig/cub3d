/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:03:10 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:35:06 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Looks for the sprite with the searched order, not the enemy order.
*/
int	get_sprite_num(t_data *data, int needle)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		if (data->enemy[i].sprite.order == needle)
			return (i);
		i++;
	}
	return (0);
}

/*
** Compares two sprites distance with each other and swaps them if needed.
*/
static int	enemy_sprite_casting_sort_it(t_data *data, int i, int sort_actions)
{
	int	count;
	int	next_count;
	int	temp;

	count = get_sprite_num(data, i);
	if (count + 1 < data->num_enemies)
		next_count = get_sprite_num(data, count + 1);
	if (count + 1 < data->num_enemies
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

/*
** Initializes all sprites.
*/
void	enemy_sprite_casting_sort_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
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

/*
** Sorts all the sprites in the right order depending on the distance to player.
** Always compares two next entries with each other.
** Continues to sort until no changes can be done.
*/
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
		while (i < data->num_enemies)
		{
			sort_actions = enemy_sprite_casting_sort_it(data, i, sort_actions);
			i++;
		}
	}
}
