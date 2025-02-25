#include <unistd.h>

void	print_hex(char c)
{
	char hex_digits[] = "0123456789abcdef";
	char hex[2];

	hex[0] = hex_digits[(c >> 4) & 0xF];
	hex[1] = hex_digits[c & 0xF];
	write(1, "\\", sizeof(char));
	write(1, &hex[0], 1);
	write(1, &hex[1], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 0 && *str <= 31)
			print_hex(*str++);
		else
			write(1, str++, sizeof(char));
	}
}
