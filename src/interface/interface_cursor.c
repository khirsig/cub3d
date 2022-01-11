/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:53:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 14:18:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include "px.h"

void	draw_mouse_variant_choose(t_data *data)
{
	if (data->mouse_x > 800)
	{
		data->mouse_variant = 2;
		data->mouse_height = 9;
		data->mouse_width = 13;
	}
	else if (data->mouse_x < 200)
	{
		data->mouse_variant = 1;
		data->mouse_height = 9;
		data->mouse_width = 13;
	}
	else if (data->mouse_x >= 200 && data->mouse_x <= 800)
	{
		data->mouse_variant = 0;
		data->mouse_height = 12;
		data->mouse_width = 12;
		data->mouse_rotation = 0;
	}
}

static void	draw_mouse_variant(t_data *data)
{
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
	draw_mouse_variant_choose(data);
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
}

void	draw_mouse(t_data *data)
{
	t_px	px;

	mlx_mouse_hide();
	draw_mouse_variant(data);
	px.y = data->mouse_y - data->mouse_height / 2 * 3;
	px.y_scaling = 0;
	while (px.y_scaling < data->mouse_height)
	{
		px.x = data->mouse_x - data->mouse_width / 2 * 3;
		px.x_scaling = 0;
		while (px.x_scaling < data->mouse_width)
		{
			px.color = data->mouse_texture[data->mouse_variant]
			[data->mouse_width * px.y_scaling + px.x_scaling];
			if (px.color != 0xFFFFFF)
				my_mlx_pixel_put(&data->vars, px.x, px.y, px.color);
			px.x++;
			if (px.x % 3 == 0)
				px.x_scaling++;
		}
		px.y++;
		if (px.y % 3 == 0)
			px.y_scaling++;
	}
}
