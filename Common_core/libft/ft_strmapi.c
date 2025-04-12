/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:05:47 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 18:12:25 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Aplica la función ’f’ a cada carácter de la cadena
/// ’s’, pasando su índice como primer argumento y el
/// propio carácter como segundo argumento. Se crea una
/// nueva cadena (utilizando malloc(3)) para recoger
/// los resultados de las sucesivas aplicaciones de
/// ’f’.
/// @param s: La string que iterar.
/// @param f: La función a aplicar sobre cada carácter.
/// @return La string creada tras el correcto uso de ’f’ sobre
// cada carácter.
// NULL si falla la reserva de memoria.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	ret = (char *) malloc((len + 1) * sizeof(char));
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
