/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:53:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 12:26:00 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Initializes all the interface base values.
** Loads textures for cursor and weapon.
*/
void	init_interface(t_data *data)
{
	data->player.weapon.y = 799;
	data->player.weapon.x = 799;
	data->player.weapon.height = 79;
	data->player.weapon.width = 35;
	data->player.weapon.texture = load_texture(data,
			"./resources/interface/sword.xpm");
	data->mouse_height = 12;
	data->mouse_width = 12;
	data->mouse_texture = malloc(sizeof(int *) * 3);
	data->mouse_texture[0] = load_texture(data,
			"./resources/interface/arrow_target.xpm");
	data->mouse_texture[1] = load_texture(data,
			"./resources/interface/arrow_left.xpm");
	data->mouse_texture[2] = load_texture(data,
			"./resources/interface/arrow_right.xpm");
	data->mouse_variant = 0;
}
