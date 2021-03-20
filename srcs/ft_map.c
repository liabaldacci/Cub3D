/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:26:21 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/19 21:03:05 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int         ft_check_input(t_vars *strct)
{
    int     fd;
    char    *line;
    int     i;
    
    line = NULL;

    fd = open(strct->map_path, O_RDONLY);
	//get_next_line(fd, &line);
    
    while(get_next_line(fd, &line) == 1)
    {
        i = 0;
        if ((line[i] == 'R') && line[i + 1] == ' ') {
            ft_putendl_fd("ft_res", 1);
        }
        else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ') {
            ft_putendl_fd("ft_color", 1);
        }
        else if (((line[i] == 'N' || line[i] == 'S') && line[i + 1] == 'O' && line[i + 2] == ' ')
            || (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ') 
            || (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
            || (line[i] == 'S' && line[i + 1] == ' ')) {
            ft_putendl_fd("ft_textures", 1);
            }
        else if ((line[i] >= 8 && line[i] <= 13) || (line[i] == ' '))
            continue;
        else if (ft_strncmp(line, "\000", 5) == 0)
            continue;
        else if (line[i] == '1'){
            ft_putendl_fd("ft_map", 1);
            continue;
        }
        else {
            ft_putendl_fd("Map is not valid", 1); //Corrigir isso, pois ele tem que checar o mapa por último tb
            return (-1);
        }
    }
    // if NO, SO, EA, WE, S
    //     ft_texture();
    // else if C, F
    //     ft_color();
    // else if R
    //     ft_res();
    close(fd);
    return (0);
}