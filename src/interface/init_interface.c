/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:53:58 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 23:51:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_interface(t_data *data)
{
	data->player.weapon.y = 799;
	data->player.weapon.x = 799;
	data->player.weapon.height = 79;
	data->player.weapon.width = 35;
	data->player.weapon.texture = load_texture(data, "./resources/interface/sword.xpm");
	data->mouse_height = 12;
	data->mouse_width = 12;
	data->mouse_texture = load_texture(data, "./resources/interface/arrow_target.xpm");
	// mlx_mouse_move(data->vars.mlx_win, 500, 500);
}