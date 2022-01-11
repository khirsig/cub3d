/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_weapon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:34:44 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 13:44:20 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include "px.h"

/*
** Returns the color of the current pixel of the texture.
*/
static int	draw_weapon_get_px(t_data *data, int ys, int xs)
{
	int	color;

	color = data->player.weapon.texture[data->player.weapon.width * ys + xs];
	return (color);
}

/*
** Draws the weapon texture upscaled x4 to be bigger on the screen.
*/
void	draw_weapon(t_data *data)
{
	int	color;
	int	y;
	int	y_scaling;
	int	x;
	int	x_scaling;

	y = 684;
	y_scaling = 0;
	while (y_scaling < data->player.weapon.height)
	{
		x = 860;
		x_scaling = 0;
		while (x_scaling < data->player.weapon.width)
		{
			color = draw_weapon_get_px(data, y_scaling, x_scaling);
			if (color != 0xFFFFFF)
				my_mlx_pixel_put(&data->vars, x, y, color);
			x++;
			if (x % 4 == 0)
				x_scaling++;
		}
		y++;
		if (y % 4 == 0)
			y_scaling++;
	}
}
