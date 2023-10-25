/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:03:11 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/23 20:52:26 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(struct Mlx_win *win, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(win->mlx, win->win, win->img_wall, win->x, win->y);
			else if (map[i][j] == 'P')
			{
				win->x_player = j * 32;
				win->y_player = i * 32;
				mlx_put_image_to_window(win->mlx, win->win, win->img_player, win->x_player, win->y_player);
			}
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(win->mlx, win->win, win->img_collectable, win->x, win->y);
			else
				mlx_put_image_to_window(win->mlx, win->win, win->img_floor, win->x, win->y);
			j++;
			win->x += 32;
		}
		j = 0;
		win->x = 0;
		win->y += 32;
		i++;
	}
}


int key_hook(int keycode, struct Mlx_win *win)
{
	int	tempx;
	int	tempy;
	int is_wall;

	tempx = win->x_player;
	tempy = win->y_player;
	if (keycode == 53) { // ESC key
		mlx_destroy_window(win->mlx, win->win);
		ft_free_map(win->p_map);
		exit(0);
	} else if (keycode == 124) { // Right arrow key
		win->x_player += 32;
	} else if (keycode == 123) { // Left arrow key
		win->x_player -= 32;
	} else if (keycode == 126) { // Up arrow key
		win->y_player -= 32;
	} else if (keycode == 125) { // Down arrow key
		win->y_player += 32;
	}
	is_wall = 0;
	if (win->p_map[win->y_player / 32][win->x_player / 32] == '1')
	{
		is_wall = 1;
		win->x_player = tempx;
		win->y_player = tempy;
	}
	if (!is_wall)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->img_floor, tempx, tempy);
		mlx_put_image_to_window(win->mlx, win->win, win->img_player, win->x_player, win->y_player);
	}
	return (0);
}

void	get_sprites(struct Mlx_win *win)
{
	win->relative_path = "./sprites/wall.xpm";
	win->img_wall = mlx_xpm_file_to_image(win->mlx, win->relative_path, &win->img_width, &win->img_height);
	if (win->img_wall == NULL)
		printf("Wall failed");

	win->relative_path = "./sprites/player.xpm";
	win->img_player = mlx_xpm_file_to_image(win->mlx, win->relative_path, &win->img_width, &win->img_height);
	if (win->img_player == NULL)
		printf("Player failed");

	win->relative_path = "./sprites/floor.xpm";
	win->img_floor = mlx_xpm_file_to_image(win->mlx, win->relative_path, &win->img_width, &win->img_height);
	if (win->img_player == NULL)
		printf("Player failed");

	win->relative_path = "./sprites/collectable.xpm";
	win->img_collectable = mlx_xpm_file_to_image(win->mlx, win->relative_path, &win->img_width, &win->img_height);
	if (win->img_player == NULL)
		printf("Player failed");
}

int	main(int argc, char **argv)
{
	struct	Mlx_win	win;
	struct	map	gnl;
	if (argc != 2)
		return (0);

	win.p_map = ft_get_map(argv[1], &gnl);
	win.x = 0;
	win.y = 0;

	win.mlx = mlx_init();

	// create sprites

	get_sprites(&win);
	win.win = mlx_new_window(win.mlx, (gnl.line_len - 1) * 32, gnl.line * 32, "Image Window");
	load_image(&win, win.p_map);
	mlx_hook(win.win, 2, 1L << 0, key_hook, &win);
	mlx_loop(win.mlx);
	return (0);
}