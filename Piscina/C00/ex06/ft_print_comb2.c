/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C06.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:15:40 by matgon            #+#    #+#             */
/*   Updated: 2025/02/23 20:27:38 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_char(int first, int second)
{
	char	c[5];

	c[0] = (first / 10) + '0';
	c[1] = (first % 10) + '0';
	c[2] = ' ';
	c[3] = (second / 10) + '0';
	c[4] = (second % 10) + '0';
	write(1, c, 5 * sizeof(char));
	if (first != 98 || second != 99)
		write(1, ", ", 2 * sizeof(char));
}

void	ft_print_comb2(void)
{
	int	primero;
	int	segundo;

	primero = 0;
	while (primero < 99)
	{
		segundo = primero + 1;
		while (segundo < 100)
		{
			int_to_char(primero, segundo);
			segundo++;
		}
		primero++;
	}
}
