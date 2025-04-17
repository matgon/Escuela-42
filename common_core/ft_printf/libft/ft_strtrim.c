/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:01:51 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 16:17:59 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(const char *s1, size_t *vars, unsigned int *found,
					char *map)
{
	size_t	len;

	len = ft_strlen(s1);
	vars[0] = 0;
	vars[1] = len - 1;
	vars[2] = 0;
	vars[3] = len;
	found[0] = 0;
	found[1] = 0;
	ft_bzero(map, 128);
}

static void	loop(char const *s1, size_t *vars, unsigned int *found,
				const char *map)
{
	vars[0] = 0;
	while (s1[vars[0]])
	{
		if (map[(int)s1[vars[0]]] == 0 && !found[0])
		{
			found[0] = 1;
			vars[2] = vars[0];
		}
		if (map[(int)s1[vars[1]]] == 0)
			found[1] = 1;
		if ((map[(int)s1[vars[0]++]] == 1 && !found[0])
			|| (map[(int)s1[vars[1]--]] == 1 && !found[1]))
			vars[3]--;
	}
}

/// @brief Elimina todos los caracteres de la string ’set’
// desde el principio y desde el final de ’s1’, hasta
// encontrar un caracter no perteneciente a ’set’. La
// string resultante se devuelve con una reserva de
// malloc(3)
/// @param s1: La string que debe ser recortada.
/// @param set: Los caracteres a eliminar de la string.
/// @return La string recortada. NULL si falla la reserva de memoria.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			vars[4];
	unsigned int	found[2];
	char			*ret;
	char			map[128];

	init_vars(s1, vars, found, map);
	while (set[vars[0]])
	{
		if (map[(int)set[vars[0]]] == 0)
			map[(int)set[vars[0]]] = 1;
		vars[0]++;
	}
	loop(s1, vars, found, map);
	ret = ft_substr(s1, vars[2], vars[3]);
	if (!ret)
		return (NULL);
	return (ret);
}
