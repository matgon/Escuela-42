
#include "pipex.c"

int main(int argc, char **argv)
{
	char *cmd = "awk '{print $2}'";
	char **split = pipex_split(cmd);
	int i = 0;
	while (split[i])
	{
		printf("%i: %s\n", i, split[i++]);
	}
	free_split(split);
	return (0);
}