/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:23:41 by matgon            #+#    #+#             */
/*   Updated: 2025/03/03 23:06:28 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	ret;

	ret = 0;
	while (ret == 0 && *s1 && *s2)
		ret = *s1++ - *s2++;
	if (ret > 0 || (*s1 && !*s2 && ret == 0))
		ret = 1;
	if (ret < 0 || (!*s1 && *s2 && ret == 0))
		ret = -1;
	return (ret);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	ret;

	ret = 0;
	while (ret == 0 && *s1 && *s2 && n--)
		ret = *s1++ - *s2++;
	return (ret);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*cpy;

	cpy = dest;
	while (*++dest)
		;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cpy);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*cpy;

	cpy = dest;
	while (*++dest)
		;
	while (*src && nb--)
		*dest++ = *src++;
	*dest = '\0';
	return (cpy);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == to_find[i])
		{
			if (to_find[i+1] == '\0')
				return (str);
			i++;
		}
		else
			i = 0;
		str++;
	}
	return NULL;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		j++;
	if (size <= i)
		return size + j;

	j = 0;
	while (*src && (i + j + 1) < size)
		dest[i + j++] = src[j];
	dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}


int	main(void)
{
	char dest1[40] = "123sadfasdf4";
	char dest2[40] = "123sadfasdf4";
	//size_t
	printf("%zu\n", strlcat(dest1, "asdfasdfasdfas", 3));
	printf("%u\n", ft_strlcat(dest2, "asdfasdfasdfas", 3));
	printf("%s", dest1);
	printf("%s", dest2);
}
