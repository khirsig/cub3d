/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_display_vitals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:49:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 14:01:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Draws the health and stamina bar at the top left of the screen.
*/
void	display_vitals(t_data *data)
{
	int	hp;
	int	stam;
	int	x;
	int	y;

	hp = data->player.health * 2;
	stam = data->player.stamina * 2;
	y = 930;
	while (y < 975)
	{
		x = 30;
		while (x < 230)
		{
			if (x < hp + 30 && y < 950)
				my_mlx_pixel_put(&data->vars, x, y, 0x00FE0000);
			else if (y < 950)
				my_mlx_pixel_put(&data->vars, x, y, 0x00505050);
			if (x < stam + 30 && y >= 955)
				my_mlx_pixel_put(&data->vars, x, y, 0x00009B0E);
			else if (y >= 955)
				my_mlx_pixel_put(&data->vars, x, y, 0x00505050);
			x++;
		}
		y++;
	}
}
