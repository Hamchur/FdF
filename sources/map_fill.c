/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:14:29 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 17:15:55 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_fill(char *map_path, t_map *map)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**clean;

	fd = open(map_path, O_RDONLY);
	y = 0;
	while (y < map->y_max)
	{
		line = get_next_line(fd);
		clean = ft_split(line, ' ');
		x = 0;
		while (x < map->x_max)
		{
			map->dot[y][x].z = ft_atoi(clean[x]);
			map->dot[y][x].x = x;
			map->dot[y][x].y = y;
			x++;
		}
		y++;
		free(line);
		free_map((void **)clean);
	}
	close(fd);
}
