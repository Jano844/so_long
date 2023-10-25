/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:32:16 by jsanger           #+#    #+#             */
/*   Updated: 2023/09/25 19:35:59 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ftpf_putchar_fd(char c, int fd);
int		ftpf_putchar(char c);
int		ftpf_putnbr_fd(int n, int fd);
int		ftpf_putstr_fd(char *s, int fd);
int		ftpf_put_unsigned_nbr_fd(unsigned int n, int fd);
int		ftpf_puthex_fd(size_t n, int fd, char c);
int		ftpf_putadress(size_t adress);
int		ftpf_num_to_hex(size_t n, int fd, char c, int i);

#endif
