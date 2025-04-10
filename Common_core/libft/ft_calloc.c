#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void    *ret;
    size_t  n_bytes;

    if (nmemb == 0 || size == 0)
    {
        ret = malloc(1);
        n_bytes = 1;
    }
    else
    {
        ret = malloc(nmemb * size);
        n_bytes = nmemb * size;
    }
    ft_bzero(ret, n_bytes);
    return (ret);
}