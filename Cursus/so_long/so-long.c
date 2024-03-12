/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by mmauchre          #+#    #+#             */
/*   Updated: 2024/02/24 15:44:03 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/max/42/Cursus/so_long/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>



#include <X11/X.h>
#include <X11/keysym.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width, height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");

    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "asphalt_resized.xpm", &width, &height);

    // Ajustez les coordonnées pour centrer l'image dans la fenêtre
    int x = (WINDOW_WIDTH - width) / 2;
    int y = (WINDOW_HEIGHT - height) / 2;

    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);

    mlx_loop(mlx_ptr);

    return (0);
}