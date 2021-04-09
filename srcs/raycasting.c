/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:51:29 by gadoglio          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/04/08 22:41:37 by gadoglio         ###   ########.fr       */
=======
/*   Updated: 2021/04/08 22:23:01 by gadoglio         ###   ########.fr       */
>>>>>>> 753f34676f755732054298b5a5dc5bef483a63cf
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void        ft_render_3d_rays(t_vars *strct)
{
    double  wall_strip_height;
    double  distance_proj_plane;
    int     wall_top_pixel;
    int     wall_bottom_pixel;
    
    //calculate the distance to the projection plane
    distance_proj_plane = (strct->window_width / 2)
        / tan(strct->player.fov_angle / 2);
    //projected wall height
    wall_strip_height = (strct->tile_Y / strct->rays.distance)
        * distance_proj_plane;
    wall_top_pixel = (strct->window_height / 2) - (wall_strip_height / 2);
    wall_top_pixel = (wall_top_pixel < 0) ? 0 : wall_top_pixel;
    wall_bottom_pixel = (strct->window_height / 2) + (wall_strip_height / 2);
    wall_bottom_pixel = (wall_bottom_pixel > strct->window_height)
        ? strct->window_height : wall_bottom_pixel;
    ft_draw_line(strct, strct->rays.column_id,
        wall_top_pixel,
        strct->rays.column_id,
        wall_bottom_pixel);
}

void        ft_horizontal_check(t_vars *strct, double ray_angle)
{
    double  xintercept;
    double  yintercept;
    double  xstep;
    double  ystep;
    double  next_horz_touch_x;
    double  next_horz_touch_y;
    int     found_horizontal_wall_hit;
    double  x_to_check;
    double  y_to_check;
    
    found_horizontal_wall_hit = 0;

    //////////////////////////////////////////////
    ////HORIZONTAL RAY-GRID INTERSECTION CHECK////
    //////////////////////////////////////////////

    //find the y-coordinate of the closes horizontal grid intersection
    yintercept = (floor(strct->player.y / strct->tile_Y)) * strct->tile_Y;
    yintercept += strct->rays.is_facing_down ? strct->tile_Y : 0;
    //find the x-coordinate of the closes horizontal grid intersection
    xintercept = strct->player.x + ((yintercept - strct->player.y) / tan(ray_angle));

    //calculate increment xstep and ystep
    ystep = strct->tile_Y;
    ystep *= strct->rays.is_facing_up ? -1 : 1;
    
    xstep = strct->tile_Y / tan(ray_angle);
    xstep *= (strct->rays.is_facing_left && xstep > 0) ? -1 : 1;
    xstep *= (strct->rays.is_facing_right && xstep < 0) ? -1 : 1;

    next_horz_touch_x = xintercept;
    next_horz_touch_y = yintercept;

    //increment xstep and ystep until we find a wall
    while (next_horz_touch_x >= 0 && next_horz_touch_x <= strct->window_width
            && next_horz_touch_y >= 0 && next_horz_touch_y <= strct->window_height)
    {
        x_to_check = next_horz_touch_x;
        y_to_check = next_horz_touch_y + (strct->rays.is_facing_up ? -1 : 0);
        if (ft_has_wall_at(strct, x_to_check, y_to_check))
        {
            //found wall hit
            found_horizontal_wall_hit = 1;
            strct->rays.horz_wall_hit_x = next_horz_touch_x;
            strct->rays.horz_wall_hit_y = next_horz_touch_y;
            break;
        }
        else
        {
            next_horz_touch_x += xstep;
            next_horz_touch_y += ystep;
        }
    }
    //calculate the horizontal distance
    strct->rays.horz_hit_distance = (found_horizontal_wall_hit)
        ? ft_distance_between_points(strct->player.x, strct->player.y,
            strct->rays.horz_wall_hit_x, strct->rays.horz_wall_hit_y) : 2147483646;
}

void        ft_vertical_check(t_vars *strct, double ray_angle)
{
    double  xintercept;
    double  yintercept;
    double  xstep;
    double  ystep;
    double  next_vert_touch_x;
    double  next_vert_touch_y;
    int     found_vertical_wall_hit;
    double  x_to_check;
    double  y_to_check;
    
    //////////////////////////////////////////////
    /////VERTICAL RAY-GRID INTERSECTION CHECK/////
    //////////////////////////////////////////////
    
    found_vertical_wall_hit = 0;
    //find the x-coordinate of the closes vertical grid intersection
    xintercept = (floor(strct->player.x / strct->tile_X)) * strct->tile_X;
    xintercept += strct->rays.is_facing_right ? strct->tile_X : 0;
    //find the y-coordinate of the closes vertical grid intersection
    yintercept = strct->player.y + ((xintercept - strct->player.x) * tan(ray_angle));

    //calculate increment xstep and ystep
    xstep = strct->tile_X;
    xstep *= strct->rays.is_facing_left ? -1 : 1;
    
    ystep = strct->tile_X * tan(ray_angle);
    ystep *= (strct->rays.is_facing_up && ystep > 0) ? -1 : 1;
    ystep *= (strct->rays.is_facing_down && ystep < 0) ? -1 : 1;

    next_vert_touch_x = xintercept;
    next_vert_touch_y = yintercept;

    //increment xstep and ystep until we find a wall
    while (next_vert_touch_x >= 0 && next_vert_touch_x <= strct->window_width
            && next_vert_touch_y >= 0 && next_vert_touch_y <= strct->window_height)
    {
        x_to_check = next_vert_touch_x + (strct->rays.is_facing_left ? -1 : 0);
        y_to_check = next_vert_touch_y;
        if (ft_has_wall_at(strct, x_to_check, y_to_check))
        {
            //found wall hit
            found_vertical_wall_hit = 1;
            strct->rays.vert_wall_hit_x = next_vert_touch_x;
            strct->rays.vert_wall_hit_y = next_vert_touch_y;
            break;
        }
        else
        {
            next_vert_touch_x += xstep;
            next_vert_touch_y += ystep;
        }
    }
    //calculate the vertical distance
    strct->rays.vert_hit_distance = (found_vertical_wall_hit)
        ? ft_distance_between_points(strct->player.x, strct->player.y,
            strct->rays.vert_wall_hit_x, strct->rays.vert_wall_hit_y) : 2147483646;
}

