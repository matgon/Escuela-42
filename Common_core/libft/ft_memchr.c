
#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
    size_t          i;
    unsigned char   *aux;

    i = 0;
    aux = (unsigned char *) s;
    while (i < n)
    {
        if (aux[i] == c)
            return (aux + i);
    }
    return (NULL);
}