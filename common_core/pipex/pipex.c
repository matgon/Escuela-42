/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:29:27 by matgonza          #+#    #+#             */
/*   Updated: 2025/11/29 14:04:40 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg, int status)
{
	perror(msg);
	exit(status);
}

void	free_split(char **strs)
{
	int	i;

	if (!strs)
		return;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}


===========================
size_t	count_words(const char *s, char c)
{
	size_t			i;
	size_t			num_words;
	unsigned int	new_word;

	i = 0;
	num_words = 0;
	new_word = 1;
	while (s[i])
	{
		if (new_word && s[i] != c)
		{
			num_words++;
			new_word = 0;
		}
		if (s[i++] == c)
			new_word = 1;
	}
	return (num_words);
}

size_t	word_length(const char *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i] && s[i] != c)
	{
		ret++;
		i++;
	}
	return (ret);
}

static void	*clear_mem_leaks(char **s, size_t j)
{
	while (j--)
		free(s[j]);
	free(s);
	return (NULL);
}

static void	init_vars(const char *s, char c, size_t *vars)
{
	vars[0] = 0;
	vars[1] = 0;
	vars[2] = count_words(s, c);
	vars[3] = 0;
}

/// @brief Reserva (utilizando malloc(3)) un array de strings
/// resultante de separar la string ’s’ en substrings
/// utilizando el caracter ’c’ como delimitador. El
/// array debe terminar con un puntero NULL.
/// @param s: La string a separar.
/// @param c: El carácter delimitador.
/// @return El array de nuevas strings resultante de la
/// separación. NULL si falla la reserva de memoria.
char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	vars[4];

	init_vars(s, c, vars);
	ret = (char **) malloc((vars[2] + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[vars[2]] = NULL;
	while (s[vars[0]])
	{
		while (s[vars[0]] == c)
			vars[0]++;
		if (s[vars[0]])
		{
			vars[3] = word_length(&s[vars[0]], c);
			ret[vars[1]] = (char *) malloc((vars[3] + 1) * sizeof(char));
			if (!ret[vars[1]])
				return (clear_mem_leaks(ret, vars[1]));
			ft_strlcpy(ret[vars[1]], (char *)&s[vars[0]], vars[3] + 1);
			vars[1]++;
			vars[0] += vars[3];
		}
	}
	return (ret);
}
===========================

int	check_quotes(char *cmd)
{
	int i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
		{

		}
	}

}

char	*find_cmd_path(const char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*aux;
	char	**paths_in_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths_in_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths_in_path[i])
	{
		aux = ft_strjoin(paths_in_path[i], "/"); //aqui no se esta liberando el primer join
		path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path, X_OK) == 0) //devuelve 0 cuando esta bien
		{
			free_split(paths_in_path);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths_in_path);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	pid_t pid1, pid2, status;
	int fd_in, fd_out;
	int p[2];
	char **cmd;
	char *path;

	if (pipe(p))
	{
		perror("Error en la creacion de la pipe.");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
			error("Failed opening file 1.", 1);
		if (dup2(fd_in, STDIN_FILENO) == -1 || dup2(p[1], STDOUT_FILENO) == -1)
			error("Failed duplicating descriptors.", 1);
		close(fd_in);
		close(p[0]);
		close(p[1]);
		cmd = ft_split(argv[2], ' ');
		if (!cmd)
			error("Failed allocating in split.", 1);
		path = find_cmd_path(cmd[0], envp);
		if (!path)
		{
			free_split(cmd);
			error("Command not found", 1);
		}
		execve(path, cmd, envp);
		free_split(cmd);
		free(path);
		error("Failed in execve 1", 1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		fd_out = open(argv[argc-1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd_out == -1)
			error("Failed opening file 2.", 1);
		if (dup2(p[0], STDIN_FILENO == -1 || dup2(fd_out, STDOUT_FILENO) == -1))
			error("Failed duplicating descriptors.", 1);
		close(fd_out);
		close(p[0]);
		close(p[1]);
		cmd = ft_split(argv[3], ' ');
		if (!cmd)
			error("Failed allocating in split.", 1);
		path = find_cmd_path(cmd[0], envp);
		if (!path)
		{
			free_split(cmd);
			error("Command not found.", 127);
		}
		execve(path, cmd, envp);
		free_split(cmd);
		free(path);
		error("Failed in execve 2.", 1);
	}
	close(p[0]);
	close(p[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (status >> 8);
}