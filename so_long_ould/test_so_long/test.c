/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:25:07 by jsanger           #+#    #+#             */
/*   Updated: 2023/10/12 04:26:25 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <mlx.h>

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int x;
    int y;
    int rect_width;
    int rect_height;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_rectangle(t_data *data) {
    int x, y, z;

    z = 1;
    for (y = data->y; y < data->y + data->rect_height; y++) {
        z++;
        for (x = data->x; x < data->x + data->rect_width - z/25; x++) {
            z++;
            my_mlx_pixel_put(data, x, y, 0x00FF0000); // Red color (ARGB: 0, 255, 0, 0)
        }
    }
}

int key_hook(int keycode, t_data *data) {
    if (keycode == 53) { // ESC key
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    } else if (keycode == 124) { // Right arrow key
        data->x += 10;
    } else if (keycode == 123) { // Left arrow key
        data->x -= 10;
    } else if (keycode == 126) { // Up arrow key
        data->y -= 10;
    } else if (keycode == 125) { // Down arrow key
        data->y += 10;
    }
    mlx_clear_window(data->mlx, data->win);
    draw_rectangle(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1000, 600, "MiniLibX Example");

    data.img = mlx_new_image(data.mlx, 1000, 600);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    data.x = 200; // Initial x-coordinate of the rectangle
    data.y = 200; // Initial y-coordinate of the rectangle
    data.rect_width = 100; // Width of the rectangle
    data.rect_height = 100; // Height of the rectangle

    draw_rectangle(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
    mlx_loop(data.mlx);
    return (0);
}
