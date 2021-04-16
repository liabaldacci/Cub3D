/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:40:05 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/15 22:31:58 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			ft_check_argument(t_vars *strct, char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len <= 4 || ft_strncmp(s + (len - 4), ".cub", 4) != 0)
		ft_errors(strct, 1);
	return (0);
}

int			ft_check_args(t_vars *strct, int argc, char **argv)
{
	if (argc <= 1)
		ft_errors(strct, 2);
	else if (argc == 2)
	{
		ft_check_argument(strct, argv[1]);
		strct->map_path = argv[1];
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[1], "--save", 6) != 0)
			ft_errors(strct, 3);
		strct->map_path = argv[2];
		return (0);
	}
	else
		ft_errors(strct, 4);
	return (0);
}
