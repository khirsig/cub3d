/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:29:58 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 11:40:24 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	parser(t_data *data, char *file)
{
	ft_bzero(data, sizeof(t_data));
	data->file = open(file, O_RDONLY);
	parser_color_wall(data);
	parser_map(data, file);
}