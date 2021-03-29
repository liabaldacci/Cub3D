/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:34 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 18:54:14 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void ft_init_struct(t_vars *strct)
{
    strct->window_title = "Hello world!";
    strct->player.playerY = 0;
    strct->player.playerX = 0;
    strct->map_height = 0;
    strct->map_width = 0;
    strct->left = 0;
    strct->right = 0;
    strct->up = 0;
    strct->down = 0;
    strct->fov_angle = (60 * PI)/180;
    strct->player.player_width = 5;
    strct->player.player_height = 5;
    strct->player.turn_direction = 0; //-1 for left and +1 for right
    strct->player.walk_direction = 0; //-1 for going backwards and +1 for going forward
    strct->player.walk_speed = 50;
    strct->player.turn_speed = 45 * (PI / 180);
    
}

int    ft_init_window(t_vars *strct) {
    //creates a window with the height and width specified in ft_init_win
    strct->mlx_win = mlx_new_window(strct->mlx, strct->window_width,
        strct->window_height, strct->window_title);
    //function returns an error if the window is not created properly.
    if (!strct->mlx_win){
        printf("Error initializing strct.");
        return (-1);
    }
    //creates an image that will be pushed to the screen. This takes up less computing space and resources.
    strct->img = mlx_new_image(strct->mlx, strct->window_height,
            strct->window_width);
    //not sure what this does. Probably gets information from something called addr inside the struct that
    //contains the info necessary to use graphics.
    strct->addr = mlx_get_data_addr(strct->img, &strct->bits_per_pixel,
            &strct->line_length, &strct->endian);
    return (0);
}

