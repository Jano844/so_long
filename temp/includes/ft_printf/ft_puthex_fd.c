/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:51:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/09/25 19:38:35 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_puthex_fd(size_t n, int fd, char c)
{
	int	i;

	i = 0;
	return (ftpf_num_to_hex(n, fd, c, i));
}

int	ftpf_num_to_hex(size_t n, int fd, char c, int i)
{
	if (n <= 9)
	{
		if (ftpf_putchar_fd(n + '0', fd) == -1)
			return (-1);
		i = 1;
	}
	else if (n >= 10 && n <= 15)
	{
		if (c == 'x')
			i = ftpf_putchar_fd(n - 10 + 'a', fd);
		else
			i = ftpf_putchar_fd(n - 10 + 'A', fd);
		if (i == -1)
			return (-1);
		i = 1;
	}
	else
	{
		i = ftpf_puthex_fd(n / 16, fd, c);
		if (i == -1)
			return (-1);
		i += ftpf_puthex_fd(n % 16, fd, c);
	}
	return (i);
}
