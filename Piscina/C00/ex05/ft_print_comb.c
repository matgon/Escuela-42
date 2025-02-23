/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C05.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:07:10 by matgon            #+#    #+#             */
/*   Updated: 2025/02/23 20:15:25 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	while (comb[0] <= '7')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '8')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				write(1, comb, 3 * sizeof(char));
				if (comb[0] != '7' || comb[1] != '8' || comb[2] != '9')
					write(1, ", ", 2 * sizeof(char));
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
