/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:49:49 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 21:49:51 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_free_all(t_vars *strct)
{
    int i;

    i = -1;
    while (i++ < 5)
    {
        if (strct->tex_path[i])
        {
            free(strct->tex_path[i]);
        }
    }
    free(strct->mlx);
	if (strct->fd != -1)
		close(strct->fd);
}

int     close_program(t_vars *strct)
{
	if (strct->img)
			mlx_destroy_image(strct->mlx, strct->img);
	ft_free_all(strct);
    exit(0);
    return(1);
}