/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:38 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 20:12:59 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void ft_render(t_vars *strct) {
    ft_black_screen(strct);
    ft_putendl_fd("HERE", 1);
    ft_render_map(strct);
    //todo render map
    //todo render rays
    //todo render player
    ft_square(strct, strct->player.playerX, strct->player.playerY,
        strct->player.player_width, strct->player.player_height, 0x00FF0000);

    mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
}

int ft_update(t_vars *strct) {
    //ft_update_player(strct);
    //ft_update_screen(strct);
    
    //ft_move(strct);
    return (0);
}

////////////////////////////////////////////////////////////////////////////////

void ft_game(t_vars *strct) {
    ft_square(strct, strct->player.playerX, strct->player.playerY,
        strct->player.player_width, strct->player.player_height, 0x00FF0000);

    mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
    // ft_update(strct);
    // ft_render(strct);
}

// ////////////////////////////////////////////////////////////////////////////////



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
    strct.num_of_rays = strct.window_width;
    strct.tile_X = strct.window_width/strct.map_width;
    strct.tile_Y = strct.window_height/strct.map_height;
    if (ft_init_window(&strct) == -1){
        printf("Error initializing window.");
        close_program(&strct);
    };
    mlx_hook(strct.mlx_win, 2, 1L<<0, key_press, &strct);
    mlx_hook(strct.mlx_win, 3, 1L<<1, key_release, &strct);
    mlx_hook(strct.mlx_win, 33, 1L<<17, close_program, &strct);

    //no idea what this does. I think it keeps the window open.
    mlx_loop_hook(strct.mlx, ft_game, &strct);
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