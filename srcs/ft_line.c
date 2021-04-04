/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:30 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/03 22:59:06 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color){
    int first_x;
    int first_y;
    int last_x;
    int last_y;
    int temp;

    first_x = (x1 > x2) ? x2 : x1;
    last_x = (x1 > x2) ? x1 : x2;
    first_y = (y1 > y2) ? y2 : y1;
    last_y = (y1 > y2) ? y1 : y2;
    temp = first_y;

    while (first_x <= last_x){
        while (first_y <= last_y){
            ft_mlx_pixel_put(strct, first_x, first_y, color);
            first_y++;
        }
        first_x++;
        first_y = temp;
    }
}

void drawLine(t_vars *strct, int x1, int y1, int x2, int y2){
    int dx;
    int dy;
    int controle;   //Controla se a direção menor vai crescer ou nao;
    int x_inc;
    int y_inc;
    int x;
    int y;
    int color;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    controle = 0;
    x_inc = 0;
    y_inc = 0;
    color = 0x00FF0000;

    //Define se Y e X estão indo nas direções positivas ou negativas
    x_inc = (x2 > x1) ? 1 : -1;
    y_inc = (y2 > y1) ? 1 : -1;
    ft_mlx_pixel_put(strct, x1, y1, color);
    x = x1;
    y = y1;
    //Pixel linha = {xi, yi, inicial.red, inicial.green, inicial.blue, inicial.alpha};
    if(dx == 0){
        if(y2 > y1){    //linha pra baixo
            while(y != y2)
            {
                y++;              
                ft_mlx_pixel_put(strct, x, y, color);
            }
        }
        else{           //linha pra cima
            while(y != y2)
            {
                y--;               
                ft_mlx_pixel_put(strct, x, y, color);
            }
        }
    }
    else if(dy == 0){
        if(x2 > x1){    //linha pra direita
            while(x != x2)
            {
                x++;                
                ft_mlx_pixel_put(strct, x, y, color);
            }
        }
        else{           //linha pra esquerda
            while(x != x2)
            {
                x--;                
                ft_mlx_pixel_put(strct, x, y, color);
            }
        }
}
else {
        if (dx >= dy) {
            controle = dx / 2;
            ft_mlx_pixel_put(strct, x1, y1, color);
            while (x != x2) {
                x += x_inc;
                controle = controle - dy;
                if (controle < 0) {
                    y += y_inc;
                    controle += dx;
                }                
                ft_mlx_pixel_put(strct, x, y, color);
            }
        } else {
            controle = dy / 2;
            ft_mlx_pixel_put(strct, x1, y1, color);
            while (y != y2) {
                y += y_inc;
                controle = controle - dx;
                if (controle < 0) {
                    x += x_inc;
                    controle += dy;
                }                
                ft_mlx_pixel_put(strct, x, y, color);
            }
        }
    }
}