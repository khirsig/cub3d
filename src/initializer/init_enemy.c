/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:13 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 12:29:22 by khirsig          ###   ########.fr       */
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
** Iterates through the map and finds each enemy.
** Initializes each enemy depending on their type. (Rat or Goblin)
*/
void	enemy_setup(t_data *data)
{
	int	x;
	int	y;
	int	numEnemy;

	y = 0;
	numEnemy = 0;
	while (data->maze.map[y] != NULL)
	{
		x = 0;
		while (data->maze.map[y][x] != '\0')
		{
			if (data->maze.map[y][x] == 'R')
			{
				setup_rat(data, &data->enemy[numEnemy], x, y);
				numEnemy++;
			}
			if (data->maze.map[y][x] == 'G')
			{
				setup_goblin(data, &data->enemy[numEnemy], x, y);
				numEnemy++;
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
	data->numEnemies = count_enemies(data);
	data->enemy = malloc(sizeof(t_enemy) * data->numEnemies);
	data->mouse_on_enemy = malloc(sizeof(int *) * data->numEnemies);
	enemy_setup(data);
}
