#ifndef UTILS_H
# define UTILS_H

// memory_utils.h
void	safe_free(void **ptr);

// error_utils.h
void	set_error(t_error *error, const char *message, int code);
void	display_error(t_game *game);
void	clear_error(t_error *error);

#endif