/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:19:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 10:49:09 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	enemy_sprite_casting(t_data *data)
{
	int	vMoveScreen;
	int	i;
	int	count;

	enemy_sprite_casting_sort(data);
	count = 0;
	i = get_sprite_num(data, count);
	while (count < data->numEnemies)
	{
		enemy_sprite_casting_cam_transform(data, i);
		vMoveScreen = enemy_sprite_casting_height(data, i);
		enemy_sprite_casting_width(data, i);
		enemy_sprite_casting_draw(data, i, vMoveScreen);
		count++;
		i = get_sprite_num(data, count);
	}
}
