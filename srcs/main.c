/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:38 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/19 20:31:25 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"



////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

// void ft_setup(t_vars *strct) {
//     strct->playerX = 0;
//     strct->playerY = 0;
// }



// void ft_render(t_vars *strct) {
//     //mlx_mouse_hook(strct.mlx_win, mouse_hook, &strct);
    
//     //pushes the image to the window.
//     mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
// }

////////////////////////////////////////////////////////////////////////////////

// void game(t_vars *strct) {
//     ft_setup(strct);
//     ft_update(strct);
//     ft_render(strct);
// }

// ////////////////////////////////////////////////////////////////////////////////

int ft_update(t_vars *strct) {     
    //ft_mlx_pixel_put(&strct, 5, 5, 0x00FF0000);
    // strct->playerX += 1;
    // strct->playerY += 1;
    ft_black_screen(strct);
    ft_move(strct);
    ft_square(strct, strct->playerX, strct->playerY, strct->player_size, strct->player_size, 0x00FF0000);
    mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
    return (0);
}

// ////////////////////////////////////////////////////////////////////////////////

// void    teste(t_vars *strct) {
    
//     strct->img = mlx_new_image(strct->mlx, 800, 800);
// }


int         main(int argc, char **argv)
{
    t_vars  strct;
    

    if ((ft_check_args(&strct, argc, argv) < 0) || (ft_check_input(&strct) < 0))
        return(-1);
    if (ft_init_window(&strct) == -1){
        printf("Error initializing window.");
        close_program();
    };
    //mlx_key_hook(strct.mlx_win, key_hook, &strct);
    //creates an image that will be pushed to the screen. This takes up less computing space and resources.
    //teste(&strct);
            
    //not sure what this does. Probably gets information from something called addr inside the struct that
    //contains the info necessary to use graphics.
    // strct.addr = mlx_get_data_addr(strct.img, &(strct.bits_per_pixel),
    //         &(strct.line_length), &(strct.endian));
    strct.player_size = 10;
    mlx_hook(strct.mlx_win, 2, 1L<<0, key_press, &strct);
    mlx_hook(strct.mlx_win, 3, 1L<<1, key_release, &strct);
    mlx_hook(strct.mlx_win, 33, 1L<<17, close_program, &strct);
    
    //ft_update(&strct);
    //ft_mlx_pixel_put(&strct, 5, 5, 0x00FF0000);
    //ft_square(&strct, 5, 5, 100, 100, 0x00FF0000);
    //mlx_put_image_to_window(strct.mlx, strct.mlx_win, strct.img, 0, 0);
    strct.playerX = 0;
    strct.playerY = 0;
    //no idea what this does. I think it keeps the window open.
    mlx_loop_hook(strct.mlx, ft_update, &strct);
    mlx_loop(strct.mlx);

    mlx_destroy_image(strct.mlx, strct.img);
    mlx_destroy_window(strct.mlx, strct.mlx_win);
    mlx_destroy_display(strct.mlx);
    free(strct.mlx);
    
    return (0);
}


// int main (void)
// {
//         t_game  game;
//         game.screen.mlx = mlx_init();
//         window_init(&(game.screen));
//         mlx_destroy_image(game.screen.mlx, game.screen.img);
//         mlx_destroy_window(game.screen.mlx, game.screen.win);
//         mlx_destroy_display(game.screen.mlx);
//         free(game.screen.mlx);
//         return (0);
// }