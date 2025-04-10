int	check_alpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
		ret = check_alpha(*str++);
	return (ret);
}
