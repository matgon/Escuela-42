int	check_uppercase(char c)
{
	if ((c >= 65 && c <= 90))
	{
		return (1);
	}
	else
		return (0);
}

char	*ft_strupcase(char *str){
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_uppercase(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
