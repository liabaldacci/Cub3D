/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:00:22 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/18 21:54:57 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int key_press(int keycode, t_vars *strct) {
    //if the UP or 'w' keys have been pressed
    if (keycode == 65362 || keycode == 119)
        strct->up = 1;
    //if the DOWN or 's' keys have been pressed
    else if (keycode == 65364 || keycode == 115)
        strct->down = 1;
    //if the LEFT or 'a' keys have been pressed
    else if (keycode == 65361 || keycode == 97)
        strct->left = 1;
    //if the RIGHT or 'd' keys have been pressed
    else if (keycode == 65363 || keycode == 100)
        strct->right = 1;
    //if the 'esc' key has been pressed the program closes.
    else if (keycode == 65307) {
        mlx_destroy_window(strct->mlx, strct->mlx_win);
        close_program();}
    return (0);
}
int key_release(int keycode, t_vars *strct) {
    //if the UP or 'w' keys have been pressed
    if (keycode == 65362 || keycode == 119)
        strct->up = 0;
    //if the DOWN or 's' keys have been pressed
    else if (keycode == 65364 || keycode == 115)
        strct->down = 0;
    //if the LEFT or 'a' keys have been pressed
    else if (keycode == 65361 || keycode == 97)
        strct->left = 0;
    //if the RIGHT or 'd' keys have been pressed
    else if (keycode == 65363 || keycode == 100)
        strct->right = 0;
    return (0);
}