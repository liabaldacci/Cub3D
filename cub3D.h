/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/17 21:54:23 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>   

typedef struct  s_vars
{
    void        *mlx;
    void        *mlx_win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         window_height;
    int         window_width;
    char        *window_title;
    int     up;
    int     down;
    int     left;
    int     right;
    int     mouse_x;
    int     mouse_y;
    int         playerX;
    int         playerY;
    
}               t_vars;

int     main(void);
void    ft_init_struct(t_vars *strct);
int     ft_init_window(t_vars *strct);
void    ft_mlx_pixel_put(t_vars *strct, int x, int y, int color);
void    ft_square(t_vars *strct, int x, int y, int height, int width, unsigned int color);
void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color);
void    ft_empty_circle(t_vars *strct, int x, int y, int radius, int color);
void    ft_filled_circle(t_vars *strct, int x, int y, int radius, int color);
int     key_hook(int keycode, t_vars *strct);
int     close_program(void);

#endif