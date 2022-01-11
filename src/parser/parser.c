/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:29:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 13:59:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Organizes all the parsing functions.
*/
void	parser(t_data *data, char *file)
{
	ft_bzero(data, sizeof(t_data));
	data->file = open(file, O_RDONLY);
	if (data->file == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	parser_color_wall(data);
	parser_map(data, file);
}
