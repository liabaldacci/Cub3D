/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 13:10:35 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_move(t_vars *strct) {
    if (strct->left == 1 && strct->player.playerX > 0)
        strct->player.playerX--;
    if (strct->right == 1 && ((strct->player.playerX + strct->player.player_width) < strct->window_width))
        strct->player.playerX++;
    if (strct->up == 1 && strct->player.playerY > 0)
        strct->player.playerY--;
    if (strct->down == 1 && ((strct->player.playerY + strct->player.player_height) < strct->window_height))
        strct->player.playerY++;
    return (0);
}