void        ft_cast_ray(t_vars *strct, double ray_angle)
{
    ft_horizontal_check(strct, ray_angle);
    ft_vertical_check(strct, ray_angle);
    //only store the smallest of the distances
    strct->rays.wall_hit_x = (strct->rays.horz_hit_distance < strct->rays.vert_hit_distance)
        ? strct->rays.horz_wall_hit_x : strct->rays.vert_wall_hit_x;
    strct->rays.wall_hit_y = (strct->rays.horz_hit_distance < strct->rays.vert_hit_distance)
        ? strct->rays.horz_wall_hit_y : strct->rays.vert_wall_hit_y;
    strct->rays.distance = (strct->rays.horz_hit_distance < strct->rays.vert_hit_distance)
        ? strct->rays.horz_hit_distance : strct->rays.vert_hit_distance;
    strct->rays.was_hit_vertical = (strct->rays.vert_hit_distance < strct->rays.horz_hit_distance);
<<<<<<< HEAD
=======
    // printf("ray angle 2: %f\n", ray_angle);
    // printf("cosine angle: %f\n", cos(ray_angle));
    // printf("scaled_x: %f\n", strct->player.scaled_x);
    // printf("sine angle: %f\n", sin(ray_angle));
    // printf("scaled_y: %f\n", strct->player.scaled_y);
    // ray_x = (strct->player.scaled_x + cos(ray_angle) * 50 * strct->minimap_scale);
    // ray_y = (strct->player.scaled_y + sin(ray_angle) * 50 * strct->minimap_scale);
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
    // ft_draw_line(strct, strct->player.scaled_x + (strct->player.scaled_width / 2),
    //     strct->player.scaled_y + (strct->player.scaled_height / 2),
    //     (strct->player.scaled_x + cos(strct->player.rotation_angle) * 50 * strct->minimap_scale),
    //     (strct->player.scaled_y + sin(strct->player.rotation_angle) * 50 * strct->minimap_scale));
    ft_draw_line(strct, ((strct->player.x + (strct->player.width / 2)) * strct->minimap_scale),
        ((strct->player.y + (strct->player.height / 2)) * strct->minimap_scale),
        (strct->rays.wall_hit_x * strct->minimap_scale),
        (strct->rays.wall_hit_y * strct->minimap_scale));
>>>>>>> 753f34676f755732054298b5a5dc5bef483a63cf
}

void        cast_all_rays(t_vars *strct)
{
    double  ray_angle;
    strct->rays.column_id = 0;

    strct->player.rotation_angle = ft_normalize_angle(strct->player.rotation_angle);
    ray_angle = strct->player.rotation_angle - (strct->player.fov_angle / 2);
    while (strct->rays.column_id < strct->rays.num_of){
        ray_angle = ft_normalize_angle(ray_angle);
        strct->rays.is_facing_down = (ray_angle > 0 ) && (ray_angle < PI);
        strct->rays.is_facing_up = (strct->rays.is_facing_down == 0) ? 1 : 0;
        strct->rays.is_facing_right = (ray_angle < (PI / 2)) || (ray_angle > (1.5 * PI));
        strct->rays.is_facing_left = (strct->rays.is_facing_right == 0) ? 1 : 0;
        ft_cast_ray(strct, ray_angle);
        ray_angle += strct->player.fov_angle / strct->rays.num_of;
        ft_draw_line(strct, ((strct->player.x + (strct->player.width / 2)) * strct->minimap_scale),
            ((strct->player.y + (strct->player.height / 2)) * strct->minimap_scale),
            (strct->rays.wall_hit_x * strct->minimap_scale),
            (strct->rays.wall_hit_y * strct->minimap_scale));
        strct->rays.column_id++;
    }
}

void        cast_3d_rays(t_vars *strct)
{
    double  ray_angle;
    strct->rays.column_id = 0;

    strct->player.rotation_angle = ft_normalize_angle(strct->player.rotation_angle);
    ray_angle = strct->player.rotation_angle - (strct->player.fov_angle / 2);
    while (strct->rays.column_id < strct->rays.num_of){
        ray_angle = ft_normalize_angle(ray_angle);
        strct->rays.is_facing_down = (ray_angle > 0 ) && (ray_angle < PI);
        strct->rays.is_facing_up = (strct->rays.is_facing_down == 0) ? 1 : 0;
        strct->rays.is_facing_right = (ray_angle < (PI / 2)) || (ray_angle > (1.5 * PI));
        strct->rays.is_facing_left = (strct->rays.is_facing_right == 0) ? 1 : 0;
        ft_cast_ray(strct, ray_angle);
        ft_render_3d_rays(strct);
        ray_angle += strct->player.fov_angle / strct->rays.num_of;
        strct->rays.column_id++;
    }
}