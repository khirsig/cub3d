/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:05 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 13:20:17 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	parser_map_set_length(t_data *data, char *file)
{
	data->y_length = parser_map_y_length(data, file);
	if (data->y_length <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	data->x_length = parser_map_x_length(data, file);
	if (data->x_length <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

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
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		index++;
	}
	return (temp);
}

void	parser_map(t_data *data, char *file)
{
	char	**temp;

	parser_map_set_length(data, file);
	temp = parser_map_read_temp(data);
	if (parser_map_finalize_map(data, temp) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	free(temp);
	parser_map_error(data, data->maze.map);
}
