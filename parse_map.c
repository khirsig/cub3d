/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:05 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/08 18:20:33 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	map_x_length(char *file)
{
	char	*str;
	int		highest_count;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	highest_count = 0;
	str = get_next_line(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	highest_count = ft_strlen(str) - 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		count = ft_strlen(str) - 1;
		if (highest_count < count)
			highest_count = count;
	}
	free(str);
	close(fd);
	return (highest_count);
}

static int	map_y_length(char *file)
{
	char	*str;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	str = get_next_line(fd);
	while (str != NULL && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}

static int	check_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\0'
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
		// printf("%s\n", temp[y_index]);
		strlen = ft_strlen(temp[y_index]);
		data->maze.map[y_index] = malloc(sizeof(char) * data->x_length + 2);
		data->maze.map[y_index][data->x_length + 1] = '\0';
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
		// printf("%i\n", x_index);
		printf("%i: |%s|\n", y_index, data->maze.map[y_index]);
		y_index++;
	}
	return (1);
}

int	parse_map(t_data *data, char *file)
{
	char	**temp;
	char	*str;
	int		index;

	data->y_length = map_y_length(file);
	if (data->y_length <= 0)
		return (1);
	printf("y_length = %i\n", data->y_length);
	data->x_length = map_x_length(file);
		if (data->x_length <= 0)
		return (1);
	printf("x_length = %i\n", data->x_length);
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
		index++;
	}
	index = 0;
	finalize_map(data, temp);
	index = 0;
	// while (data->maze.map[index] != NULL)
	// {
	// 	printf("|%s|\n", data->maze.map[index]);
	// 	index++;
	// }
	return (0);
}
