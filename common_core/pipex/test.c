#include <sys/types.h>

size_t	count_words_cmd(const char *cmd)
{
	size_t	i;
	size_t	num_words;
	int		new_word;
	int		in_single;
	int		in_double;

	i = 0;
	num_words = 0;
	new_word = 1;
	in_single = 0;
	in_double = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (cmd[i] == '"' && !in_single)
			in_double = !in_double;
		else if (cmd[i] == ' ' && !in_single && !in_double)
			new_word = 1;
		else if (new_word)
		{
			num_words++;
			new_word = 0;
		}
		i++;
	}
	if (in_single || in_double)
		return ((size_t)-1);  // error: comillas sin cerrar
	return (num_words);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	char *c = "Hola 'que ' tal";

	printf("Numero de palabras: %ld\n", count_words_cmd(c));
}