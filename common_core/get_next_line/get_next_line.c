/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:13 by matgonza          #+#    #+#             */
/*   Updated: 2025/05/21 16:47:52 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*reset_buffer(char *ret, char *buff, int i)
{
	char *aux;
	buff[i] = '\0';
	aux = ft_strjoin(ret, buff);
	free(ret);
	free(buff);
	return (aux);
}

char	*get_next_line(int fd){
	int		i;
	char	*buff;
	char	*ret;

	i = 0;
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = (char *) malloc(sizeof(char) * 1);
	ret[0] = '\0';
	while (read(fd, &buff[i], 1) > 0)
	{
		if (buff[i++] == '\n')
			return (reset_buffer(ret, buff, i));
		if (i == BUFFER_SIZE)
		{
			ret = reset_buffer(ret, buff, i);
			buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
			i = 0;
		}
	}
	if (ft_strlen(ret) > 0 || ft_strlen(buff) > 0)
	{
		printf("%d", i);
		return (reset_buffer(ret, buff, i));
	}
	free(buff);
	free(ret);
	return (NULL);
}

#include <fcntl.h>
int main()
{
	char	*line;

	int fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
