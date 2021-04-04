/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:43:11 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/03 21:44:36 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double       ft_normalize_angle(double angle){
    double  remainder;

    if (angle > TWO_PI || angle < 0){
        remainder = fmod(angle, TWO_PI);
        angle = (angle < 0) ? (TWO_PI + remainder) : remainder;
    }
    return (angle);    
}