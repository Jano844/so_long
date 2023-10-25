/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:47:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/18 14:04:48 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_len(char *file_to_open)
{
	char	*first_line;
	char	*line;
	int		len;
	int		fd;

	len = 0;
	fd = open(file_to_open, O_RDONLY, 0777);

	first_line = get_next_line(fd);
	line = first_line;
	len = ft_strlen(first_line);
	while (line != NULL)
	{
		if ((size_t)len != ft_strlen(line))
			exit (1);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_strlen(first_line));
}

int	get_lines(char *file_to_open)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

char	**ft_get_map(char *file_to_open, struct map *gtl)
{
	int		fd;
	int		i;
	char	**map;

	gtl->line = get_lines(file_to_open);
	gtl->line_len = get_line_len(file_to_open);
	i = 0;
	fd = open(file_to_open, O_RDONLY, 0777);
	map = malloc((gtl->line + 1) * sizeof(char *));
	while (i < gtl->line)
	{
		map[i] = ft_substr(get_next_line(fd), 0 ,gtl->line_len);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

