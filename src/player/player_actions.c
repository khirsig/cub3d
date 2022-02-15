/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:07:40 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:22:13 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	player_actions_door(t_data *data)
{
	if (data->maze.map
		[(int)(data->player.y_pos + data->player.dir_y)]
		[(int)(data->player.x_pos + data->player.dir_x)] == '2')
		data->maze.map
		[(int)(data->player.y_pos + data->player.dir_y)]
		[(int)(data->player.x_pos + data->player.dir_x)] = '3';
	else if (data->maze.map
		[(int)(data->player.y_pos + data->player.dir_y)]
		[(int)(data->player.x_pos + data->player.dir_x)] == '3')
		data->maze.map
		[(int)(data->player.y_pos + data->player.dir_y)]
		[(int)(data->player.x_pos + data->player.dir_x)] = '2';
}
