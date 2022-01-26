/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:05 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/26 10:49:34 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** This checks for the maximum length in both x and y for the map.
** If any length is <= 0 it exits the program cleanly.
*/
static void	parser_map_set_length(t_data *data, char *file)
{
	data->y_length = parser_map_y_length(data, file);
	if (data->y_length <= 0)
	{
		ft_putstr_error("Error\n");
		exit(EXIT_FAILURE);
	}
	data->x_length = parser_map_x_length(data, file);
	if (data->x_length <= 0)
	{
		ft_putstr_error("Error\n");
		exit(EXIT_FAILURE);
	}
}

/*
** Skips every newline until the map starts.
** Then saves every line and returns them as **char.
*/
static char	**parser_map_read_temp(t_data *data)
{
	char	**temp;
	char	*str;
	int		index;

	temp = malloc(sizeof(char *) * data->y_length + 1);
	temp[data->y_length] = NULL;
	str = get_next_line(data->file);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(data->file);
	}
	temp[0] = ft_strdup(str);
	index = 1;
	while (index < data->y_length)
	{
		temp[index] = get_next_line(data->file);
		if (temp[index][0] == '\n')
		{
			ft_putstr_error("Error\n");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	return (temp);
}

/*
** Main parser function that checks and sets up everything in order.
*/
void	parser_map(t_data *data, char *file)
{
	char	**temp;

	parser_map_set_length(data, file);
	temp = parser_map_read_temp(data);
	if (parser_map_finalize_map(data, temp) == 1)
	{
		ft_putstr_error("Error\n");
		exit(EXIT_FAILURE);
	}
	free(temp);
	if (parser_map_error(data, data->maze.map) == 1)
		exit(EXIT_FAILURE);
}
