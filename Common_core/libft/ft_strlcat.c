
#include "libft.h"

size_t    ft_strlcat(char *dest, char *src, size_t size)
{
    unsigned int    dest_len;
    unsigned int    src_len;
    unsigned int    i;

    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    i = 0;
    if (size <= dest_len)
        return (size + src_len);
    while (src[i] && dest_len + i < size - 1)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest_len + src_len);
}