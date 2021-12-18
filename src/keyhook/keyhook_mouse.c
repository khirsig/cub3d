/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:35:22 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 09:03:15 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 && data->mouse_variant == 2)
	{
		data->mouse_rotation = 1;
		data->player.rotation_direction = LEFT;
	}
	if (button == 1 && data->mouse_variant == 1)
	{
		data->mouse_rotation = 1;
		data->player.rotation_direction = RIGHT;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 && (data->mouse_variant == 2 || data->mouse_variant == 1))
		data->mouse_rotation = 0;
	return (0);
}