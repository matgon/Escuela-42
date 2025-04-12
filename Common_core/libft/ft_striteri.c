/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:16:22 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 18:21:57 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief A cada carácter de la string ’s’, aplica la función
/// ’f’ dando como parámetros el índice de cada
/// carácter dentro de ’s’ y la dirección del propio
/// carácter, que podrá modificarse si es necesario.
/// @param s: La string que iterar.
/// @param f: La función a aplicar sobre cada carácter. 
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
