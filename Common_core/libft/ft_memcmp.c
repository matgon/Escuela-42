#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
    unsigned char *aux1;
    unsigned char *aux2;

	i = 0;
    aux1 = (unsigned char *) s1;
    aux2 = (unsigned char *) s2;
	while (i < n)
	{
		if (aux1[i] - aux2[i] != 0)
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}