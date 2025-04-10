int	check_lowercase(char c)
{
	if ((c >= 97 && c <= 122))
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
		if (check_lowercase(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}

// int main() {
//     char mt[40] = "aaabvbbbVBsdfa321DF";
    
//     printf("%s\n", ft_strupcase(mt));
//     return 0;
// }