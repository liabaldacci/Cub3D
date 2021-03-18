/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:34 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/17 21:41:32 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void ft_init_struct(t_vars *strct)
{
    strct->window_width = 600;
    strct->window_height = 800;
    strct->window_title = "Hello world!";
    // strct->grid = [
    //         [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    //         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
    //         [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
    //         [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
    //         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
    //         [1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1],
    //         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    //         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    //         [1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
    //         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    //         [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]];
}

int    ft_init_window(t_vars *strct) {
    //initializes struct containing information regarding mlx and the window size
    ft_init_struct(strct);
    //creates a window with the height and width specified in ft_init_win
    strct->mlx = mlx_init();
    strct->mlx_win = mlx_new_window(strct->mlx, strct->window_height,
        strct->window_width, strct->window_title);
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

