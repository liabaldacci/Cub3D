/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/18 22:09:55 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_move(t_vars *strct) {
    if (strct->left == 1 && strct->playerX > 0)
        strct->playerX--;
    if (strct->right == 1 && ((strct->playerX + strct->player_size) < strct->window_width))
        strct->playerX++;
    if (strct->up == 1 && strct->playerY > 0)
        strct->playerY--;
    if (strct->down == 1 && ((strct->playerY + strct->player_size) < strct->window_height))
        strct->playerY++;
    return (0);
}