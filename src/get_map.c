/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:41:47 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 00:21:24 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(map->map[i]);
		i--;
	}
	free(map->map);
}

int	count_lines(char *file_to_open)
{
	int		count;
	int		fd;
	char	*line;

	if (ft_strncmp(file_to_open + (ft_strlen(file_to_open) - 4), ".ber\0", 5))
		map_error();
	count = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	if (fd < 0)
		map_error();
	line = get_next_line(fd);
	if (line == NULL)
		map_error();
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	free(line);
	return (count);
}

int	get_line_len(char *file_to_open)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	if (fd < 0)
		map_error();
	line = get_next_line(fd);
	while (line[count] != '\0')
		count++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	check_line_len(char *file_to_open, int len_per_line)
{
	int		j;
	char	*line;
	int		fd;

	j = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	if (fd < 0)
		map_error();
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[j] != '\0')
			j++;
		free(line);
		if (j != len_per_line)
			map_error();
		line = get_next_line(fd);
		j = 0;
	}
	close(fd);
}

void	get_map(char *file_to_open, t_map *map)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	if (fd < 0)
		map_error();
	map->line = count_lines(file_to_open);
	map->line_len = get_line_len(file_to_open);
	check_line_len(file_to_open, map->line_len);
	map->map = malloc((map->line + 1) * sizeof(char *));
	if (map->map == NULL)
		map_error();
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map->map[i] = temp;
		temp = get_next_line(fd);
		i++;
	}
	free(temp);
	close(fd);
	map->map[i] = NULL;
}
