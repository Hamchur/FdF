/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:16:48 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/25 17:17:05 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(void **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	get_map_size(t_map *map, int fd)
{
	char		*line;
	char		**clean;
	char		**tmp;

	map->y_max = 0;
	map->x_max = 0;
	line = get_next_line(fd);
	clean = ft_split(line, ' ');
	tmp = clean;
	while (*clean && **clean != '\n')
	{
		map->x_max++;
		++clean;
	}
	clean = tmp;
	free_map((void **)clean);
	while (line)
	{
		map->y_max++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

static void	alloc_map(t_map *map)
{
	int	i;

	i = -1;
	map->dot = malloc(sizeof(t_dot *) * map->y_max);
	if (map->dot == NULL)
		exit(EXIT_FAILURE);
	while (++i < map->y_max)
	{
		map->dot[i] = malloc(sizeof(t_dot) * map->x_max);
		if (map->dot[i] == NULL)
			exit(EXIT_FAILURE);
	}
}

void	map_init(char *map_path, t_map	*map)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	get_map_size(map, fd);
	close(fd);
	alloc_map(map);
}
