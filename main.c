/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:16 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/26 19:36:52 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	erorrs(char *reason)
{
	ft_putendl(reason);
	return (1);
}

void	free_all(t_mlx *mlx)
{
	free_map((void **)mlx->map->dot);
	free(mlx->map);
	free(mlx->id);
}

int	key(int num, t_mlx *mlx)
{
	printf("%d\n", num);
	if (num == 69)
		mlx->zoom += 2;
	if (num == 78)
		mlx->zoom -= 2;
	if (num == 123)
		mlx->win_x -= 10;
	if (num == 126)
		mlx->win_y -= 10;
	if (num == 124)
		mlx->win_x += 10;
	if (num == 125)
		mlx->win_y += 10;
	if (num == 53)
		exit(0);
	mlx_clear_window(mlx->id, mlx->id_win);
	draw(mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	float	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd <= -1)
		return (erorrs("Error: not enough or many arguments"));
	close(fd);
	mlx.map = malloc(sizeof(t_map));
	if (mlx.map == NULL)
		return (1);
	mlx_global_init(&mlx);
	map_init(argv[1], mlx.map);
	map_fill(argv[1], mlx.map);
	draw(&mlx);
	mlx_hook(mlx.id_win, 2, 0, &key, &mlx);
	mlx_loop(mlx.id);
	return (0);
}
