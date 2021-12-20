/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:05 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 11:43:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0' || c == 'R' || c == 'G'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

static int	finalize_map(t_data *data, char **temp)
{
	int	x_index;
	int	y_index;
	int	strlen;

	data->maze.map = malloc(sizeof(char *) * data->y_length + 1);
	data->maze.map[data->y_length] = NULL;
	y_index = 0;
	while (y_index < data->y_length)
	{
		x_index = 0;
		strlen = ft_strlen(temp[y_index]);
		data->maze.map[y_index] = malloc(sizeof(char) * data->x_length + 1);
		data->maze.map[y_index][data->x_length] = '\0';
		while (x_index < strlen)
		{
			if (temp[y_index][x_index] == '\n')
			{
				break ;
			}
			if (check_char(temp[y_index][x_index]) == 0)
				return (0);
			data->maze.map[y_index][x_index] = temp[y_index][x_index];
			x_index++;
		}
		while (x_index < data->x_length)
		{
			data->maze.map[y_index][x_index] = ' ';
			x_index++;
		}
		y_index++;
	}
	return (1);
}

void	parser_map(t_data *data, char *file)
{
	char	**temp;
	char	*str;
	int		index;

	data->y_length = parser_map_y_length(data, file);
	if (data->y_length <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	data->x_length = parser_map_x_length(data, file);
	if (data->x_length <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
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
			return (0);
		}
		index++;
	}
	if (finalize_map(data, temp) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	// free(temp);
	parser_map_error(data, data->maze.map);
	return (1);
}
