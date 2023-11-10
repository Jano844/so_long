/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:37:30 by jsanger           #+#    #+#             */
/*   Updated: 2023/09/25 19:38:00 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ftpf_putchar_fd(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (i);
}

// int main()
// {
//     char *c;
//     int fd;
//     fd = 1;
//     c = "abcd";
//     ft_putstr_fd(c, fd);
// 	return 0;
// }
