int	check_lowercase(char c)
{
	if ((c >= 97 && c <= 122))
	{
		return (1);
	}
	else
		return (0);
}

char	*ft_strcapitalize(char *str){
	int	i;
	int capitalize = 1;

	i = 0;
	while (str[i])
	{	
		if (capitalize && check_lowercase(str[i]))
			str[i] -= 32;
		capitalize = 0;
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			capitalize = 1;
		i++;
	}
	return (str);
}


int main() {
    char mt[250] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    
    printf("%s\n", ft_strcapitalize(mt));
    return 0;
}