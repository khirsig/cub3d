/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting_translate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:53:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 14:07:06 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Translates and transforms the current player view to start the calculations.
*/
void	enemy_sprite_casting_cam_transform(t_data *data, int i)
{
	data->enemy[i].sprite.spriteX
		= data->enemy[i].sprite.x - data->player.x_pos;
	data->enemy[i].sprite.spriteY
		= data->enemy[i].sprite.y - data->player.y_pos;
	data->enemy[i].sprite.invDet = 1.0 / (data->player.planeX
			* data->player.dirY - data->player.dirX * data->player.planeY);
	data->enemy[i].sprite.transformX = data->enemy[i].sprite.invDet
		* (data->player.dirY * data->enemy[i].sprite.spriteX
			- data->player.dirX * data->enemy[i].sprite.spriteY);
	data->enemy[i].sprite.transformY = data->enemy[i].sprite.invDet
		* (-data->player.planeY * data->enemy[i].sprite.spriteX
			+ data->player.planeX * data->enemy[i].sprite.spriteY);
	data->enemy[i].sprite.ScreenX = (int)((WIDTH / 2)
			* (1 + data->enemy[i].sprite.transformX
				/ data->enemy[i].sprite.transformY));
}

/*
** Calculates and defines the height of the sprite.
*/
int	enemy_sprite_casting_height(t_data *data, int i)
{
	int	vMoveScreen;

	vMoveScreen = (int)(data->enemy[i].sprite.vMove
			/ data->enemy[i].sprite.transformY);
	data->enemy[i].sprite.height = abs((int)(HEIGHT
				/ (data->enemy[i].sprite.transformY)))
		/ data->enemy[i].sprite.vDiv;
	data->enemy[i].sprite.drawStartY = -data->enemy[i].sprite.height
		/ 2 + HEIGHT / 2 + vMoveScreen;
	if (data->enemy[i].sprite.drawStartY < 0)
		data->enemy[i].sprite.drawStartY = 0;
	data->enemy[i].sprite.drawEndY = data->enemy[i].sprite.height
		/ 2 + HEIGHT / 2 + vMoveScreen;
	if (data->enemy[i].sprite.drawEndY >= HEIGHT)
		data->enemy[i].sprite.drawEndY = HEIGHT - 1;
	return (vMoveScreen);
}

/*
** Calculates and defines the width of the sprite.
*/
void	enemy_sprite_casting_width(t_data *data, int i)
{
	data->enemy[i].sprite.width = abs((int)(HEIGHT
				/ (data->enemy[i].sprite.transformY)))
		/ data->enemy[i].sprite.uDiv;
	data->enemy[i].sprite.drawStartX = -data->enemy[i].sprite.width
		/ 2 + data->enemy[i].sprite.ScreenX;
	if (data->enemy[i].sprite.drawStartX < 0)
		data->enemy[i].sprite.drawStartX = 0;
	data->enemy[i].sprite.drawEndX = data->enemy[i].sprite.width
		/ 2 + data->enemy[i].sprite.ScreenX;
	if (data->enemy[i].sprite.drawEndX >= WIDTH)
		data->enemy[i].sprite.drawEndX = WIDTH - 1;
	data->enemy[i].sprite.stripe = data->enemy[i].sprite.drawStartX;
}
