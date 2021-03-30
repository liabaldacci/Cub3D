/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:47:10 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/29 20:45:34 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void        ft_get_direction(t_vars *strct){
    if (strct->direction == 'N')
        strct->player.rotation_angle = PI / 2;
    else if (strct->direction == 'W')
        strct->player.rotation_angle = PI;
    else if (strct->direction == 'S')
        strct->player.rotation_angle = (3 * PI) / 2;
    else if (strct->direction == 'E')
        strct->player.rotation_angle = 0;
}

int         ft_map_is_valid(t_vars *strct){
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < strct->map_height){
        while (j < strct->map_width){
            if (strct->map[i][j] == 'X'){
                if (i != 0)
                    if (!ft_strchr("1X", strct->map[i-1][j]))
                        return (-1);
                if (i != strct->map_height - 1)
                    if (!ft_strchr("1X", strct->map[i+1][j]))
                        return (-1);
                if (j != 0)
                    if (!ft_strchr("1X", strct->map[i][j-1]))
                        return (-1);
                if (j != strct->map_width - 1)
                    if (!ft_strchr("1X", strct->map[i][j+1]))
                        return (-1);
            }
            else if (strct->map[i][j] == '0'){
                if (i == 0 || i == strct->map_height - 1 || j == 0
                    || j == strct->map_width - 1)
                    return (-1);
                else{
                    if (!ft_strchr("012NSWE", strct->map[i-1][j]))
                        return (-1);
                    if (!ft_strchr("012NSWE", strct->map[i+1][j]))
                        return (-1);
                    if (!ft_strchr("012NSWE", strct->map[i][j-1]))
                        return (-1);
                    if (!ft_strchr("012NSWE", strct->map[i][j+1]))
                        return (-1);
                }
            }
        j++;
        }
    j = 0;
    i++;
    }
    return (0);
}

int         ft_check_map(t_vars *strct)
{
    int     fd;
    char    *line;
    int     line_nbr;
    char    *check;

    line_nbr = 0;
    line = NULL;
    fd = open(strct->map_path, O_RDONLY);
    strct->map = (char **)ft_calloc((strct->map_height + 1) * sizeof(char *));
    // while (line_nbr <= strct->map_height){
    //     strct->map[line_nbr] = ft_calloc((strct->map_width + 1) * sizeof(char));
    //     line_nbr++;
    // }
    while(get_next_line(fd, &line) == 1)
    {
        if (ft_strchr("NSWE\t\n\v\f\r", line[0])) {
            free(line);
            continue;
        }
        else if(line[0] == ' ' || line[0] == '1'){
            if (ft_strchr(line, '1') != 0){
                if (ft_map(line, strct, line_nbr) < 0)
                {
                    ft_putendl_fd("Map is not valid.", 1);
                    free(line);
                    close(fd);
                    return (-1);
                }
                check = strct->map[line_nbr];
                printf("%s\n", strct->map[line_nbr]);
                line_nbr++;
            }
        }
        free(line);
    }
    if (ft_strchr(line, '1') != 0){
        ft_map(line, strct, line_nbr);
        printf("%s\n", strct->map[line_nbr]);
        line_nbr++;
    }
    close(fd);
    free(line);
    if (ft_map_is_valid(strct) < 0)
    {
        ft_putendl_fd("Map is not valid.", 1);
        return (-1);
    }
    // ft_putendl_fd("done", 1);
    // while (*strct->map){
    //     printf("%s\n", *strct->map);
    //     *strct->map++;}
    return (0);
}

int     ft_map(char *str, t_vars *strct, int line_nbr) {
    int i;
    char    *temp;

    i = 0;
    if ((str[ft_strlen(str)-1]) != '1')
        return (-1);
    temp = ft_calloc((strct->map_width + 1) * sizeof(char));
    while (str[i] != '\0' && ft_strchr("012NSWE \t\n\v\f\r", str[i])){
        if (ft_strchr(" \t\n\v\f\r", str[i]))
            temp[i] = 'X';
        else if (ft_strchr("NSWE", str[i])){
            if (strct->player.playerX != 0 || strct->player.playerY != 0){
                ft_putendl_fd("Player position is invalid.", 1);
                free(temp);
                return (-1);
            }
            strct->player.playerX = i;
            strct->player.playerY = line_nbr;
            strct->player.direction = str[i];
            ft_get_direction(strct);
            temp[i] = '0';
        }
        else if (ft_strchr("012", str[i]))
            temp[i] = str[i];
        else
            return (-1);
        i++;
    }
    if (strct->map_width > ft_strlen(str)){
        while (i < strct->map_width){
            temp[i] = 'X';
            i++;
        }
    }
    strct->map[line_nbr] = temp;
    return (1);
}