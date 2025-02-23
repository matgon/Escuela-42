/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C07.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:34:24 by matgon            #+#    #+#             */
/*   Updated: 2025/02/23 20:34:48 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursion(int n)
{
	int	resto;

	if (n > 0)
	{
		recursion(n / 10);
		write(1, &(char){'0' + n % 10}, sizeof(char));
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		recursion(nb);
	else
	{
		write(1, &(char){'-'}, sizeof(char));
		recursion(nb * -1);
	}
}
