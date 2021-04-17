/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:11:17 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 20:50:08 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double		ft_calc_angle(t_vars *strct, int i)
{
	double	angle;

	angle = strct->player.rotation_angle
		- atan2((strct->sprite[i].y - strct->player.y),
		(strct->sprite[i].x - strct->player.x));
	if (angle > PI)
		angle -= TWO_PI;
	if (angle < -PI)
		angle+= TWO_PI;
	angle = fabs(angle);
	return (angle);
}

void		ft_calc_distance(t_vars *strct, double angle_sprite_player, int i)
{
	if (angle_sprite_player < (strct->player.fov_angle / 2))
	{
		strct->sprite[i].is_visible = 1;
		strct->sprite[i].angle = angle_sprite_player;
		strct->sprite[i].distance =
			ft_distance_between_points(strct->sprite[i].x, strct->sprite[i].y,
			strct->player.x, strct->player.y);
	}
	else
		strct->sprite[i].is_visible = 0;
}

void		ft_render_sprites(t_vars *strct)
{
	int		i;
	double	angle_sprite_player;
	
	i = -1;
	while (i++ < strct->num_of_sprites)
	{
		angle_sprite_player = ft_calc_angle(strct, i);
		ft_calc_distance(strct, angle_sprite_player, i);
	}
	
	
}