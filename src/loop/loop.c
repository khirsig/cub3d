/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:23:33 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 13:24:50 by khirsig          ###   ########.fr       */
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
	enemy_anim_cycle(data);
	enemy_actions(data);
	enemy_sprite_casting(data);
	display_vitals(data);
	draw_weapon(data);
	draw_mouse(data);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win,
		data->vars.mlx_img, 0, 0);
	return (0);
}
