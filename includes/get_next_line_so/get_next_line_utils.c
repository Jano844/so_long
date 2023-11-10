/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:49:28 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/12 16:34:56 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *start, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	i_buff;
	size_t	i_start;

	i_buff = ft_strlen_gnl(buff);
	i_start = ft_strlen_gnl(start);
	i = -1;
	if (!start)
	{
		start = (char *)ft_calloc_gnl(1, sizeof(char));
		if (!start)
			return (free(start), NULL);
	}
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(i_start + i_buff + 1);
	if (!ptr)
		return (free(ptr), free(start), NULL);
	while (++i < i_start)
		ptr[i] = start[i];
	i = -1;
	while (++i < i_buff + 1)
		ptr[i_start + i] = buff[i];
	return (free(start), ptr);
}

size_t	ft_strlen_gnl(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen_gnl(s);
		return (&s[i]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&s[i]);
	return (NULL);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (free(ptr), NULL);
	ft_bzero_gnl(ptr, size * count);
	return (ptr);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
