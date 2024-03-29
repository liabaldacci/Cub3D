/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 21:11:33 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int         ft_move(t_vars *strct)
{
    double  new_position;
    double  new_x;
    double  new_y;
    double  move_step;

    strct->player.rotation_angle += strct->player.turn_direction
		* strct->player.turn_speed;
	strct->player.rotation_angle = ft_normalize_angle(strct->player.rotation_angle);
    move_step = strct->player.walk_direction * strct->player.walk_speed;
    new_x = strct->player.x + cos(strct->player.rotation_angle) * move_step;
    new_y = strct->player.y + sin(strct->player.rotation_angle) * move_step;
    //only set new player position if it is not coliding with map wall
    if (ft_has_wall_at(strct, new_x, new_y) == 0)
    {
        strct->player.x = new_x;
        strct->player.y = new_y;
    }
    return (0);
}
    

int         ft_has_wall_at(t_vars *strct, double x, double y)
{
    int     i;
    int     j;
    int     value;

    if (x < 0 || x + strct->player.width > strct->window_width
        || y < 0 || y + strct->player.height > strct->window_height) {
            return (1);
        }
    i = floor(x / strct->tile_X);
    j = floor(y / strct->tile_Y);
    value = strct->map[j][i] != '0';
    return (value);
}