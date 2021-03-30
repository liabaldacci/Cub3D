/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 21:33:15 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_move(t_vars *strct) {
    int new_position;
    
    if (strct->left == 1 && strct->player.playerX > 0){
        if (strct->player.playerX - strct->player.walk_speed > 0){
            strct->player.playerX = strct->player.playerX - strct->player.walk_speed;
        }
        else
            strct->player.playerX = 0;
        }
    if (strct->right == 1) {
        new_position = strct->player.playerX + strct->player.player_width + strct->player.walk_speed;
        if (new_position < strct->window_width)
            strct->player.playerX = strct->player.playerX + strct->player.walk_speed;
        else
            strct->player.playerX = strct->window_width - strct->player.player_width;
    }
    if (strct->up == 1 && strct->player.playerY > 0){
        if (strct->player.playerY - strct->player.walk_speed > 0)
            strct->player.playerY = strct->player.playerY - strct->player.walk_speed;
        else
            strct->player.playerY = 0;
    }
    if (strct->down == 1){
        new_position = strct->player.playerY + strct->player.player_height + strct->player.walk_speed;
        if (new_position < strct->window_height)
            strct->player.playerY = strct->player.playerY + strct->player.walk_speed;
        else
            strct->player.playerY = strct->window_height - strct->player.player_height;
    }
    return (0);
}