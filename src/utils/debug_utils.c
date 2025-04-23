/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:01:38 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/23 22:01:38 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "game.h"

void	print_grid(int **grid, int height, int width)
{
	int i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d ", grid[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	debug_render(t_game *game)
{
	int x, y;
	int *buffer = (int *)game->mlx.img_data;

	// Fill the entire screen with a test pattern
	for (y = 0; y < game->mlx.height; y++)
	{
		for (x = 0; x < game->mlx.width; x++)
		{
		    // Create a colorful test pattern
		    buffer[y * game->mlx.width + x] = ((x ^ y) & 255) * 0x10101;
		}	
	}
	// Draw a red square in the middle
	int center_x = game->mlx.width / 2;
	int center_y = game->mlx.height / 2;
	for (y = center_y - 50; y < center_y + 50; y++)
	{
		for (x = center_x - 50; x < center_x + 50; x++)
		{
			if (x >= 0 && x < game->mlx.width && y >= 0 && y < game->mlx.height)
				buffer[y * game->mlx.width + x] = 0xFF0000;
		}
	}
	// Put the image to the window
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, 
                           game->mlx.img_ptr, 0, 0);
}