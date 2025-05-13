#include <stdlib.h>
#include "utils.h"
#include "types.h"
#include "game.h"

void	set_error(t_error *error, const char *message, int code)
{
	if (error->message != NULL)
		return ;
	error->message = ft_strdup(message);
	error->code = code;
	ft_dprintf(STDERR_FILENO, "[ERROR %d]: %s\n", code, message);
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
		ft_dprintf(STDERR_FILENO, "Error [%d]: %s\n", game->error.code, game->error.message);
}

void	clear_error(t_error *error)
{
	if (error->message)
		safe_free((void **)&error->message);
	error->code = 0;
}
