/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/05/21 13:21:35 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif