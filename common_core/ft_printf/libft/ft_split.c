/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:37:51 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 16:18:31 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *s, char c)
{
	size_t			i;
	size_t			num_words;
	unsigned int	new_word;

	i = 0;
	num_words = 0;
	new_word = 1;
	while (s[i])
	{
		if (new_word && s[i] != c)
		{
			num_words++;
			new_word = 0;
		}
		if (s[i++] == c)
			new_word = 1;
	}
	return (num_words);
}

size_t	word_length(const char *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i] && s[i] != c)
	{
		ret++;
		i++;
	}
	return (ret);
}

static void	*clear_mem_leaks(char **s, size_t j)
{
	while (j--)
		free(s[j]);
	free(s);
	return (NULL);
}

static void	init_vars(const char *s, char c, size_t *vars)
{
	vars[0] = 0;
	vars[1] = 0;
	vars[2] = count_words(s, c);
	vars[3] = 0;
}

/// @brief Reserva (utilizando malloc(3)) un array de strings
/// resultante de separar la string ’s’ en substrings
/// utilizando el caracter ’c’ como delimitador. El
/// array debe terminar con un puntero NULL.
/// @param s: La string a separar.
/// @param c: El carácter delimitador.
/// @return El array de nuevas strings resultante de la
/// separación. NULL si falla la reserva de memoria.
char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	vars[4];

	init_vars(s, c, vars);
	ret = (char **) malloc((vars[2] + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[vars[2]] = NULL;
	while (s[vars[0]])
	{
		while (s[vars[0]] == c)
			vars[0]++;
		if (s[vars[0]])
		{
			vars[3] = word_length(&s[vars[0]], c);
			ret[vars[1]] = (char *) malloc((vars[3] + 1) * sizeof(char));
			if (!ret[vars[1]])
				return (clear_mem_leaks(ret, vars[1]));
			ft_strlcpy(ret[vars[1]], (char *)&s[vars[0]], vars[3] + 1);
			vars[1]++;
			vars[0] += vars[3];
		}
	}
	return (ret);
}
