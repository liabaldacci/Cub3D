/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:38 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 21:13:41 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// void ft_render(t_vars *strct) {
//     //todo render map
//     //todo render rays
//     //todo render player.player
// }

////////////////////////////////////////////////////////////////////////////////

// void game(t_vars *strct) {
//     ft_setup(strct);
//     ft_update(strct);
//     ft_render(strct);
// }

// ////////////////////////////////////////////////////////////////////////////////

int ft_update(t_vars *strct) {
    ft_black_screen(strct);
    ft_move(strct);
    ft_square(strct, strct->player.playerX, strct->player.playerY,
        strct->player.player_width, strct->player.player_height, 0x00FF0000);
    mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
    return (0);
}

// ////////////////////////////////////////////////////////////////////////////////

int         main(int argc, char **argv)
{
    t_vars  strct;
    
    strct.mlx = mlx_init();
    //initializes struct containing information regarding mlx and the window size
    ft_init_struct(&strct);
    if ((ft_check_args(&strct, argc, argv) < 0) || (ft_check_input(&strct) < 0)
        || ft_check_map(&strct)){
        close_program(&strct);
        return(-1);
    }
    if (ft_init_window(&strct) == -1){
        printf("Error initializing window.");
        close_program(&strct);
    }
    mlx_hook(strct.mlx_win, 2, 1L<<0, key_press, &strct);
    mlx_hook(strct.mlx_win, 3, 1L<<1, key_release, &strct);
    mlx_hook(strct.mlx_win, 33, 1L<<17, close_program, &strct);
    
    //ft_update(&strct);
    //ft_mlx_pixel_put(&strct, 5, 5, 0x00FF0000);
    //ft_square(&strct, 5, 5, 100, 100, 0x00FF0000);
    //mlx_put_image_to_window(strct.mlx, strct.mlx_win, strct.img, 0, 0);
    //no idea what this does. I think it keeps the window open.
    mlx_loop_hook(strct.mlx, ft_update, &strct);
    mlx_loop(strct.mlx);

    free(strct.mlx);
    free(strct.NO_texture);
    free(strct.SO_texture);
    free(strct.WE_texture);
    free(strct.EA_texture);
    free(strct.Sprite_texture);
    mlx_destroy_image(strct.mlx, strct.img);
    mlx_destroy_window(strct.mlx, strct.mlx_win);
    mlx_destroy_display(strct.mlx);
    
    return (0);

















    
    mlx_hook(strct.mlx_win, 2, 1L<<0, key_press, &strct);
    mlx_hook(strct.mlx_win, 3, 1L<<1, key_release, &strct);
    mlx_hook(strct.mlx_win, 33, 1L<<17, close_program, &strct);

    //no idea what this does. I think it keeps the window open.
    mlx_loop_hook(strct.mlx, ft_update, &strct);
    mlx_loop(strct.mlx);

    free(strct.mlx);
    free(strct.NO_texture);
    free(strct.SO_texture);
    free(strct.WE_texture);
    free(strct.EA_texture);
    free(strct.Sprite_texture);
    mlx_destroy_image(strct.mlx, strct.img);
    mlx_destroy_window(strct.mlx, strct.mlx_win);
    mlx_destroy_display(strct.mlx);
    
    return (0);
}