/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:48 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 17:07:57 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	threed(t_dot *dot, t_mlx *mlx)
{
	dot->x *= mlx->zoom;
	dot->y *= mlx->zoom;
	dot->z *= 1;
	dot->x = (dot->x - dot->y) * cos(1);
	dot->y = (dot->x + dot->y) * sin(1) - dot->z;
	dot->x += mlx->win_x - 250;
	dot->y += mlx->win_y - 850;
}
