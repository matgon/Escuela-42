int	check_printable(char c)
{
	if ((c >= 32 && c <= 255))
	{
		return (1);
	}
	else
		return (0);
}

int	ft_str_is_printable(char *str)
{
	int	ret;

	ret = 1;
	while (*str && ret)
		ret = check_printable(*str++);
	return (ret);
}
