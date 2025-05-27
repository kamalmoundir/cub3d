/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:57:19 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/22 17:31:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>
#include "game.h"
#include "ray.h"
#include "utils.h"
#include "player.h"
#include "render.h"
#include "mlx_wrapper.h"
#include "map.h"
#include "debug.h"

static bool validate_args(int argc, char **argv);
static void run_game(t_game *game);
static int game_loop(t_game *game);
static int handle_init_error(t_game *game);

int main(int argc, char **argv)
{
    t_game game;
    
    if (!validate_args(argc, argv))
        return (EXIT_FAILURE);
    
    ft_memset(&game, 0, sizeof(t_game));
    if (!init_game_with_file(&game, argv[1]))
        return (handle_init_error(&game));
    // debug_game_state(&game);
    run_game(&game);
    cleanup_game(&game);
    return (EXIT_SUCCESS);
}

static bool validate_args(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_dprintf(STDERR_FILENO, "Usage: %s <map_file.cub>\n", argv[0]);
        return (false);
    }
    return (true);
}

static void run_game(t_game *game)
{
    mlx_hook(game->mlx.win_ptr, 2, 1L<<0, key_press, game);
    mlx_hook(game->mlx.win_ptr, 3, 1L<<1, key_release, game);
    mlx_hook(game->mlx.win_ptr, 17, 0, close_window, game);
    mlx_loop_hook(game->mlx.mlx_ptr, game_loop, game);
    mlx_loop(game->mlx.mlx_ptr);
}

static int game_loop(t_game *game)
{
    if (!game->running)
    {
        mlx_loop_end(game->mlx.mlx_ptr);
        return (1);
    }
    update_player(game);
    render_frame(game);
    return (0);
}

static int handle_init_error(t_game *game)
{
    cleanup_game(game);
    ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
    return (EXIT_FAILURE);
}