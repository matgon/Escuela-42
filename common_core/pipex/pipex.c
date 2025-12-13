/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:29:27 by matgonza          #+#    #+#             */
/*   Updated: 2025/12/13 16:32:24 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg, int status)
{
	write(2, msg, ft_strlen(msg));
	exit(status);
}

void	free_split(char **strs)
{
	int i;

	if (!strs)
		return;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	count_words_cmd(const char *cmd)
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
		return (-1);
	return (num_words);
}

size_t	word_len_cmd(const char *cmd, size_t i)
{
	size_t	len;
	int		in_single;
	int		in_double;

	len = 0;
	in_single = 0;
	in_double = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (cmd[i] == '"' && !in_single)
			in_double = !in_double;
		else if (cmd[i] == ' ' && !in_single && !in_double)
			break;
		else
			len++;
		i++;
	}
	return (len);
}

char **pipex_split(char *cmd)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	len;
    int     words = 0;
	int		in_single = 0;
	int		in_double = 0;
	char	**ret;

    words = count_words_cmd(cmd);
    if (words == -1)
	{
        return (NULL);
	}
	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (cmd[i])
	{
		while (cmd[i] == ' ')
			i++;
		if (!cmd[i])
			break;
		len = word_len_cmd(cmd, i);
		ret[j] = malloc(len + 1);
		if (!ret[j])
			return (NULL);

		size_t k = 0;
		in_single = 0;
		in_double = 0;
		while (cmd[i])
		{
			if (cmd[i] == '\'' && !in_double)
				in_single = !in_single;
			else if (cmd[i] == '"' && !in_single)
				in_double = !in_double;
			else if (cmd[i] == ' ' && !in_single && !in_double)
				break;
			else
				ret[j][k++] = cmd[i];
			i++;
		}
		ret[j][k] = '\0';
		j++;
	}
	ret[j] = NULL;
	return (ret);
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
		aux = ft_strjoin(paths_in_path[i], "/");
		path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path, X_OK) == 0)
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

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1, pid2;
	int		status;
	int		p[2];
	int		fd_in, fd_out;
	char	**cmd;
	char	*path;

	if (pipe(p) == -1)
		error("Pipe creation failed\n", 1);

	// Hijo 1
	pid1 = fork();
	if (pid1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
			error("Failed opening infile\n", 1);

		if (dup2(fd_in, STDIN_FILENO) == -1)
			error("dup2 stdin failed\n", 1);
		if (dup2(p[1], STDOUT_FILENO) == -1)
			error("dup2 stdout failed\n", 1);

		close(fd_in);
		close(p[0]);
		close(p[1]);

		cmd = pipex_split(argv[2]);
		if (!cmd)
			error("Failed in split\n", 1);

		if (ft_strchr(cmd[0], '/'))
			execve(cmd[0], cmd, envp);

		path = find_cmd_path(cmd[0], envp);
		if (!path)
			error("Command not found\n", 127);

		execve(path, cmd, envp);
		free_split(cmd);
		free(path);
		error("Execve failed\n", 1);
	}

	// Hijo 2
	pid2 = fork();
	if (pid2 == 0)
	{
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd_out == -1)
			error("Failed opening outfile\n", 1);

		if (dup2(p[0], STDIN_FILENO) == -1)
			error("dup2 stdin failed\n", 1);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			error("dup2 stdout failed\n", 1);

		close(fd_out);
		close(p[0]);
		close(p[1]);

		cmd = pipex_split(argv[3]);
		if (!cmd)
			error("Failed in split\n", 1);

		if (ft_strchr(cmd[0], '/'))
			execve(cmd[0], cmd, envp);

		path = find_cmd_path(cmd[0], envp);
		if (!path)
			error("Command not found\n", 127);

		execve(path, cmd, envp);
		free_split(cmd);
		free(path);
		error("Execve failed\n", 1);
	}

	close(p[0]);
	close(p[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);

	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (1);
}
