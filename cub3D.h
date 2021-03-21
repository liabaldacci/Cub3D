/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/21 16:46:58 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include "./GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>   
# include <fcntl.h> 

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
    int         up;
    int         down;
    int         left;
    int         right;
    int         mouse_x;
    int         mouse_y;
    int         playerX;
    int         playerY;
    int         player_size;
    char        *map_path;
    
}               t_vars;

int     main(int argc, char **argv);
void    ft_init_struct(t_vars *strct);
int     ft_init_window(t_vars *strct);
void    ft_mlx_pixel_put(t_vars *strct, int x, int y, int color);
void    ft_square(t_vars *strct, int x, int y, int height, int width, unsigned int color);
void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color);
void    ft_empty_circle(t_vars *strct, int x, int y, int radius, int color);
void    ft_filled_circle(t_vars *strct, int x, int y, int radius, int color);
int     key_press(int keycode, t_vars *strct);
int     key_release(int keycode, t_vars *strct);
int     close_program(void);
int     ft_move(t_vars *strct);
void	ft_putendl_fd(char *s, int fd);
int     ft_check_argument(char *s);
int     ft_check_args(t_vars *vars, int argc, char **argv);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_check_input(t_vars *strct);
void    ft_black_screen(t_vars *strct);
int     ft_eval_line(char   *line);


#endif