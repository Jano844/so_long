/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:43 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 00:12:26 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_zombie(t_Mlx_42 *lib, int tempx, int tempy)
{
	int	is_wall;

	is_wall = 0;
	if (lib->map_data->map[lib->map_data->zombie_y][lib->map_data->zombie_x]
		!= '0' && lib->map_data->map[lib->map_data->zombie_y]
		[lib->map_data->zombie_x] != 'P')
	{
		is_wall = 1;
		lib->map_data->zombie_x = tempx;
		lib->map_data->zombie_y = tempy;
	}
	if (!is_wall)
	{
		lib->map_data->map[lib->map_data->zombie_y][lib->map_data->zombie_x]
			= 'X';
		lib->map_data->map[tempy][tempx] = '0';
		mlx_image_to_window(lib->mlx, lib->images->zombie,
			lib->map_data->zombie_x * 32, lib->map_data->zombie_y * 32);
		mlx_image_to_window
			(lib->mlx, lib->images->bg, tempx * 32, tempy * 32);
	}
}

void	zombie(t_Mlx_42 *l)
{
	int	random_number;

	srand(time(NULL));
	random_number = rand() % 4;
	if (random_number == 0)
	{
		l->map_data->zombie_y -= 1;
		ft_move_zombie(l, l->map_data->zombie_x, l->map_data->zombie_y + 1);
	}
	if (random_number == 1)
	{
		l->map_data->zombie_y += 1;
		ft_move_zombie(l, l->map_data->zombie_x, l->map_data->zombie_y - 1);
	}
	if (random_number == 2)
	{
		l->map_data->zombie_x += 1;
		ft_move_zombie(l, l->map_data->zombie_x -1, l->map_data->zombie_y);
	}
	if (random_number == 3)
	{
		l->map_data->zombie_x -= 1;
		ft_move_zombie(l, l->map_data->zombie_x +1, l->map_data->zombie_y);
	}
}

void	check_game_state(t_Mlx_42 *lib, int *is_wall, int tempx, int tempy)
{
	char	tile;

	tile = lib->map_data->map[lib->map_data->player_y][lib->map_data->player_x];
	if (tile == '1' || (tile == 'E' && lib->map_data->collectible_num != 0))
	{
		*is_wall = 1;
		lib->map_data->player_x = tempx;
		lib->map_data->player_y = tempy;
	}
	else if (tile == 'C')
	{
		lib->map_data->map[lib->map_data->player_y][lib->map_data->player_x]
			= '0';
		lib->map_data->collectible_num -= 1;
	}
	else if (tile == 'E' || tile == 'X')
		mlx_close_window(lib->mlx);
}

void	update_player_pos(t_Mlx_42 *lib, int is_wall, int tempx, int tempy)
{
	if (!is_wall)
	{
		lib->counter++;
		ft_mv_counter(lib);
		if (mlx_image_to_window
			(lib->mlx, lib->images->player, lib->map_data->player_x * 32
				, lib->map_data->player_y * 32) < 0)
			error();
		if (lib->map_data->map[tempy][tempx] != 'X')
		{
			if (mlx_image_to_window(lib->mlx, lib->images->bg
					, tempx * 32, tempy * 32) < 0)
				error();
		}
	}
}

void	ft_move(t_Mlx_42 *minilibx, int tempx, int tempy)
{
	int	is_wall;

	is_wall = 0;
	if (minilibx->map_data->x != 0)
		zombie(minilibx);
	check_game_state(minilibx, &is_wall, tempx, tempy);
	update_player_pos(minilibx, is_wall, tempx, tempy);
}
