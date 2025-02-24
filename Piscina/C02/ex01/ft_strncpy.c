char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = dest;
	while (i < n)
	{
		if (*dest)
			*dest++ = *src++;
		else
			*dest++ = '\0';
		i++;
	}
	return (cpy);
}
