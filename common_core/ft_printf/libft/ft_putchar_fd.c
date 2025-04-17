/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:29:08 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 18:32:47 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Envía el carácter ’c’ al file descriptor
/// especificado.
/// @param c: El carácter a enviar.
/// @param fd: El file descriptor sobre el que escribir.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
