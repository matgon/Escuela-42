/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:10:10 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/09 22:18:45 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*fill_with_zeros(char *str)
{
	int		length;
	int		n_zeros;
	int		i;
	char	*zeros;
	char	*ret;

	length = ft_strlen(str);
	n_zeros = (3 - (length % 3)) % 3;
	if (n_zeros == 0)
		return (NULL);
	i = 0;
	zeros = (char *)malloc(sizeof(char) * n_zeros + 1);
	while (i < n_zeros)
		zeros[i++] = '0';
	zeros[i] = '\0';
	ret = ft_strcat(zeros, str);
	free(zeros);
	return (ret);
}

void	free_mem(t_node *nodes, int num_lines)
{
	int	i;

	i = num_lines - 1;
	while (i >= 0)
	{
		free(nodes[i].num);
		free(nodes[i].name);
		i--;
	}
	free(nodes);
}

int	parse_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 37)
		return (0);
	i = 0;
	while (str[i])
		if (!(str[i++] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	init(char *str, char *filename)
{
	int			num_lines;
	t_node		*nodes;
	char		*str2;
	char		*aux;

	num_lines = 0;
	if (parse_arg(str))
	{
		aux = fill_with_zeros(str);
		if (aux != NULL)
			str = aux;
		nodes = load_dict(filename, &num_lines);
		if (all_zeros(str))
			str2 = ft_strcat(srch_n("0", 1, nodes), " ");
		else
			str2 = recursion(str, nodes);
		if (aux != NULL)
			free(str);
		put_str(str2);
		free_mem(nodes, num_lines);
		free(str2);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	char		*filename;
	char		*str;

	if (argc >= 2 && argc <= 3)
	{
		filename = NULL;
		if (argc == 2)
		{
			filename = (char *) malloc(sizeof(char) * 13);
			ft_strncpy(filename, "numbers.dict", 12);
			str = argv[1];
		}
		else
		{
			filename = (char *) malloc(sizeof(char) * ft_strlen(argv[1]));
			ft_strncpy(filename, argv[1], ft_strlen(argv[1]));
			str = argv[2];
		}
		if (!init(str, filename))
			write(1, "ERROR: Ponga argumentos validos.\n", 33);
		free(filename);
	}
	else
		write(2, "ERROR: Escriba como maximo dos argumentos.\n", 43);
	return (0);
}
