/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:34:31 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Iterates through the map and returns the count of enemies.
*/
int	count_enemies(t_data *data)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (data->maze.map[y] != NULL)
	{
		x = 0;
		while (data->maze.map[y][x] != '\0')
		{
			if (data->maze.map[y][x] == 'R' || data->maze.map[y][x] == 'G')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/*
** Iterates through the map and finds each enemy and their type.
** Initializes each enemy depending on their type. (Rat or Goblin)
*/
void	enemy_setup(t_data *data)
{
	int	x;
	int	y;
	int	num_enemy;

	y = 0;
	num_enemy = 0;
	while (data->maze.map[y] != NULL)
	{
		x = 0;
		while (data->maze.map[y][x] != '\0')
		{
			if (data->maze.map[y][x] == 'R')
			{
				setup_rat(data, &data->enemy[num_enemy], x, y);
				num_enemy++;
			}
			if (data->maze.map[y][x] == 'G')
			{
				setup_goblin(data, &data->enemy[num_enemy], x, y);
				num_enemy++;
			}
			x++;
		}
		y++;
	}
}

/*
** Initializes each enemy depending on how many there are.
** Allocates place for the enemy data structures.
*/
void	init_enemy(t_data *data)
{
	data->num_enemies = count_enemies(data);
	data->enemy = malloc(sizeof(t_enemy) * data->num_enemies);
	data->mouse_on_enemy = malloc(sizeof(int *) * data->num_enemies);
	enemy_setup(data);
}
