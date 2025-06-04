/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:47:40 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/04 13:46:23 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <X11/keysym.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->player.move_forward = 1;
	else if (keycode == XK_a)
		game->player.move_sideways = -1;
	else if (keycode == XK_s)
		game->player.move_forward = -1;
	else if (keycode == XK_d)
		game->player.move_sideways = 1;
	else if (keycode == XK_Left)
		game->player.rotate = -1;
	else if (keycode == XK_Right)
		game->player.rotate = 1;
	else if (keycode == XK_Escape)
	{
		ft_printf("Closing window\n");
		cleanup_game(game);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s)
		game->player.move_forward = 0;
	else if (keycode == XK_a || keycode == XK_d)
		game->player.move_sideways = 0;
	else if (keycode == XK_Left || keycode == XK_Right)
		game->player.rotate = 0;
	return (0);
}

int	close_window(t_game *game)
{
	ft_printf("Closing window\n");
	game->running = 0;
	cleanup_game(game);
	exit(0);
	return (0);
}
