/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_load_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:33:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/16 23:39:56 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image_at_coordinates(void *mlx, void *win, void *img, int x, int y)
{
    mlx_put_image_to_window(mlx, win, img, x, y);
}

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    char *relative_path = "./player.xpm"; // Replace with your XPM file
    int img_width;
    int img_height;

    mlx = mlx_init();
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

    printf("%d/n", img_height);

    win = mlx_new_window(mlx, 400, 400, "Image Window");

    int x = 0; // Example x coordinate
    int y = 0;  // Example y coordinate

    put_image_at_coordinates(mlx, win, img, x, y);

    mlx_loop(mlx);

    return 0;
}

