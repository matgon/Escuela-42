/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C08.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:46:08 by matgon            #+#    #+#             */
/*   Updated: 2025/02/23 21:15:07 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

const int	g_max_arr = 10;

void	write_and_set_i(int n, int *i, char *comb)
{
	write(1, comb, n * sizeof(char));
	while (comb[*i] == 9 + '0' || comb[*i] == 10 - (n - *i) + '0')
		(*i)--;
}

void	reset_positions(int n, int i, int *j, char *comb)
{
	write(1, ", ", 2 * sizeof(char));
	comb[i]++;
	*j = i + 1;
	while (*j < n)
		comb[(*j)++] = comb[*j - 1] + 1;
}

void	ft_print_combn(int n)
{
	char	comb[g_max_arr];
	int		i;
	int		j;
	int		finished;

	i = 0;
	while (i < n)
		comb[i++] = '0' + i;
	finished = 0;
	i = n - 1;
	while (!finished)
	{
		write_and_set_i(n, &i, comb);
		if (i < 0)
			finished = 1;
		else
		{
			reset_positions(n, i, &j, comb);
		}
	}
}
