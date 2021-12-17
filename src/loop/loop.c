/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:23:33 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 20:20:35 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	gameloop(t_data *data)
{
	mlx_clear_window(data->vars.mlx, data->vars.mlx_win);
	player_movement(data);
	player_rotation(data);
	draw_view(data);
	minimap(data);
	modify_stamina(data);
	cycle_animstep(data);
	enemy_movement(data);
	sprite_casting(data);
	display_vitals(data);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, data->vars.mlx_img, 0, 0);
	return (0);
}