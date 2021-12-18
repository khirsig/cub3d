/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:53:20 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 09:02:05 by khirsig          ###   ########.fr       */
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

void	choose_mouse_variant(t_data *data, int mouse_x)
{
	if (mouse_x > 800)
	{
		data->mouse_variant = 2;
		data->mouse_height = 9;
		data->mouse_width = 13;
	}
	else if (mouse_x < 200)
	{
		data->mouse_variant = 1;
		data->mouse_height = 9;
		data->mouse_width = 13;
	}
	else if (mouse_x >= 200 && mouse_x <= 800)
	{
		data->mouse_variant = 0;
		data->mouse_height = 12;
		data->mouse_width = 12;
		data->mouse_rotation = 0;
	}

}

void	draw_mouse(t_data *data)
{
	int y;
	int yi;
	int xi;
	int x;
	int color;

	mlx_mouse_hide();
	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x > 982)
		mlx_mouse_move(data->vars.mlx_win, 982, data->mouse_y);
	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_y > 982)
		mlx_mouse_move(data->vars.mlx_win, data->mouse_x, 982);
	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x < 18)
		mlx_mouse_move(data->vars.mlx_win, 18, data->mouse_y);
	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_y < 18)
		mlx_mouse_move(data->vars.mlx_win, data->mouse_x, 18);
	mlx_mouse_get_pos(data->vars.mlx_win, &data->mouse_x, &data->mouse_y);
	choose_mouse_variant(data, data->mouse_x);
	if (data->mouse_variant == 1 || data->mouse_variant == 2)
	{
		data->mouse_height = 9;
		data->mouse_width = 13;
	}
	else
	{
		data->mouse_height = 12;
		data->mouse_width = 12;
	}
	y = data->mouse_y - data->mouse_height / 2 * 3;
	yi = 0;
	while (yi < data->mouse_height)
	{
		x = data->mouse_x - data->mouse_width / 2 * 3;
		xi = 0;
		while (xi < data->mouse_width)
		{
			color = data->mouse_texture[data->mouse_variant][data->mouse_width * yi + xi];
			if (color != 0xFFFFFF)
				my_mlx_pixel_put(&data->vars, x, y, color);
			x++;
			if (x % 3 == 0)
				xi++;
		}
		y++;
		if (y % 3 == 0)
			yi++;
	}
}
