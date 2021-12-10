/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/10 18:00:00 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Checks input for the floor and ceiling (helper function).
*/

void	check_color_str_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != ' ')
			ft_putstr_fd("Error\n", 2);
		i++;
	}	
}

/*
Checks input for the floor and ceiling.
*/

void	check_color_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	check_color_str_char(str);
	if (str[i] != ' ')
		ft_putstr_fd("Error\n", 2);
	while (count <= 5)
	{
		while (str[i] == ' ')
			i++;
		if (count % 2 == 0 && str[i] != ',')
			ft_putstr_fd("Error\n", 2);
		if (count % 2 == 1 && (str[i] < '0' || str[i] > '9'))
			ft_putstr_fd("Error\n", 2);
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

/*
Parses color information for the floor and ceiling.
*/

void	parse_color(char *str, int i, t_data *data)
{
	check_color_str(&str[i + 1]);
	if (str[i] == 'F')
	{
		data->maze.floor.r = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.floor.g = ft_atoi(&str[i + 1]);
		i++;
		while (str[i] != ',')
			i++;
		data->maze.floor.b = ft_atoi(&str[i + 1]);
		data->maze.floor.check = 1;
	}
	else
	{
		data->maze.ceiling.r = ft_atoi(&str[i + 1]);
		while (str[i] != ',')
			i++;
		data->maze.ceiling.g = ft_atoi(&str[i + 1]);
		i++;
		while (str[i] != ',')
			i++;
		data->maze.ceiling.b = ft_atoi(&str[i + 1]);
		data->maze.ceiling.check = 1;
	}
}
