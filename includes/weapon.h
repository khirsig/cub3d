/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 23:02:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

typedef struct s_weapon {
		int 	*texture;
		double	x;
		double	y;
		int		height;
		int		width;
}				t_weapon;

#endif