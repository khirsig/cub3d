/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:23:33 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 16:11:30 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	gameloop(t_data *data)
{
	mlx_clear_window(data->vars.mlx, data->vars.mlx_win);
	player_movement(data);
	player_rotation(data);
	calculate_dist(data);
	minimap(data);
	mlx_put_image_to_window(data->vars.mlx, data->vars.mlx_win, data->vars.mlx_img, 0, 0);
	return (0);
}