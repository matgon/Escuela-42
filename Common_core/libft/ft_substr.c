/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:04:55 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/11 13:50:33 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Reserva (con malloc(3)) y devuelve una substring de
/// la string ’s’.
/// La substring empieza desde el índice ’start’ y
/// tiene una longitud máxima ’len’.
/// @param s: La string desde la que crear la substring
/// @param start: El índice del caracter en ’s’ desde el que
/// empezar la substring.
/// @param len: La longitud máxima de la substring.
/// @return La substring resultante.
///	NULL si falla la reserva de memoria.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
	{
		ret = (char *) malloc(1 * sizeof(char));
		if (!ret)
			return (NULL);
		ft_bzero(ret, 1);
		return (ret);
	}
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, (char *)s + start, len + 1);
	return (ret);
}
