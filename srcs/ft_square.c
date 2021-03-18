/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:59:03 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/17 21:46:00 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_square(t_vars *strct, int x, int y, int height, int width, unsigned int color)
{
    int x_temp;

    x_temp = x;
    while (y <= height)
    {
        while (x <= width)
        {
            ft_mlx_pixel_put(strct, x, y, color);
            x++;
        }
        x = x_temp;
        y++;
    }
}