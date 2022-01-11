/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_modify_vitals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:15:21 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 14:01:23 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Checks if the player is sprinting.
** If is_sprinting is 1 and stamina > 0.99, the stamina gets drained.
** If the player runs out of stamina he stops sprinting.
*/
int	modify_stamina(t_data *data)
{
	if (data->player.is_sprinting == 0 && data->player.stamina < 100.000000)
		data->player.stamina += 0.20;
	if (data->player.stamina > 100.000000)
		data->player.stamina = 100.000000;
	if (data->player.is_sprinting == 1 && data->player.stamina > 0.99)
		data->player.stamina--;
	if (data->player.is_sprinting == 1 && data->player.stamina <= 0.99)
	{
		data->player.is_sprinting = 0;
		data->player.speed = 0.03;
	}
	return (0);
}
