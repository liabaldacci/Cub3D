/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:30 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/15 11:50:36 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color)
{
    int largest;
    int y_step;
    int x_step;
    int i;
    
    x_step = ((x2 - x1) <= (y2 - y1)) ? 0 : 1;
    y_step = ((x2 - x1) < (y2 - y1)) ? 1 : 0;
    largest = ((x2 - x1) <= (y2 - y1)) ? y2 : x2;
    i = ((x2 - x1) <= (y2 - y1)) ? y1 : x1;
    
    while (i < largest)
    {
        ft_mlx_pixel_put(strct, x1, y1, color);
        y1 += y_step;
        x1 += x_step;
        i++;
    }
}
