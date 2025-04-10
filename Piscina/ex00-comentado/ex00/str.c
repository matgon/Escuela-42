/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:53:01 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/10 21:52:07 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//escribe una cadena de caracteres
void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] != '\0')
			write(1, &str[i], 1);
		i++;
	}
}

//compara dos cadenas de caracteres con un tamanio n de comparacion
int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' || str2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

//concatena str2 a str1 (hace un malloc que hay que liberar despues)
char	*ft_strcat(const char *str1, const char *str2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*ret;

	len1 = 0;
	len2 = 0;
	while (str1[len1] != '\0')
		len1++;
	while (str2[len2] != '\0')
		len2++;
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (i < len1)
		ret[i++] = str1[j++];
	j = 0;
	while (j < len2)
		ret[i++] = str2[j++];
	ret[i] = '\0';
	return (ret);
}

//copia n caracteres de src en dest
char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && is_imprimible(src[i]) && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//devuelve la longitud de una cadena de caracteres
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
