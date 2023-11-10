/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:24:44 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 23:34:55 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include "../includes/libft/libft.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/get_next_line_so/get_next_line.h"
# include "../includes/MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int		line_len;
	int		line;
	char	**map;
	int		exit_num;
	int		collectible_num;
	int		player_x;
	int		player_y;
	int		zombie_x;
	int		zombie_y;
	int		p;
	int		c;
	int		e;
	int		x;
}		t_map;

typedef struct s_images
{
	xpm_t		*xpm;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*bg;
	mlx_image_t	*c;
	mlx_image_t	*exit;
	mlx_image_t	*zombie;
}		t_images;

typedef struct s_Mlx_42
{
	int				counter;
	mlx_image_t		*image;
	mlx_t			*mlx;
	t_map			*map_data;
	t_images		*images;
}		t_Mlx_42;

// error
void		error(void);
void		map_error(void);
int			invalid_map(t_map *map, char *file_to_open);

// get_map

void		get_map(char *file_to_open, t_map *map);
void		check_line_len(char *file_to_open, int len_per_line);
int			get_line_len(char *file_to_open);
int			count_lines(char *file_to_open);
void		ft_free_map(t_map *map);	

// get_map_test
// int			count_lines(char *file_to_open);

// move
void		ft_move_zombie(t_Mlx_42 *lib, int tempx, int tempy);
void		zombie(t_Mlx_42 *l);
void		check_game_state(t_Mlx_42 *lib, int *is_wall, int tempx, int tempy);
void		update_player_pos(t_Mlx_42 *lib, int is_wall, int tempx, int tempy);
void		ft_move(t_Mlx_42 *minilibx, int tempx, int tempy);

// so_long
void		ft_mv_counter(t_Mlx_42 *minilibx);

// init
void		init_map(t_Mlx_42 lib, t_images img, t_map *map);
void		init_sprites(t_Mlx_42 *lib, t_images *image);
void		init_map_utils(t_Mlx_42 lib, t_images img, t_map *map, int a[2]);
void		imu_player(t_Mlx_42 lib, t_images img, int a[2]);
void		imu_zombie(t_Mlx_42 lib, t_images img, int a[2]);

void		init_e_p(t_map *map, int i, int j);

//checker
int			checker(t_map *map);
int			ft_path_check(t_map *map, size_t x, size_t y);
int			check_map(t_map *map, int j, int i);
int			check_wall(t_map *map);
#endif