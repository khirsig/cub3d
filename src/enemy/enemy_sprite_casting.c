/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:19:41 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 16:54:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	enemy_sprite_casting(t_data *data)
{
	int color;
	int vMoveScreen;
	int i;
	int count;
	int d;
	int y;

	enemy_sprite_casting_sort(data);
	i = get_sprite_num(data, count);
	count = 0;
	while (count < data->numEnemies)
	{
		enemy_sprite_casting_cam_transform(data, i);
		vMoveScreen = enemy_sprite_casting_height(data, i);
		enemy_sprite_casting_width(data, i);
		while (data->enemy[i].sprite.stripe < data->enemy[i].sprite.drawEndX)
		{
			data->enemy[i].sprite.texX = (int)(256 * (data->enemy[i].sprite.stripe - (-data->enemy[i].sprite.width / 2 + data->enemy[i].sprite.ScreenX))
										* data->enemy[i].texWidth / data->enemy[i].sprite.width) / 256;
			if (data->enemy[i].sprite.transformY > 0 && data->enemy[i].sprite.stripe > 0 && data->enemy[i].sprite.stripe < WIDTH
				&& data->enemy[i].sprite.transformY < data->ray.ZBuffer[data->enemy[i].sprite.stripe])
			{
				y = data->enemy[i].sprite.drawStartY;
				while (y < data->enemy[i].sprite.drawEndY)
				{
					d = (y - vMoveScreen) * 256 - HEIGHT * 128 + data->enemy[i].sprite.height * 128;
					data->enemy[i].sprite.texY = ((d * data->enemy[i].texHeight) / data->enemy[i].sprite.height) / 256;
					color = data->enemy[i].texture[(int)data->enemy[i].animstep][data->enemy[i].texWidth * data->enemy[i].sprite.texY + data->enemy[i].sprite.texX];
					if (color != 0xFFFFFF)
					{
						my_mlx_pixel_put(&data->vars, data->enemy[i].sprite.stripe, y, color);
						if (data->mouse_x == data->enemy[i].sprite.stripe && data->mouse_y == y)
							data->mouse_on_enemy[i] = 1;
					}
					y++;
				}
			}
			data->enemy[i].sprite.stripe++;
		}
		count++;
		i = get_sprite_num(data, count);
	}
}
