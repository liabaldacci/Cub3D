/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:47:10 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 21:32:03 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			ft_get_direction(t_vars *strct)
{
	if (strct->player.direction == 'S')
		strct->player.rotation_angle = PI / 2;
	else if (strct->player.direction == 'W')
		strct->player.rotation_angle = PI;
	else if (strct->player.direction == 'N')
		strct->player.rotation_angle = (3 * PI) / 2;
	else if (strct->player.direction == 'E')
		strct->player.rotation_angle = 0;
	else
		ft_errors(strct, 9);
	return (0);
}

void		ft_check_space(t_vars *strct, int i, int j, int situation)
{
	if (situation == 1)
	{
		if ((i != 0) && (!ft_strchr("1X", strct->map[i - 1][j])))
			ft_errors(strct, 8);
		if (i != strct->map_height - 1)
			if (!ft_strchr("1X", strct->map[i + 1][j]))
				ft_errors(strct, 8);
		if ((j != 0) && (!ft_strchr("1X", strct->map[i][j - 1])))
			ft_errors(strct, 8);
		if ((j != strct->map_width - 1))
			if (!ft_strchr("1X", strct->map[i][j + 1]))
				ft_errors(strct, 8);
	}
	else
	{
		if (!ft_strchr("012NSWE", strct->map[i - 1][j]))
			ft_errors(strct, 8);
		if (!ft_strchr("012NSWE", strct->map[i + 1][j]))
			ft_errors(strct, 8);
		if (!ft_strchr("012NSWE", strct->map[i][j - 1]))
			ft_errors(strct, 8);
		if (!ft_strchr("012NSWE", strct->map[i][j + 1]))
			ft_errors(strct, 8);
	}
}

int			ft_map_is_valid(t_vars *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < strct->map_height)
	{
		while (j < strct->map_width)
		{
			if (strct->map[i][j] == 'X')
				ft_check_space(strct, i, j, 1);
			else if (strct->map[i][j] == '0')
			{
				if (i == 0 || (i == strct->map_height - 1) || j == 0
					|| (j == strct->map_width - 1))
					ft_errors(strct, 8);
				else
					ft_check_space(strct, i, j, 2);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int			ft_map(char *str, t_vars *strct, int line_nbr)
{
	int		i;
	char	*temp;

	i = 1;
	while (str[ft_strlen(str) - i] == ' ')
		i++;
	if (str[ft_strlen(str) - i] != '1')
		ft_errors(strct, 8);
	i = 0;
	temp = ft_calloc((strct->map_width + 1) * sizeof(char));
	while (str[i] != '\0' && ft_strchr("012NSWE \t\n\v\f\r", str[i]))
	{
		if (ft_strchr(" \t\n\v\f\r", str[i]))
			temp[i] = 'X';
		else if (ft_strchr("2", str[i]))
		{
			temp[i] = str[i];
			strct->sprite[strct->sprite_id].x = (i * strct->tile_X);
			strct->sprite[strct->sprite_id].y = (line_nbr * strct->tile_Y);
			strct->sprite_id++;
		}
		else if (ft_strchr("NSWE", str[i]))
		{
			if (strct->player.x != 0 || strct->player.y != 0)
			{
				free(temp);
				ft_errors(strct, 8);
			}
			ft_init_tile(strct, i, str, line_nbr);
			temp[i] = '0';
		}
		else if (ft_strchr("012", str[i]))
			temp[i] = str[i];
		else
			ft_errors(strct, 8);
		i++;
	}
	if (!ft_strchr("012NSWE \t\n\v\f\r", str[i]))
		ft_errors(strct, 8);
	if (strct->map_width > ft_strlen(str))
	{
		i--;
		while (i++ < strct->map_width)
			temp[i] = 'X';
	}
	strct->map[line_nbr] = temp;
	return (1);
}

int			ft_check_map(t_vars *strct)
{
	char	*line;
	int		line_nbr;

	line_nbr = 0;
	line = NULL;
	strct->fd = open(strct->map_path, O_RDONLY);
	strct->map = (char **)ft_calloc((strct->map_height + 1) * sizeof(char *));
	ft_init_sprites(strct);
	while (get_next_line(strct->fd, &line) == 1)
	{
		strct->line = &line;
		if (line[0] == ' ' || line[0] == '1')
		{
			if (ft_strchr(line, '1') != 0)
			{
				ft_map(line, strct, line_nbr);
				line_nbr++;
			}
		}
		free(line);
	}
	if (ft_strchr(line, '1') != 0)
	{
		ft_map(line, strct, line_nbr);
		line_nbr++;
	}
	close(strct->fd);
	free(line);
	ft_map_is_valid(strct);
	ft_get_direction(strct);
	return (0);
}
