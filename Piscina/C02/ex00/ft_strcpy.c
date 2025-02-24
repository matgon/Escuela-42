char	*ft_strcpy(char *dest, char *src)
{
	char	*cpy;

	cpy = dest;
	while (*dest)
		*dest++ = *src++;
	return (cpy);
}
