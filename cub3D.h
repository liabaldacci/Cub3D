/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/08 22:19:04 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.141592653589793238462643383279502884197169399375105820974944
# define TWO_PI PI*2

# include "./minilibx-linux/mlx.h"
# include "./GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>   
# include <fcntl.h>
#include <string.h>

typedef struct  s_player
{
    
    int         x;
    int         y;
    char        direction;
    int         width;
    int         height;
    int         turn_direction; //-1 for left and +1 for right
    int         walk_direction; //-1 for going backwards and +1 for going forward
    double      rotation_angle;
    double      walk_speed;
    double      turn_speed;
    double      fov_angle;
    
}               t_player;

typedef struct  s_rays
{
    
    double          num_of;
    double          size_of;
    double          distance; //distance between player and wall hit
    double          wall_hit_x;
    double          wall_hit_y;
    double          wall_hit_content;
    double          was_hit_vertical;
    double          ray_angle;
    int             is_facing_down;
    int             is_facing_up;
    int             is_facing_left;
    int             is_facing_right;
    double          horz_hit_distance;
    double          vert_hit_distance;
    double          horz_wall_hit_x;
    double          horz_wall_hit_y;
    double          vert_wall_hit_x;
    double          vert_wall_hit_y;
    
}               t_rays;

typedef struct  s_vars
{
    void        *mlx;
    void        *mlx_win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         window_height;
    int         window_width;
    char       *window_title;
    int         R_ceiling;
    int         G_ceiling;
    int         B_ceiling;
    int         R_floor;
    int         G_floor;
    int         B_floor;
    char        *NO_texture;
    char        *SO_texture;
    char        *WE_texture;
    char        *EA_texture;
    char        *Sprite_texture;
    int         up;
    int         down;
    int         left;
    int         right;
    char        *map_path;
    int         map_width;
    int         map_height;
    char        **map;
    int         tile_X;
    int         tile_Y;
    double      minimap_scale;
    t_player    player;
    t_rays      rays;
    
}               t_vars;



int     main(int argc, char **argv);
void    ft_init_struct(t_vars *strct);
int     ft_init_window(t_vars *strct);
void    ft_mlx_pixel_put(t_vars *strct, int x, int y, int color);
void    ft_square(t_vars *strct, int x, int y, int height, int width, unsigned int color);
void    ft_line(t_vars *strct, int x1, int y1, int x2, int y2, int color);
void    ft_empty_circle(t_vars *strct, int x, int y, int radius, int color);
void    ft_filled_circle(t_vars *strct, int x, int y, int radius, int color);
int     key_press(int keycode, t_vars *strct);
int     key_release(int keycode, t_vars *strct);
int     close_program(t_vars *strct);
int     ft_move(t_vars *strct);
void	ft_putendl_fd(char *s, int fd);
int     ft_check_argument(char *s);
int     ft_check_args(t_vars *vars, int argc, char **argv);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_check_input(t_vars *strct);
void    ft_black_screen(t_vars *strct);
int     ft_eval_line(char *line, t_vars *strct);
int     ft_resolution(char *str, t_vars *strct);
int     ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int     ft_colors(char *str, t_vars *strct);
int     ft_textures(char *str, t_vars *strct);
int     ft_check_map(t_vars *strct);
int     ft_map(char *str, t_vars *strct, int line_nbr);
int     ft_render_map(t_vars *strct);
int     ft_render_player(t_vars *strct);
int    ft_draw_line(t_vars *strct, int x1, int y1, int x2, int y2);
int     ft_has_wall_at(t_vars *strct, double x, double y);
void    cast_all_rays(t_vars *strct);
void        ft_init_structs(t_vars *strct);
double       ft_normalize_angle(double angle);
double      ft_distance_between_points(double x1, double y1, double x2, double y2);




#endif