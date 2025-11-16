/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:54:16 by matgonza          #+#    #+#             */
/*   Updated: 2025/11/16 14:46:32 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *cache)
{
	int		len;
	char	*line;

	if (!cache || !cache[0])
		return (NULL);
	len = 0;
	while (cache[len] && cache[len] != '\n')
		len++;
	if (cache[len] == '\n')
		len++;
	line = substr_gnl(cache, 0, len);
	return (line);
}

static char	*clean_cache(char *cache)
{
	int		start;
	char	*ret;

	start = 0;
	while (cache[start] && cache[start] != '\n')
		start++;
	if (!cache[start])
	{
		free(cache);
		return (NULL);
	}
	ret = substr_gnl(cache, start + 1, strlen_gnl(cache) - start - 1);
	free(cache);
	return (ret);
}

static char	*read_and_join(int fd, char *cache)
{
	char	*buff;
	int		bytes;
	int		found;

	buff = malloc(BUFFER_SIZE + 1);
	found = 0;
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!found && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			free(cache);
			return (NULL);
		}
		buff[bytes] = '\0';
		found = check_nl(buff);
		cache = strjoin_gnl(cache, buff);
	}
	free(buff);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = read_and_join(fd, cache);
	if (!cache)
		return (NULL);
	line = extract_line(cache);
	cache = clean_cache(cache);
	return (line);
}
