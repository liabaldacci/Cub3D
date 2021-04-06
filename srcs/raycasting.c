/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:51:29 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/05 22:22:47 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_cast_ray(t_vars *strct, double ray_angle) {
    double  ray_x;
    double  ray_y;
    double  test;
    // printf("ray angle 2: %f\n", ray_angle);
    // printf("cosine angle: %f\n", cos(ray_angle));
    // printf("scaled_x: %f\n", strct->player.scaled_x);
    // printf("sine angle: %f\n", sin(ray_angle));
    // printf("scaled_y: %f\n", strct->player.scaled_y);
    ray_x = (strct->player.scaled_x + cos(ray_angle) * 50 * strct->minimap_scale);
    ray_y = (strct->player.scaled_y + sin(ray_angle) * 50 * strct->minimap_scale);
    // test = strct->window_width - strct->tile_X;
    // if (ray_x >= test)
    //     ray_x = strct->window_width - strct->tile_X - 1;
    // if (ray_x <= strct->tile_X)
    //     ray_x = strct->tile_X + 1;
    // if (ray_y >= strct->window_height - strct->tile_Y)
    //     ray_y = strct->window_height - strct->tile_Y - 1;
    // if (ray_y <= strct->tile_Y)
    //     ray_y = strct->tile_Y + 1;
    // printf("rotation angle in cast_ray: %f\n\n", strct->player.rotation_angle);
    ft_draw_line(strct, strct->player.scaled_x + (strct->player.scaled_width / 2),
        strct->player.scaled_y + (strct->player.scaled_height / 2),
        (strct->player.scaled_x + cos(strct->player.rotation_angle) * 50 * strct->minimap_scale),
        (strct->player.scaled_y + sin(strct->player.rotation_angle) * 50 * strct->minimap_scale));
    ft_draw_line(strct, strct->player.scaled_x + (strct->player.scaled_width / 2),
        strct->player.scaled_y + (strct->player.scaled_height / 2),
        ray_x,
        ray_y);
}

void cast_all_rays(t_vars *strct) {
    double  ray_angle;
    int     i;

    i = 0;
    strct->player.rotation_angle = ft_normalize_angle(strct->player.rotation_angle);
    // strct->player.rotation_angle = 5.270894;
    ray_angle = strct->player.rotation_angle - (strct->player.fov_angle / 2);
    ray_angle = ft_normalize_angle(ray_angle);
    // ray_angle = 2.024582;
    while (i < strct->rays.num_of){
        // printf("supposed ray angle: %f\n", ft_normalize_angle(strct->player.rotation_angle - (strct->player.fov_angle / 2)));
        // printf("ray angle 1: %f\n", ray_angle);
        ft_cast_ray(strct, ray_angle);
        ray_angle += strct->player.fov_angle / strct->rays.num_of;
        i++;
    }
}