/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:07:41 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/10 13:21:46 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	print_error(void)
{
	// free struct
	printf("Error\ninvalid map\n");
	exit (0);
}

void	check_color_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != ' ')
			print_error();
		i++;
	}
	i = 0;
	count = 1;
	while (count <= 5)
	{
		while (str[i] == ' ')
			i++;
		if (count % 2 == 0 && str[i] != ',')
			print_error();
		if (count % 2 == 1 && (str[i] < '0' || str[i] > '9'))
			print_error();
		if (str[i] == ',')
			i++;
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		count++;
	}
}


void	parse_texture(char *str, int i, t_data *data)
{
	if (str[i] == 'N' && str[i + 1] == 'O')
		data->maze.north_texture = &str[i + 2];
	else if (str[i] == 'S' && str[i + 1] == 'O')
		data->maze.south_texture = &str[i + 2];
	else if (str[i] == 'W' && str[i + 1] == 'E')
		data->maze.west_texture = &str[i + 2];
	else if (str[i] == 'E' && str[i + 1] == 'A')
		data->maze.east_texture = &str[i + 2];
	else
		print_error();
}

void	parse_color(char *str, int i, t_data *data)
{
	char	c;

	c = str[i];
	if (str[i + 1] != ' ')
		print_error();
	check_color_str(&str[i + 1]);
	if (str[i] == 'F')
	{
		data->maze.floor.r = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.floor.b = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.floor.g = ft_atoi(&str[i + 1]);
	}
	else
	{
		data->maze.ceiling.r = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.ceiling.b = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.ceiling.g = ft_atoi(&str[i + 1]);
	}
}

int	check_next_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'N' || str[i] == 'S' ||  str[i] == 'W' || str[i] == 'E')
	{
		parse_texture(str, i, data);
		return (1);
	}
	else if (str[i] == 'F' || str[i] == 'C')
	{
		parse_color(str, i, data);
		return (2);
	}
	else if (str[i] == '\n')
		return (3);
	return (0);
}


int	parse_part_1(int fd, t_data *data)
{
	int		lines;
	int		count;
	int		i;
	char	*str;
	
	if (fd == -1)
		return (-1);
	lines = 0;
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL || count == 6)
		{
			if (count < 6)
				print_error();
			break ;
		}
		i = check_next_line(str, data);
		if (i == 0)
			print_error();
		else if (i == 1 || i == 2)
			count++;
		lines++;
	}
	// check that everything is filled and nothing is filled twice
	return (lines);
}