/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:26:21 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/16 21:40:38 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			ft_texture_letters(char *line, int i)
{
	if (((line[i] == 'N' || line[i] == 'S') && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		|| (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		|| (line[i] == 'S' && line[i + 1] == ' '))
		return (1);
	return (0);
}

void		ft_map_size(t_vars *strct, char *line)
{
	int		i;
	int		len;

	i = 0;
	if (ft_strchr(line, '1') != 0)
	{
		if (ft_strlen(line) > strct->map_width)
			strct->map_width = ft_strlen(line);
		strct->map_height++;
	}
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == '2')
			strct->num_of_sprites++;
		i++;
	}
	
}

int			ft_eval_line(char *line, t_vars *strct)
{
	int		i;

	i = 0;
	if ((line[i] == 'R') && line[i + 1] == ' ')
		ft_resolution(line, strct);
	else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		ft_colors(line, strct);
	else if (ft_texture_letters(line, i))
		ft_textures_path(line, strct);
	else if (line[i] >= 8 && line[i] <= 13)
		return (0);
	else if (ft_strncmp(line, "\000", 5) == 0)
		return (0);
	else if (line[i] == ' ' || line[i] == '1')
		ft_map_size(strct, line);
	else
		ft_errors(strct, 8);
	return (0);
}

int			ft_check_input(t_vars *strct)
{
	char	*line;
	int		i;

	line = NULL;
	strct->fd = open(strct->map_path, O_RDONLY);
	if (strct->fd < 0)
		ft_errors(strct, 1);
	while (get_next_line(strct->fd, &line) == 1)
	{
		strct->line = &line;
		ft_eval_line(line, strct);
		free(line);
		line = NULL;
	}
	if (line)
		strct->line = &line;
	ft_eval_line(line, strct);
	close(strct->fd);
	free(line);
	line = NULL;
	return (0);
}
