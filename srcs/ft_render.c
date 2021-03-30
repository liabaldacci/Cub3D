/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:11:01 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 20:36:14 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int         ft_render_map(t_vars *strct){
//     int     i;
//     int     j;
//     int     tile_x_position;
//     int     tile_y_position;
//     int     tile_color;

//     i = 0;
//     j = 0;
//     ft_putendl_fd("render map", 1);
//     while (i < strct->map_height){
//         while (j < strct->map_width){
//             tile_x_position = j * strct->tile_X;
//             tile_y_position = i * strct->tile_Y;
//             if (strct->map[i][j] == '1' || strct->map[i][j] == 'X')
//                 tile_color = 0x00000000;
//             else
//                 tile_color = 0xFFFFFF;
//             ft_square(strct, tile_x_position, tile_y_position, strct->tile_Y,
//                 strct->tile_Y, tile_color);
//             j++;
//         }
//         j = 0;
//         i++;
//     }
//     return (0);
// }