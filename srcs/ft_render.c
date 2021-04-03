/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:11:01 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/01 15:47:19 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int         ft_render_map(t_vars *strct){
    int     i;
    int     j;
    int     tile_x_position;
    int     tile_y_position;
    int     tile_color;

    i = 0;
    j = 0;
    while (i < strct->map_height){
        while (j < strct->map_width){
            tile_x_position = j * strct->tile_X * strct->minimap_scale;
            tile_y_position = i * strct->tile_Y * strct->minimap_scale;
            if (strct->map[i][j] == '1' || strct->map[i][j] == 'X')
                tile_color = 0x00000000;
            else if (strct->map[i][j] == '2')
                tile_color = 0xFF0000;
            else
                tile_color = 0xFFFFFF;
            ft_square(strct, (tile_x_position * strct->minimap_scale),
                (tile_y_position * strct->minimap_scale),
                (strct->tile_Y * strct->minimap_scale),
                (strct->tile_X * strct->minimap_scale), tile_color);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int     ft_render_player(t_vars *strct){
    int color;
    int scaled_player_x;
    int scaled_player_y;
    int scaled_player_width;
    int scaled_player_height;

    color = 0x0000FF;
    scaled_player_x = strct->player.playerX * strct->minimap_scale;
    scaled_player_y = strct->player.playerY * strct->minimap_scale;
    scaled_player_width = strct->player.player_width * strct->minimap_scale;
    scaled_player_height = strct->player.player_height * strct->minimap_scale;
    ft_square(strct, scaled_player_x,
            scaled_player_y,
            scaled_player_width,
            scaled_player_height, color);
    drawLine(strct, scaled_player_x + (scaled_player_width / 2),
        scaled_player_y + (scaled_player_height / 2),
        (scaled_player_x + cos(strct->player.rotation_angle) * 100 * strct->minimap_scale),
        (scaled_player_y + sin(strct->player.rotation_angle) * 100 * strct->minimap_scale));
    return (0);
}