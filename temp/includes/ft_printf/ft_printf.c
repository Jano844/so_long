/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:07:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/13 20:06:07 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(va_list args, char format)
{
	int		ret;
	void	*str;

	ret = 0;
	if (format == 'c')
		ret += ftpf_putchar_fd((char)va_arg(args, int), 1);
	else if (format == 'i' || format == 'd')
		ret += ftpf_putnbr_fd(va_arg(args, int), 1);
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str != NULL)
			ret += ftpf_putstr_fd((char *)str, 1);
		else
			ret += ftpf_putstr_fd("(null)", 1);
	}
	else if (format == 'u')
		ret += ftpf_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
	else if (format == '%')
		ret += ftpf_putchar_fd(format, 1);
	else if (format == 'x' || format == 'X')
		ret += ftpf_puthex_fd(va_arg(args, unsigned int), 1, format);
	else if (format == 'p')
		ret += ftpf_putadress((size_t)&*va_arg(args, char *));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		returnval;
	int		i;
	int		check;
	va_list	args;

	i = -1;
	returnval = 0;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			check = ft_check_arg(args, format[++i]);
			returnval += check;
		}
		else
		{
			check = ftpf_putchar_fd(format[i], 1);
			returnval++;
		}
		if (check == -1)
			return (-1);
	}
	va_end(args);
	return (returnval);
}

