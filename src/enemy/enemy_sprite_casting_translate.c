/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite_casting_translate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:53:45 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 22:00:00 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Translates and transforms the current player view to start the calculations.
*/
void	enemy_sprite_casting_cam_transform(t_data *data, int i)
{
	data->enemy[i].sprite.sprite_x
		= data->enemy[i].sprite.x - data->player.x_pos;
	data->enemy[i].sprite.sprite_y
		= data->enemy[i].sprite.y - data->player.y_pos;
	data->enemy[i].sprite.inv_det = 1.0 / (data->player.plane_x
			* data->player.dir_y - data->player.dir_x * data->player.plane_y);
	data->enemy[i].sprite.transform_x = data->enemy[i].sprite.inv_det
		* (data->player.dir_y * data->enemy[i].sprite.sprite_x
			- data->player.dir_x * data->enemy[i].sprite.sprite_y);
	data->enemy[i].sprite.transform_y = data->enemy[i].sprite.inv_det
		* (-data->player.plane_y * data->enemy[i].sprite.sprite_x
			+ data->player.plane_x * data->enemy[i].sprite.sprite_y);
	data->enemy[i].sprite.screen_x = (int)((WIDTH / 2)
			* (1 + data->enemy[i].sprite.transform_x
				/ data->enemy[i].sprite.transform_y));
}

/*
** Calculates and defines the height of the sprite.
*/
int	enemy_sprite_casting_height(t_data *data, int i)
{
	int	v_move_screen;

	v_move_screen = (int)(data->enemy[i].sprite.v_move
			/ data->enemy[i].sprite.transform_y);
	data->enemy[i].sprite.height = abs((int)(HEIGHT
				/ (data->enemy[i].sprite.transform_y)))
		/ data->enemy[i].sprite.v_div;
	data->enemy[i].sprite.draw_start_y = -data->enemy[i].sprite.height
		/ 2 + HEIGHT / 2 + v_move_screen;
	if (data->enemy[i].sprite.draw_start_y < 0)
		data->enemy[i].sprite.draw_start_y = 0;
	data->enemy[i].sprite.draw_end_y = data->enemy[i].sprite.height
		/ 2 + HEIGHT / 2 + v_move_screen;
	if (data->enemy[i].sprite.draw_end_y >= HEIGHT)
		data->enemy[i].sprite.draw_end_y = HEIGHT - 1;
	return (v_move_screen);
}

/*
** Calculates and defines the width of the sprite.
*/
void	enemy_sprite_casting_width(t_data *data, int i)
{
	data->enemy[i].sprite.width = abs((int)(HEIGHT
				/ (data->enemy[i].sprite.transform_y)))
		/ data->enemy[i].sprite.u_div;
	data->enemy[i].sprite.draw_start_x = -data->enemy[i].sprite.width
		/ 2 + data->enemy[i].sprite.screen_x;
	if (data->enemy[i].sprite.draw_start_x < 0)
		data->enemy[i].sprite.draw_start_x = 0;
	data->enemy[i].sprite.draw_end_x = data->enemy[i].sprite.width
		/ 2 + data->enemy[i].sprite.screen_x;
	if (data->enemy[i].sprite.draw_end_x >= WIDTH)
		data->enemy[i].sprite.draw_end_x = WIDTH - 1;
	data->enemy[i].sprite.stripe = data->enemy[i].sprite.draw_start_x;
}
