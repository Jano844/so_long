/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:17:33 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 22:39:09 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mv_counter(t_Mlx_42 *minilibx)
{
	char	*temp;

	temp = ft_itoa(minilibx->counter);
	mlx_image_to_window(minilibx->mlx, minilibx->images->wall, 0, 0);
	mlx_image_to_window(minilibx->mlx, minilibx->images->wall, 32, 0);
	if (minilibx->counter <= 9)
	{
		mlx_put_string(minilibx->mlx, temp, 10, 5);
	}
	else if (minilibx->counter <= 99)
	{
		mlx_put_string(minilibx->mlx, temp, 5, 5);
	}
	else
	{
		mlx_put_string(minilibx->mlx, temp, 0, 5);
	}
	free(temp);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_Mlx_42	*lib;

	lib = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(lib->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		lib->map_data->player_y -= 1;
		ft_move(lib, lib->map_data->player_x, lib->map_data->player_y + 1);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		lib->map_data->player_y += 1;
		ft_move(lib, lib->map_data->player_x, lib->map_data->player_y - 1);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		lib->map_data->player_x -= 1;
		ft_move(lib, lib->map_data->player_x + 1, lib->map_data->player_y);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		lib->map_data->player_x += 1;
		ft_move(lib, lib->map_data->player_x - 1, lib->map_data->player_y);
	}
}

void	main_to_long(t_map *map, t_Mlx_42 *lib, t_images *img)
{
	lib->mlx = mlx_init
		(32 * (map->line_len - 1), 32 * map->line, "MLX42", true);
	if (!lib->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		ft_free_map(map);
		exit (EXIT_FAILURE);
	}
	init_sprites(lib, img);
	init_map(*lib, *img, map);
}

int	main(int argc, char **argv)
{
	t_Mlx_42	lib;
	t_images	img;
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
		return (1);
	get_map(argv[1], map);
	init_e_p(map, 0, 0);
	if (invalid_map(map, argv[1]) == 1)
	{
		ft_free_map(map);
		exit(1);
	}
	main_to_long(map, &lib, &img);
	lib.map_data = map;
	lib.images = &img;
	lib.counter = 0;
	mlx_key_hook(lib.mlx, ft_hook, &lib);
	mlx_loop(lib.mlx);
	ft_free_map(map);
	mlx_terminate(lib.mlx);
	return (0);
}
