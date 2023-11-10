/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:52:29 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/12 16:35:29 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*move_to_start(char	*start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i++;
	new_buff = (char *)ft_calloc_gnl(1 + ft_strlen_gnl(start) - i, sizeof(char));
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	free(start);
	return (new_buff);
}

static char	*ft_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] != '\0' && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)ft_calloc_gnl(1 + i, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			read_bites;
	static char	*stat_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bites = 1;
	temp = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (!(ft_strchr_gnl(stat_str, '\n')) && read_bites != 0)
	{
		read_bites = read(fd, temp, BUFFER_SIZE);
		if (read_bites == -1)
			return (free(temp), free(stat_str), stat_str = NULL, NULL);
		temp[read_bites] = '\0';
		stat_str = ft_strjoin_gnl(stat_str, temp);
		if (!(stat_str))
			return (free(temp), NULL);
	}
	free(temp);
	temp = ft_line(stat_str);
	stat_str = move_to_start(stat_str);
	return (temp);
}

// int	main(void)
// {
// 	int			fd;
// 	char		*line;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	return (0);
// }
