/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 02:25:44 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/23 20:49:46 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/mlx/mlx.h"
# include "../includes/get_next_line_so/get_next_line.h"
# include "../includes/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>


struct Mlx_win
{
	void *mlx;
	void *win;
	void *img_wall;
	void *img_player;
	void *img_floor;
	void *img_collectable;
	char *relative_path;
	int	img_width;
	int	img_height;
	int x;
	int y;
	int x_player;
	int y_player;
	char **p_map;
};

struct map
{
	int	line_len;
	int	line;
};

int		get_line_len(char *file_to_open);
int		get_lines(char *file_to_open);
char	**ft_get_map(char *file_to_open, struct map *gtl);
void	ft_free_map(char **map);

#endif