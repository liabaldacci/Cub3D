/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:10:45 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/14 21:39:53 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int					get_tex_pixel(t_vars *strct, int x, int y, int index)
{
	char		*color;

	color = (strct->tex[index].img) + (strct->tex[index].h * y *
			(strct->tex[index].bpp / 8)) + (x * (strct->tex[index].bpp / 8));
	if (color == 0)
		return (0);
	else
		return (*(int *)color);
}

int         ft_load_textures(t_vars *strct, int i)
{
    void    *mlx;
    char    *str;

    mlx = mlx_xpm_file_to_image(strct->mlx, strct->tex_path[i],
        &strct->tex[i].w, &strct->tex[i].h);
    if (!mlx)
    {
        ft_putendl_fd("ERROR!\nNo texture was loaded.", 1);
        return (-1);
    }
    str = mlx_get_data_addr(mlx, &strct->tex[i].bpp, &strct->tex[i].line_length,
        &strct->tex[i].endian);
    if (!str)
    {
        ft_putendl_fd("ERROR!\nInvalid textures.", 1);
        return (-1);
    }
    strct->tex[i].mlx = mlx;
    strct->tex[i].img = str;
    return (0);
}

//TODO: fazer contas pikuma
//TODO: pegar cor do pixel no (x,y) da textura
//TODO: pixel put com essa cor no (x, y) da parede

void        ft_draw_texture(t_vars *strct, int top_pixel, int bottom_pixel, double wall_strip_height, int i)
{
    int     x;
    int     y;
    double  x_tex;
    double  y_tex;
    int     color;
    double  distance_from_top;

    x = strct->rays.column_id;
    y = top_pixel;
    if (strct->rays.was_hit_vertical == 1)
        x_tex = fmod(strct->rays.wall_hit_y, strct->tile_Y) * (strct->tex[i].w / (double)strct->tile_Y);
    else
        x_tex = fmod(strct->rays.wall_hit_x, strct->tile_X) * (strct->tex[i].w / (double)strct->tile_X);
    while (y <= bottom_pixel)
    {
        // if (y == 638)
        //     ft_putendl_fd("paROU!", 1);
        distance_from_top = y + (wall_strip_height / 2) - (strct->window_height / 2);
        y_tex = (distance_from_top * (strct->tex[i].h / wall_strip_height));
        color = get_tex_pixel(strct, (int)x_tex, (int)y_tex, i);
        ft_mlx_pixel_put(strct, x, y, color);
        y++;
    }
}
