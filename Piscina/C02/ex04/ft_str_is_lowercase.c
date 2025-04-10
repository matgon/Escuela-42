int	check_lowercase(char c)
{
	if ((c >= 97 && c <= 122))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
		ret = check_lowercase(*str++);
	return (ret);
}
