/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:58:03 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 12:32:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Exits the program cleanly after the red X is pressed.
*/
int	close_button(t_data *data)
{
	(void)data;
	ft_putstr_fd("exit\n", 1);
	exit(0);
}
