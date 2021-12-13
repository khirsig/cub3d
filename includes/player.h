/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 14:15:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player {
	double	x_pos;
	double	y_pos;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_player;
#endif