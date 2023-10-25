/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:50:30 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/12 16:35:51 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *start, char *buff);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char	*str);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t count, size_t size);
#endif
