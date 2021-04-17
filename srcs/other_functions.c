/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:43:11 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 14:59:14 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double      ft_normalize_angle(double angle){
    double  remainder;

    if (angle > TWO_PI || angle < 0){
        remainder = fmod(angle, TWO_PI);
        angle = (angle < 0) ? (TWO_PI + remainder) : remainder;
    }
    return (angle);    
}

double      ft_distance_between_points(double x1, double y1, double x2, double y2)
{
    double  distance;

    distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return (distance);    
}

void        ft_errors(t_vars *strct, int i)
{
    if (i == 1)
        ft_putendl_fd("Error: Invalid map file.", 1);
    else if (i == 2)
        ft_putendl_fd("Error: Not enough arguments. USE: ./cub3d [mapfile.cub]", 1);
    else if (i == 3)
        ft_putendl_fd("Error: Invalid flag as argument.\nUse: --save", 1);
    else if (i == 4)
		ft_putendl_fd("Error: Invalid number of arguments.", 1);
	else if (i == 5)
		ft_putendl_fd("Error: Invalid resolution.", 1);
	else if (i == 6)
		ft_putendl_fd("Error: Invalid ceilling or floor colors.", 1);
	else if (i == 7)
        ft_putendl_fd("Error: Invalid path to texture!", 1);
	else if (i == 8)
        ft_putendl_fd("Error: Map is not valid.", 1);
	else if (i == 9)
        ft_putendl_fd("Error: There is no player position.", 1);
	else if (i == 10)
        ft_putendl_fd("Error: The player position is not valid.", 1);
    close_program(strct);
}