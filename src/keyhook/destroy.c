/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:58:03 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 09:20:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	destroy(int keystroke, t_data *data)
{
	if (keystroke == 53 || keystroke == 12)
	{
		printf("exit\n");
		mlx_destroy_window(&data->vars.mlx, &data->vars.mlx_win);
		exit(0);
	}
	return (0);
}

int	close_button(t_data *data)
{
	(void)data;
	ft_putstr_fd("exit\n", 1);
	exit(0);
}
