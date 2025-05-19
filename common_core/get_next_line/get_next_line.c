/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:13 by matgonza          #+#    #+#             */
/*   Updated: 2025/05/19 17:04:29 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strndup(char *dest, char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	dest[i] = '\0';
}

char	*get_next_line(int fd){
	int		bytes_read;
	int		i;
	char	byte;
	char	*line;
	char	*ret;

	i = 0;
	bytes_read = 1;
	line = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	while (bytes_read > 0 && i < BUFFER_SIZE)
	{
		bytes_read = read(fd, &byte, 1);
		line[i] = byte;
		i++;
		if (byte == '\n')
		{
			printf("%d\n", i);
			ret = (char *) malloc(sizeof(char) * (i + 1));
			ft_strndup(ret, line, i + 1);
			return (ret);
		}
	}
	free(line);
	return (NULL);
}

#include <fcntl.h>
int main()
{
	char	*line;

	int fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
