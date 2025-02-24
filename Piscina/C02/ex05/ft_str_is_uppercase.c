int	check_uppercase(char c)
{
	if ((c >= 65 && c <= 90))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
		ret = check_uppercase(*str++);
	return (ret);
}
