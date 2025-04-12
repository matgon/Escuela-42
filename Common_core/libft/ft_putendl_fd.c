/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:36:36 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 18:41:07 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Envía la string ’s’ al file descriptor dado,
///seguido de un salto de línea.
/// @param s: La string a enviar. 
/// @param fd: El file descriptor sobre el que escribir.
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], sizeof(char));
	write(fd, "\n", sizeof(char));
}
