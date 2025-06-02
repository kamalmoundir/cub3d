/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:16:21 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 18:03:09 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "types.h"

char	*get_next_line(int fd);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size);
size_t	ft_strlcat_gnl(char *dst, char *src, size_t size);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_get_line(int fd, char *line);
char	**array_map(int fd, int size);

#endif