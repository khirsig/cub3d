/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:29:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/26 10:51:25 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Error function
*/
void	ft_putstr_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

/*
** Organizes all the parsing functions.
*/
void	parser(t_data *data, char *file)
{
	ft_bzero(data, sizeof(t_data));
	data->file = open(file, O_RDONLY);
	if (data->file == -1)
	{
		ft_putstr_error("Error: Map not found.\n");
		exit(EXIT_FAILURE);
	}
	parser_color_wall(data);
	parser_map(data, file);
}
