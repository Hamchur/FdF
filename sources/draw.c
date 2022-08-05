/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:13:00 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 16:54:10 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	max_unsigned(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return (x);
	else
		return (y);
}

static void	line_draw(t_dot a, t_dot b, t_mlx *mlx, int color)
{
	float	step_x;
	float	step_y;
	float	max;

	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = max_unsigned(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)a.x != (int)b.x)
	{
		mlx_pixel_put(mlx->id, mlx->id_win, (int)a.x, (int)a.y, color);
		a.x += step_x;
		a.y += step_y;
	}
}

static void	dot_convert(t_dot a, t_dot b, t_mlx *mlx)
{
	int	colour;

	if (a.z > 1 || b.z > 1)
		colour = 0xe80c0c;
	else if (a.z < 1 || b.z < 1)
		colour = 0x2b5999;
	else
		colour = 0xFFFFFF;
	threed(&a, mlx);
	threed(&b, mlx);
	line_draw(a, b, mlx, colour);
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->y_max)
	{
		x = 0;
		while (x < mlx->map->x_max)
		{
			if ((y + 1) < mlx->map->y_max)
				dot_convert(mlx->map->dot[y][x], mlx->map->dot[y + 1][x], mlx);
			if ((x + 1) < mlx->map->x_max)
				dot_convert(mlx->map->dot[y][x], mlx->map->dot[y][x + 1], mlx);
			x++;
		}
		y++;
	}
}
