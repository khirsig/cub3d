/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:53:20 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 23:50:38 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_weapon(t_data *data)
{
	int color;
	int y;
	int yi;
	int x;
	int xi;

	y = 684;
	yi = 0;
	while (yi < data->player.weapon.height)
	{
		x = 860;
		xi = 0;
		while (xi < data->player.weapon.width)
		{
			color = data->player.weapon.texture[data->player.weapon.width * yi + xi];
			if (color != 0xFFFFFF)
				my_mlx_pixel_put(&data->vars, x, y, color);
			// printf("%i\n", xi);
			x++;
			if (x % 4 == 0)
				xi++;
		}
		y++;
		if (y % 4 == 0)
			yi++;
	}
}

void	draw_mouse(t_data *data)
{
	int y;
	int yi;
	int xi;
	int x;
	int color;

	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	y = data->mouse_y - 18;
	yi = 0;
	while (yi < data->mouse_height)
	{
		x = data->mouse_x - 18;
		xi = 0;
		while (xi < data->mouse_width)
		{
			color = data->mouse_texture[data->mouse_width * yi + xi];
			if (color != 0xFFFFFF)
				my_mlx_pixel_put(&data->vars, x, y, color);
			// printf("%i\n", xi);
			x++;
			if (x % 3 == 0)
				xi++;
		}
		y++;
		if (y % 3 == 0)
			yi++;
	}
}
