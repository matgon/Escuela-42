
#include <stdio.h>

int check_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int check_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int check_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int ft_pow(int base, int exp){
	int i = 1;
	int ret = 1;

	while (i++ <= exp){
		ret *= base;
	}

	return ret;
}

int recursion(char *str, int base, int *total){
	static int pos;
	int value;

	pos = 0;
	value = 0;
	if (*str)
	{
		recursion(str+1, base, total);
		if (check_digit(*str))
			value = *str - '0';
		else if(check_uppercase(*str))
			value = *str - 'A' + 10;
		else if (check_lowercase(*str))
			value = *str - 'a' + 10;
		else
			return (0);
		*total += (ft_pow(base, pos) * value);
		pos++;
		return (1);
	}
}

int ft_atoi_base(char *str, char *base)
{
	int b;
	int total = 0;

	b = (base[0] - '0') * 10 + (base[1] - '0');
	recursion(str, b, &total);

	return total;
}

int main(int argc, char *argv[])
{
	printf("%d", ft_atoi_base("1111", "36"));
	return (0);
}