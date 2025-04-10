#include <unistd.h>
#include <stdlib.h>

int	is_delimeter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	count_words(char *str)
{
	int	i;
	int new_word;
	int ret;

	i = 0;
	new_word = 1;
	ret = 0;
	while(str[i])
	{
		if (new_word && !is_delimeter(str[i]))
			ret++;
		new_word = 0;
		if (is_delimeter(str[i]))
			new_word = 1;
		i++;
	}
	return (ret);
}

int str_length(char *str)
{
	int i = 0;
	int ret = 0;

	while (!is_delimeter(str[i]))
	{
		i++;
	}
	return (i);
}

char    **ft_split(char *str)
{
	int num_words = count_words(str);
	char **ret = (char **) malloc(sizeof(char *) * num_words + 1);
	int str_len = 0;
	int i = 0;
	int j;
	
	while(str[i])
	{
		j = 0;
		str_len = str_length(str + i);
		ret[i] = (char *) malloc(sizeof(char) * str_len);
		while (j < str_len)
		{	
			ret[i][j] = str[i + j];
			j++;
		}
		if (str_len > 0)
			i+=str_len;
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	char **c = ft_split("Hola que tal  ");
	char *str;
	while (*c != NULL){
		free(*c);
	}
}