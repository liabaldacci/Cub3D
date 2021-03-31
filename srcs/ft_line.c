/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:30 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/30 21:28:06 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color){
    int first_x;
    int first_y;
    int last_x;
    int last_y;
    int temp;

    first_x = (x1 > x2) ? x2 : x1;
    last_x = (x1 > x2) ? x1 : x2;
    first_y = (y1 > y2) ? y2 : y1;
    last_y = (y1 > y2) ? y1 : y2;
    temp = first_y;

    while (first_x <= last_x){
        while (first_y <= last_y){
            ft_mlx_pixel_put(strct, first_x, first_y, color);
            first_y++;
        }
        first_x++;
        first_y = temp;
    }
}