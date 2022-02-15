/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:19:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:35:12 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Organizes the casting of all the enemy sprites.
*/
void	enemy_sprite_casting(t_data *data)
{
	int	v_move_screen;
	int	i;
	int	count;

	enemy_sprite_casting_sort(data);
	count = 0;
	i = get_sprite_num(data, count);
	while (count < data->num_enemies)
	{
		enemy_sprite_casting_cam_transform(data, i);
		v_move_screen = enemy_sprite_casting_height(data, i);
		enemy_sprite_casting_width(data, i);
		enemy_sprite_casting_draw(data, i, v_move_screen);
		count++;
		i = get_sprite_num(data, count);
	}
}
