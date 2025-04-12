/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:38:54 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 18:54:31 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(int n, int fd)
{
	char	rest;

	if (n > 0)
	{
		recursion(n / 10, fd);
		rest = (n % 10) + '0';
		write(fd, &rest, sizeof(char));
	}
}

/// @brief Envía el número ’n’ al file descriptor dado.
/// @param n: El número que enviar.
/// @param fd: El file descriptor sobre el que escribir.
void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;

	i = 0;
	if (n == 0)
		write(fd, "0", sizeof(char));
	else if (n < 0)
	{
		write(fd, "-", sizeof(char));
		if (n == -2147483648)
			write(fd, "2147483648", 10 * sizeof(char));
		else
		{
			n = -n;
			recursion(n, fd);
		}
	}
	else
		recursion(n, fd);
}
