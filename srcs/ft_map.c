/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:47:10 by gadoglio          #+#    #+#             */
/*   Updated: 2021/03/25 22:45:24 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int         ft_check_map(t_vars *strct)
{
    int     fd;
    char    *line;
    int     line_nbr;
    int     i;
    int     gnl_result;

    line_nbr++;
    strct->map = (char*)ft_calloc((strct->map_width + 1));
    line = NULL;
    fd = open(strct->map_path, O_RDONLY);
    while(get_next_line(fd, &line) == 1)
    {
        if (ft_strchr("NSWE\t\n\v\f\r", line[0])) {
            free(line);
            continue;
        }
        else if(line[i] == ' ' || line[i] == '1'){
            if (ft_strchr(line, '1') != 0){
                printf("%s",line);
                //ft_map(line, strct, line_nbr);
                line_nbr++;
            }
        }
        free(line);
    }
    if (ft_strchr(line, '1') != 0){
        printf("%s",line);
        //ft_map(line, strct, line_nbr);
        line_nbr++;
    }
    close(fd);
    free(line);
    ft_putendl_fd("done", 1);
    return (0);
}

// int     ft_map(char *str, t_vars *strct,int line_nbr) {
//     int i;
//     int line_nbr;
    
//     while (str[i] != '\0' && ft_strchr("012NSWE \t\n\v\f\r", str[i])) {
        
//     }
//     strct->map[line_nbr] = ft_strdup(str);
    
// }