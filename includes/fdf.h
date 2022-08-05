/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:47:07 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 16:00:21 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
}				t_dot;

typedef struct s_map
{
	int			x_max;
	int			y_max;
	t_dot		**dot;
}				t_map;

typedef struct s_mlx
{
	void		*id;
	void		*id_win;
	int			win_x;
	int			win_y;
	int			zoom;
	t_map		*map;
}				t_mlx;

void	threed(t_dot *dot, t_mlx *mlx);
void	draw(t_mlx *mlx);
void	free_map(void **map);
void	map_fill(char *map_path, t_map *map);
void	map_init(char *map_path, t_map *map);
void	mlx_global_init(t_mlx *mlx);

#endif
