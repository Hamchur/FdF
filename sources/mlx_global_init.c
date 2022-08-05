/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:20:14 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 17:20:21 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	window_init(t_mlx *mlx)
{
	mlx->id_win = mlx_new_window(mlx->id, mlx->win_y, mlx->win_x, "FDF");
}

void	mlx_global_init(t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		exit(1);
	mlx->win_y = 1080;
	mlx->win_x = 720;
	mlx->zoom = 20;
	window_init(mlx);
}
