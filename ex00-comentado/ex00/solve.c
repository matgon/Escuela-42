/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:54:40 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/09 22:17:06 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

t_process_hundreds	init_p(char *nbr, int indexes[2], char hundreds[3],
			const t_node *dict)
{
	t_process_hundreds	p;

	p.dict = dict;
	p.h = hundreds;
	p.i = indexes[0];
	p.nbr = nbr;
	return (p);
}

void	append_to_result(char **ret, char *str, int free_ret)
{
	char	*temp;

	temp = ft_strcat(*ret, str);
	if (*ret && free_ret)
		free(*ret);
	*ret = ft_strcat(temp, " ");
	free(temp);
}

void	process_hundreds(t_process_hundreds p, char **ret)
{
	if (p.nbr[p.i] != '0')
	{
		p.h[p.i] = p.nbr[p.i];
		if (p.i == 0)
		{
			append_to_result(ret, srch_n(&p.h[p.i], 1, p.dict), 1);
			p.h[p.i] = '1';
			append_to_result(ret, srch_n("100", 3, p.dict), 1);
		}
		else if (p.i == 1)
		{
			if (p.nbr[p.i] == '1')
			{
				*p.eleven_flag = 1;
				p.h[p.i + 1] = p.nbr[p.i + 1];
				append_to_result(ret, srch_n(&p.h[p.i], 2, p.dict), 1);
			}
			else
				append_to_result(ret, srch_n(&p.h[p.i], 2, p.dict), 1);
		}
		else if (p.i == 2 && !(*p.eleven_flag))
			append_to_result(ret, srch_n(&p.h[p.i], 1, p.dict), 1);
	}
}

char	*create_chain(char *nbr, int pos, const t_node *dict)
{
	int					indexes[3];
	char				*buffs[2];
	char				hundreds[3];
	t_process_hundreds	p;

	buffs[0] = ft_strcat("", "");
	init_h_and_i(hundreds, indexes, &indexes[2]);
	buffs[1] = (char *)malloc(sizeof(char) * pos);
	while (indexes[0] < 3)
	{
		p = init_p(nbr, indexes, hundreds, dict);
		p.eleven_flag = &indexes[2];
		process_hundreds(p, &buffs[0]);
		if (indexes[0] == 2 && pos > 3)
		{
			while (indexes[1] < pos)
				buffs[1][indexes[1]++] = '0';
			buffs[1][0] = '1';
			if (nbr[0] != '0' || nbr[1] != '0' || nbr[2] != '0')
				append_to_result(&buffs[0], srch_n(buffs[1], pos - 2, dict), 1);
		}
		indexes[0]++;
	}
	free(buffs[1]);
	return (buffs[0]);
}

char	*recursion(char *nbr, const t_node *dict)
{
	static int	pos;
	char		*str;
	char		*ret;
	char		*testing;

	if (*nbr)
	{
		str = recursion(nbr + 1, dict);
		pos++;
		if (pos % 3 == 0)
		{
			testing = create_chain(nbr, pos, dict);
			ret = ft_strcat(testing, str);
			free(testing);
			if (*str)
				free(str);
			return (ret);
		}
		return (str);
	}
	return ("");
}
