/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:43:31 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/08 12:55:24 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int     close_program(t_vars *strct)
{
    //closes the program but does not destroy windows.
    free(strct->mlx);
    exit(0);
    return(1);
}