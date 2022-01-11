/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:22:52 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 12:31:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Organized function for all the keyhooks.
** Handles all possible user input through mouse and keyboard.
*/
int	keyhook_handler(t_data *data)
{
	mlx_hook(data->vars.mlx_win, 4, (1L << 2), &mouse_press, data);
	mlx_hook(data->vars.mlx_win, 5, (1L << 3), &mouse_release, data);
	mlx_hook(data->vars.mlx_win, 17, 0L, &close_button, data);
	mlx_hook(data->vars.mlx_win, 2, (1L << 0), &key_press, data);
	mlx_hook(data->vars.mlx_win, 3, (1L << 1), &key_release, data);
	return (0);
}
