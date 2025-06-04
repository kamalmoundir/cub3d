/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:55:01 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/04 12:41:21 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void	set_error(t_error *error, const char *message, int code)
{
	if (error->message != NULL)
		return ;
	error->message = ft_strdup(message);
	error->code = code;
	ft_dprintf(STDERR_FILENO, "[ERROR %d]:\n %s\n", code, message);
}

void	handle_critical_error(t_game *game)
{
	if (game->error.code == EXIT_FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Critical error encountered: %s\n",
			game->error.message);
		game->running = false;
	}
}

void	display_error(t_game *game)
{
	if (game->error.message)
		ft_dprintf(STDERR_FILENO, "Error [%d]:\n %s\n", game->error.code,
			game->error.message);
}

void	clear_error(t_error *error)
{
	if (error->message)
		safe_free((void **)&error->message);
	error->code = 0;
}
