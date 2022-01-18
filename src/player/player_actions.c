/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:07:40 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/18 11:08:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	player_actions_door(t_data *data)
{
	if (data->maze.map
		[(int)(data->player.y_pos + data->player.dirY)]
		[(int)(data->player.x_pos + data->player.dirX)] == '2')
		data->maze.map
		[(int)(data->player.y_pos + data->player.dirY)]
		[(int)(data->player.x_pos + data->player.dirX)] = '3';
	else if (data->maze.map
		[(int)(data->player.y_pos + data->player.dirY)]
		[(int)(data->player.x_pos + data->player.dirX)] == '3')
		data->maze.map
		[(int)(data->player.y_pos + data->player.dirY)]
		[(int)(data->player.x_pos + data->player.dirX)] = '2';
}
