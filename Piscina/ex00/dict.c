/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:52:57 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/10 22:08:40 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//inicializacion de variables por la norminette (no me cabia en las funciones)
void	init_h_and_i(char hundreds[3], int indexes[2], int *eleven_flag)
{
	hundreds[0] = '1';
	hundreds[1] = '0';
	hundreds[2] = '0';
	indexes[0] = 0;
	indexes[1] = 1;
	*eleven_flag = 0;
}

//busca el numero "nbr", con un numero de digitos "digits" en el diccionario de nodos "dict"
char	*srch_n(char *nbr, int digits, const t_node *dict)
{
	int	i;

	i = 0;
	while (dict[i].num != NULL)
	{
		if (ft_strncmp(nbr, dict[i].num, digits) == 0)
			return (dict[i].name);
		i++;
	}
	return (NULL);
}

//procesar la linea "line" del archivo del diccionario. "node" es el nodo en donde se va a guardar la informacion de la linea
void	process_line(char *line, t_node *node)
{
	char	*num;
	char	*name;
	int		i;

	num = line;
	i = 0;
	while (ft_is_number(num[i]))
		i++;
	node->num = (char *)malloc(sizeof(char) * i + 1);
	if (!(node->num))
		write(1, "Error\n", 6);
	ft_strncpy(node->num, num, i);
	name = line + i;
	i = 0;
	while (name[i] == ' ' || name[i] == ':')
		i++;
	name += i;
	node->name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1);
	ft_strncpy(node->name, name, ft_strlen(name));
	node->num_digits = count_digits(node->num);
}

//inicializacion de variables por la norminette (no me cabia en la funcion)
void	set_vars(int *inx)
{
	inx[0] = 0;
	inx[1] = 0;
}

//funcion que procesa todas las lineas del archivo diccionario y crea todos los nodos con la informacion de cada linea.
t_node	*load_dict(const char *filename, int *size)
{
	int		fd;
	int		idx[2];
	char	*buffers[2];
	t_node	*nodes;

	fd = open(filename, 0);
	set_vars(idx);
	buffers[0] = (char *)malloc(MAX_BUFFER_SIZE);
	nodes = (t_node *)malloc(sizeof(t_node) * count_file_lines(filename));
	while (read(fd, &buffers[0][idx[1]], 1) > 0)
	{
		if (buffers[0][idx[1]++] == '\n')
		{
			buffers[0][idx[1] - 1] = '\0';
			buffers[1] = (char *)malloc(idx[1] + 1);
			ft_strncpy(buffers[1], buffers[0], idx[1]);
			process_line(buffers[1], &nodes[idx[0]++]);
			free(buffers[1]);
			idx[1] = 0;
		}
	}
	free(buffers[0]);
	*size = idx[0];
	close(fd);
	return (nodes);
}
