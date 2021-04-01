/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/01 16:05:19 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_move(t_vars *strct) {
    double new_position;
    double new_x;
    double new_y;
    double  move_step;

    strct->player.rotation_angle += strct->player.turn_direction * strct->player.turn_speed;
    move_step = strct->player.walk_direction * strct->player.walk_speed;
    new_x = strct->player.playerX + cos(strct->player.rotation_angle) * move_step;
    new_y = strct->player.playerY + sin(strct->player.rotation_angle) * move_step;
    printf("current x: %i\nnext x:%f\n",strct->player.playerX, new_x);
    printf("current y: %i\nnext y:%f\n\n",strct->player.playerY, new_y);

    //only set new player position if it is not coliding with map wall
    if (ft_has_wall_at(strct, new_x, new_y) == 0) {
        strct->player.playerX = new_x;
        strct->player.playerY = new_y;
    }
    return (0);
}
    

int     ft_has_wall_at(t_vars *strct, double x, double y){
    int i;
    int j;
    int value;

    if (x < 0 || x + strct->player.player_width > strct->window_width
        || y < 0 || y + strct->player.player_height > strct->window_height) {
            return (1);
        }
    i = floor((x + strct->player.player_width) / strct->tile_X);
    j = floor((y + strct->player.player_height) / strct->tile_Y);
    // printf("%i\n", i);
    // printf("%i\n", j);
    // printf("%c\n\n", strct->map[j][i]);
    value = strct->map[j][i] != '0';
    return (value);
}
//     if (strct->left == 1 && strct->player.playerX > 0){
//         if (strct->player.playerX - strct->player.walk_speed > 0){
//             strct->player.playerX = strct->player.playerX - strct->player.walk_speed;
//         }
//         else
//             strct->player.playerX = 0;
//         }
//     if (strct->right == 1) {
//         new_position = strct->player.playerX + strct->player.player_width + strct->player.walk_speed;
//         if (new_position < strct->window_width)
//             strct->player.playerX = strct->player.playerX + strct->player.walk_speed;
//         else
//             strct->player.playerX = strct->window_width - strct->player.player_width;
//     }
//     if (strct->up == 1 && strct->player.playerY > 0){
//         if (strct->player.playerY - strct->player.walk_speed > 0)
//             strct->player.playerY = strct->player.playerY - strct->player.walk_speed;
//         else
//             strct->player.playerY = 0;
//     }
//     if (strct->down == 1){
//         new_position = strct->player.playerY + strct->player.player_height + strct->player.walk_speed;
//         if (new_position < strct->window_height)
//             strct->player.playerY = strct->player.playerY + strct->player.walk_speed;
//         else
//             strct->player.playerY = strct->window_height - strct->player.player_height;
//     }
//     return (0);
// }