/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:19:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 16:07:18 by khirsig          ###   ########.fr       */
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
		data->enemy.sprite.order = i;
		data->enemy.sprite.distance = ((data->player.x_pos - data->enemy.sprite.x) * (data->player.x_pos - data->enemy.sprite.x)
										+ (data->player.y_pos - data->enemy.sprite.y) * (data->player.y_pos - data->enemy.sprite.y));
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
		data->enemy.sprite.spriteX = data->enemy.sprite.x - data->player.x_pos;
		data->enemy.sprite.spriteY = data->enemy.sprite.y - data->player.y_pos;
		/*
		** transform sprite with the inverse camera matrix
		*/
		data->enemy.sprite.invDet = 1.0 / (data->player.planeX * data->player.dirY - data->player.dirX * data->player.planeY);
		data->enemy.sprite.transformX = data->enemy.sprite.invDet * (data->player.dirY * data->enemy.sprite.spriteX - data->player.dirX * data->enemy.sprite.spriteY);
		data->enemy.sprite.transformY = data->enemy.sprite.invDet * (-data->player.planeY * data->enemy.sprite.spriteX + data->player.planeX * data->enemy.sprite.spriteY);
		data->enemy.sprite.ScreenX = (int)((w / 2) * (1 + data->enemy.sprite.transformX / data->enemy.sprite.transformY));
		/*
		** calculate height of the sprite on screen
		*/
		vMoveScreen = (int)(data->enemy.sprite.vMove / data->enemy.sprite.transformY);
		data->enemy.sprite.height = abs((int)(h / (data->enemy.sprite.transformY))) / data->enemy.sprite.vDiv;
		data->enemy.sprite.drawStartY = -data->enemy.sprite.height / 2 + h / 2 + vMoveScreen;
		if (data->enemy.sprite.drawStartY < 0)
			data->enemy.sprite.drawStartY = 0;
		data->enemy.sprite.drawEndY = data->enemy.sprite.height / 2 + h / 2 + vMoveScreen;
		if (data->enemy.sprite.drawEndY >= h)
			data->enemy.sprite.drawEndY = h - 1;
		/*
		** calculate width of the sprite on screen
		*/
		data->enemy.sprite.width = abs((int)(h / (data->enemy.sprite.transformY))) / data->enemy.sprite.uDiv;
		data->enemy.sprite.drawStartX = -data->enemy.sprite.width / 2 + data->enemy.sprite.ScreenX;
		if (data->enemy.sprite.drawStartX < 0)
			data->enemy.sprite.drawStartX = 0;
		data->enemy.sprite.drawEndX = data->enemy.sprite.width / 2 + data->enemy.sprite.ScreenX;
		if (data->enemy.sprite.drawEndX >= w)
			data->enemy.sprite.drawEndX = w - 1;
		data->enemy.sprite.stripe = data->enemy.sprite.drawStartX;
		while (data->enemy.sprite.stripe < data->enemy.sprite.drawEndX)
		{
			data->enemy.sprite.texX = (int)(256 * (data->enemy.sprite.stripe - (-data->enemy.sprite.width / 2 + data->enemy.sprite.ScreenX))
										* data->enemy.texWidth / data->enemy.sprite.width) / 256;
			if (data->enemy.sprite.transformY > 0 && data->enemy.sprite.stripe > 0 && data->enemy.sprite.stripe < w
				&& data->enemy.sprite.transformY < data->ray.ZBuffer[data->enemy.sprite.stripe])
			{
				y = data->enemy.sprite.drawStartY;
				while (y < data->enemy.sprite.drawEndY)
				{
					d = (y - vMoveScreen) * 256 - h * 128 + data->enemy.sprite.height * 128;
					data->enemy.sprite.texY = ((d * data->enemy.texHeight) / data->enemy.sprite.height) / 256;
					color = data->enemy.texture[data->enemy.texWidth * data->enemy.sprite.texY + data->enemy.sprite.texX];
					if (color != 0xFFFFFF)
						my_mlx_pixel_put(&data->vars, data->enemy.sprite.stripe, y, color);
					y++;
				}
			}
			data->enemy.sprite.stripe++;
		}
		i++;
	}
	return (0);
}