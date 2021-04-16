/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:46:53 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/15 22:51:15 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int 		ft_split_number(char *str,int i, char **number)
{
	int		len_number;
	int		j;

	len_number = 0;
	while ((str[i] == ' ' || str[i] == ',') && str[i] != '\0')
		i++;
	j = i;
	while ((str[i++] != ' ' && str[i] != ',') && str[i] != '\0')
		len_number++;
	*number = ft_substr(str, j, len_number + 1);
	return (i);
}

int			ft_validate_number(char *number)
{
	int		i;

	i = 0;
	while (number[i] != '\0')
	{
		if (ft_isdigit(number[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		 	ft_colors(char *str, t_vars *strct) {
	char	*number;
	int		nbr;
	int		i;
	int		RGB;
		
	i = 1;
	RGB = 0;
	while (RGB < 3)
	{
		i = ft_split_number(str, i, &number);
		if (ft_validate_number(number) < 0)
		{
			free(number);
			ft_errors(strct, 6);
		}
		nbr = ft_atoi(number);
		if (nbr < 0 || nbr > 255)
		{
			free(number);
			ft_errors(strct, 6);
		}
		if (str[0] == 'C')
		{
			if (RGB == 0)
				strct->R_ceiling = nbr;
			else if (RGB == 1)
				strct->G_ceiling = nbr;
			else if (RGB == 2)
				strct->B_ceiling = nbr;
		}
		else
		{
			if (RGB == 0)
				strct->R_floor = nbr;
			else if (RGB == 1)
				strct->G_floor = nbr;
			else if (RGB == 2)
				strct->B_floor = nbr;
		}
		RGB++;
		free(number);
	}
	return (0);
}
