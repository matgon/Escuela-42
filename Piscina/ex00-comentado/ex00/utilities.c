/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:53:05 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/10 21:53:32 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//devuelve si un caracter es imprimible
int	is_imprimible(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}

//cuenta el numero de digitos que tiene una cadena de caracteres (solamente numeros)
int	count_digits(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			count++;
		}
		str++;
	}
	return (count);
}

//cuenta todas las lineas de un fichero (para nosotros el diccionario tiene 41 lineas creo)
int	count_file_lines(const char *filename)
{
	int		fd;
	char	buffer;
	int		ret;

	ret = 0;
	fd = open(filename, 0);
	if (fd == -1)
	{
		write(2, "Error al intentar abrir el archivo\n", 35);
		return (-1);
	}
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			ret++;
		}
	}
	close(fd);
	return (ret);
}

//funcion que devuelve 1 si es un numero y 0 si no
int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
