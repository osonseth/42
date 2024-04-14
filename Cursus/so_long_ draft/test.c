/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:17:14 by max               #+#    #+#             */
/*   Updated: 2024/04/14 02:03:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_game(t_mlx *mlx)
{
    int i = 0;
    int j;

  

    while (i < 9) // len du nombre de ligne
    {
        j = 0;
        while (j < 13) // len d'une ligne
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx->mlx, mlx->windows, mlx->image_aste, j * 64, i * 64);
            if (map[i][j] == '0')
                mlx_put_image_to_window(mlx->mlx, mlx->windows, mlx->image_space, j * 64, i * 64);
            if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx->mlx, mlx->windows, mlx->image_astro, j * 64, i * 64);
            if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx->mlx, mlx->windows, mlx->image_ship, j * 64, i * 64);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx->mlx, mlx->windows, mlx->image_exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

int main()
{
   

    

    

    display_game(&mlx);

    mlx_loop(mlx.mlx);

    return 0;
}
