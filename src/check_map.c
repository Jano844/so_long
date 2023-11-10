/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:39:29 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 18:16:15 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_e_p(t_map *map, int i, int j)
{
	map->collectible_num = 0;
	while (map->map[j] != NULL)
	{
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
			}
			if (map->map[j][i] == 'X')
			{
				map->zombie_x = i;
				map->zombie_y = j;
			}
			if (map->map[j][i] == 'C')
				map->collectible_num += 1;
			i++;
		}
		i = 0;
		j++;
	}
}

int	check_map(t_map *map, int j, int i)
{
	map->e = 0;
	map->p = 0;
	map->x = 0;
	while (map->map[j] != NULL)
	{
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'E')
				map->e += 1;
			if (map->map[j][i] == 'P')
				map->p += 1;
			if (map->map[j][i] == 'X')
				map->x += 1;
			if (map->map[j][i] != '0' && map->map[j][i] != '1'
				&& map->map[j][i] != 'P' && map->map[j][i] != 'E'
				&& map->map[j][i] != 'X' && map->map[j][i] != 'C'
				&& map ->map[j][i] != '\n')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_path_check(t_map *map, size_t x, size_t y)
{
	if (map->map[y][x] == 'C')
		map->c--;
	if (map->map[y + 1][x] == 'E' || map->map[y][x + 1] == 'E'
		|| map->map[y - 1][x] == 'E' || map->map[y][x - 1] == 'E')
		map->e--;
	map->map[y][x] = '1';
	if (map->map[y + 1][x] != '1')
		map->c = ft_path_check(map, x, y + 1);
	if (map->map[y][x + 1] != '1')
		map->c = ft_path_check(map, x + 1, y);
	if (map->map[y - 1][x] != '1')
		map->c = ft_path_check(map, x, y - 1);
	if (map->map[y][x - 1] != '1')
		map->c = ft_path_check(map, x - 1, y);
	return (map->c);
}

int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		if (map->map[j][0] != '1' || map->map[j][map->line_len - 2] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (j < map->line_len - 2)
	{
		if (map->map[0][j] != '1' || map->map[map->line - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	checker(t_map *map)
{
	if (check_wall(map) == 1)
		return (1);
	if (check_map(map, 0, 0) == 1)
		return (1);
	if (map->e != 1 || map->p != 1 || map->collectible_num < 1)
		return (1);
	map->c = map->collectible_num;
	ft_path_check(map, map->player_x, map->player_y);
	if (map->c != 0 || map->e != 0)
		return (1);
	return (0);
}
