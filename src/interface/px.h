/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:53:36 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 13:54:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PX_H
# define PX_H

typedef struct s_px {
	int	x;
	int	y;
	int	x_scaling;
	int	y_scaling;
	int	color;
}				t_px;

#endif