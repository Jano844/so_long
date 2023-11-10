/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:18:35 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/10 17:54:31 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_Mlx_42 *lib, t_images *image)
{
	image->xpm = mlx_load_xpm42("./textures/stone_block.xpm42");
	image->bg = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
	image->xpm = mlx_load_xpm42("./textures/bedrock.xpm42");
	image->wall = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
	image->xpm = mlx_load_xpm42("./textures/steve.xpm42");
	image->player = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
	image->xpm = mlx_load_xpm42("./textures/diamonds.xpm42");
	image->c = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
	image->xpm = mlx_load_xpm42("./textures/türee.xpm42");
	image->exit = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
	image->xpm = mlx_load_xpm42("./textures/zombie.xpm42");
	image->zombie = mlx_texture_to_image(lib->mlx, &image->xpm->texture);
	mlx_delete_xpm42(image->xpm);
}

void	imu_player(t_Mlx_42 lib, t_images img, int a[2])
{
	if (mlx_image_to_window(lib.mlx, img.player, a[1] * 32, a[0] * 32) < 0)
		error();
}

void	imu_zombie(t_Mlx_42 lib, t_images img, int a[2])
{
	if (mlx_image_to_window(lib.mlx, img.zombie, a[1] * 32, a[0] * 32) < 0)
		error();
}

void	init_map_utils(t_Mlx_42 lib, t_images img, t_map *map, int a[2])
{
	if (map->map[a[0]][a[1]] == '1')
		if (mlx_image_to_window(lib.mlx, img.wall, a[1] * 32, a[0] * 32) < 0)
			error();
	if (map->map[a[0]][a[1]] == '0')
		if (mlx_image_to_window(lib.mlx, img.bg, a[1] * 32, a[0] * 32) < 0)
			error();
	if (map->map[a[0]][a[1]] == 'E')
		if (mlx_image_to_window(lib.mlx, img.exit, a[1] * 32, a[0] * 32) < 0)
			error();
	if (map->map[a[0]][a[1]] == 'X')
		imu_zombie(lib, img, a);
	if (map->map[a[0]][a[1]] == 'C')
	{
		if (mlx_image_to_window(lib.mlx, img.c, a[1] * 32, a[0] * 32) < 0)
			error();
	}
	if (map->map[a[0]][a[1]] == 'P')
		imu_player(lib, img, a);
}

void	init_map(t_Mlx_42 lib, t_images img, t_map *map)
{
	int		arr[2];
	char	*temp;

	arr[0] = 0;
	arr[1] = 0;
	while (map->map[arr[0]] != NULL)
	{
		while (map->map[arr[0]][arr[1]] != '\0')
		{
			init_map_utils(lib, img, map, arr);
			arr[1]++;
		}
		arr[1] = 0;
		arr[0]++;
	}
	temp = ft_itoa(lib.counter);
	mlx_put_string(lib.mlx, temp, 10, 5);
	free(temp);
}
