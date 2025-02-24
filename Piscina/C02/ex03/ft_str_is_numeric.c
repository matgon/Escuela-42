int	check_numeric(char c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
		ret = check_numeric(*str++);
	return (ret);
}
