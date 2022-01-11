/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting_draw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:34:32 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 10:45:49 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	enemy_sprite_casting_draw_str(t_data *data, int i, int vMoveScreen)
{
	int	d;
	int	y;
	int	color;

	y = data->enemy[i].sprite.drawStartY;
	while (y < data->enemy[i].sprite.drawEndY)
	{
		d = (y - vMoveScreen) * 256 - HEIGHT * 128
			+ data->enemy[i].sprite.height * 128;
		data->enemy[i].sprite.texY = ((d * data->enemy[i].texHeight)
				/ data->enemy[i].sprite.height) / 256;
		color = data->enemy[i].texture[(int)data->enemy[i].animstep]
		[data->enemy[i].texWidth * data->enemy[i].sprite.texY
			+ data->enemy[i].sprite.texX];
		if (color != 0xFFFFFF)
		{
			my_mlx_pixel_put(&data->vars,
				data->enemy[i].sprite.stripe, y, color);
			if (data->mouse_x == data->enemy[i].sprite.stripe
				&& data->mouse_y == y)
				data->mouse_on_enemy[i] = 1;
		}
		y++;
	}
}

void	enemy_sprite_casting_draw(t_data *data, int i, int vMoveScreen)
{
	while (data->enemy[i].sprite.stripe < data->enemy[i].sprite.drawEndX)
	{
		data->enemy[i].sprite.texX = (int)(256
				* (data->enemy[i].sprite.stripe
					- (-data->enemy[i].sprite.width / 2
						+ data->enemy[i].sprite.ScreenX))
				* data->enemy[i].texWidth / data->enemy[i].sprite.width) / 256;
		if (data->enemy[i].sprite.transformY > 0
			&& data->enemy[i].sprite.stripe > 0
			&& data->enemy[i].sprite.stripe < WIDTH
			&& data->enemy[i].sprite.transformY
			< data->ray.ZBuffer[data->enemy[i].sprite.stripe])
		{
			enemy_sprite_casting_draw_str(data, i, vMoveScreen);
		}
		data->enemy[i].sprite.stripe++;
	}
}
