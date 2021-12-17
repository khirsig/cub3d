/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:19:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 20:51:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	sprite_casting(t_data *data)
{
	int color;
	int vMoveScreen;
	int i;
	int w;
	int h;
	int d;
	int y;

	/*
	** sort sprites from far to close
	*/
	w = 1000;
	h = 1000;
	i = 0;
	while (i < data->numEnemies)
	{
		data->enemy[i].sprite.order = i;
		data->enemy[i].sprite.distance = ((data->player.x_pos - data->enemy[i].sprite.x) * (data->player.x_pos - data->enemy[i].sprite.x)
										+ (data->player.y_pos - data->enemy[i].sprite.y) * (data->player.y_pos - data->enemy[i].sprite.y));
		i++;
	}
	/*
	** after sorting the sprites, do the projection and draw them
	*/
	i = 0;
	while (i < data->numEnemies)
	{
		/*
		** translate sprite position to relative to camera
		*/
		data->enemy[i].sprite.spriteX = data->enemy[i].sprite.x - data->player.x_pos;
		data->enemy[i].sprite.spriteY = data->enemy[i].sprite.y - data->player.y_pos;
		/*
		** transform sprite with the inverse camera matrix
		*/
		data->enemy[i].sprite.invDet = 1.0 / (data->player.planeX * data->player.dirY - data->player.dirX * data->player.planeY);
		data->enemy[i].sprite.transformX = data->enemy[i].sprite.invDet * (data->player.dirY * data->enemy[i].sprite.spriteX - data->player.dirX * data->enemy[i].sprite.spriteY);
		data->enemy[i].sprite.transformY = data->enemy[i].sprite.invDet * (-data->player.planeY * data->enemy[i].sprite.spriteX + data->player.planeX * data->enemy[i].sprite.spriteY);
		data->enemy[i].sprite.ScreenX = (int)((w / 2) * (1 + data->enemy[i].sprite.transformX / data->enemy[i].sprite.transformY));
		/*
		** calculate height of the sprite on screen
		*/
		vMoveScreen = (int)(data->enemy[i].sprite.vMove / data->enemy[i].sprite.transformY);
		data->enemy[i].sprite.height = abs((int)(h / (data->enemy[i].sprite.transformY))) / data->enemy[i].sprite.vDiv;
		data->enemy[i].sprite.drawStartY = -data->enemy[i].sprite.height / 2 + h / 2 + vMoveScreen;
		if (data->enemy[i].sprite.drawStartY < 0)
			data->enemy[i].sprite.drawStartY = 0;
		data->enemy[i].sprite.drawEndY = data->enemy[i].sprite.height / 2 + h / 2 + vMoveScreen;
		if (data->enemy[i].sprite.drawEndY >= h)
			data->enemy[i].sprite.drawEndY = h - 1;
		/*
		** calculate width of the sprite on screen
		*/
		data->enemy[i].sprite.width = abs((int)(h / (data->enemy[i].sprite.transformY))) / data->enemy[i].sprite.uDiv;
		data->enemy[i].sprite.drawStartX = -data->enemy[i].sprite.width / 2 + data->enemy[i].sprite.ScreenX;
		if (data->enemy[i].sprite.drawStartX < 0)
			data->enemy[i].sprite.drawStartX = 0;
		data->enemy[i].sprite.drawEndX = data->enemy[i].sprite.width / 2 + data->enemy[i].sprite.ScreenX;
		if (data->enemy[i].sprite.drawEndX >= w)
			data->enemy[i].sprite.drawEndX = w - 1;
		data->enemy[i].sprite.stripe = data->enemy[i].sprite.drawStartX;
		while (data->enemy[i].sprite.stripe < data->enemy[i].sprite.drawEndX)
		{
			data->enemy[i].sprite.texX = (int)(256 * (data->enemy[i].sprite.stripe - (-data->enemy[i].sprite.width / 2 + data->enemy[i].sprite.ScreenX))
										* data->enemy[i].texWidth / data->enemy[i].sprite.width) / 256;
			if (data->enemy[i].sprite.transformY > 0 && data->enemy[i].sprite.stripe > 0 && data->enemy[i].sprite.stripe < w
				&& data->enemy[i].sprite.transformY < data->ray.ZBuffer[data->enemy[i].sprite.stripe])
			{
				y = data->enemy[i].sprite.drawStartY;
				while (y < data->enemy[i].sprite.drawEndY)
				{
					d = (y - vMoveScreen) * 256 - h * 128 + data->enemy[i].sprite.height * 128;
					data->enemy[i].sprite.texY = ((d * data->enemy[i].texHeight) / data->enemy[i].sprite.height) / 256;
					color = data->enemy[i].texture[(int)data->enemy[i].animstep][data->enemy[i].texWidth * data->enemy[i].sprite.texY + data->enemy[i].sprite.texX];
					if (color != 0xFFFFFF)
						my_mlx_pixel_put(&data->vars, data->enemy[i].sprite.stripe, y, color);
					y++;
				}
			}
			data->enemy[i].sprite.stripe++;
		}
		i++;
	}
	return (0);
}