/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:11:07 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 00:32:39 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	map_error(void)
{
	printf("Error creating the map\n");
	exit(1);
}

int	invalid_map(t_map *map, char *file_to_open)
{
	if (checker(map) == 1)
	{
		printf("Error, Invalid Map\n");
		return (1);
	}
	ft_free_map(map);
	get_map(file_to_open, map);
	return (0);
}
