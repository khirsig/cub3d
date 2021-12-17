/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:22:52 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 09:27:18 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	keyhook_handler(t_data *data)
{
	mlx_key_hook(data->vars.mlx_win, &destroy, &data);
	mlx_hook(data->vars.mlx_win, 17, 0L, &close_button, &data);
	mlx_hook(data->vars.mlx_win, 2, (1L << 0), &player_press, &data);
	mlx_hook(data->vars.mlx_win, 3, (1L << 1), &player_release, &data);
	return (0);
}