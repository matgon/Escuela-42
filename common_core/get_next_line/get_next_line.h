/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:54:12 by matgonza          #+#    #+#             */
/*   Updated: 2025/11/15 22:12:23 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*strjoin_gnl(char *s1, char *s2);
char	*strdup_gnl(char *s);
char	*substr_gnl(char *s, int start, int len);
int		strlen_gnl(char *s);
int		check_nl(char *s);

#endif
