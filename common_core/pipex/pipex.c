#include "pipex.h"

#include <stdio.h>

char *find_cmd_path(const char *cmd)
{
    char *path;


    return (path);
}

int main(int argc, char **argv, char **envp)
{
    pid_t pid1, pid2, status;
    int fd_in, fd_out;
    int p[2];
    char **cmd;

    
    if (pipe(p)) //-1 error, 0 bien
    {
        perror("Error en la creacion de la pipe.");
        exit(1);
    }
    cmd = ft_split(argv[2], ' ');
    execve(cmd[0], cmd, envp);
    perror("Error en execve");
    printf("comando completo 1: %s", argv[2]);
    printf("comando completo 2: %s", argv[3]);
    // pid1 = fork(); // primer hijo
    // if (pid1 == 0)
    // {
    //     fd_in = open(argv[1], O_RDONLY); //fichero de entrada
    //     dup2(fd_in, 0); //ahora la entrada va a ser lo que hay en el fichero
    //     dup2(p[1], 1); //ahora la salida va a escribir en el pipe
    //     close(fd_in);
    //     close(p[0]);  //cierro el pipe de lectura ya que no lo necesito en este hijo
    //     close(p[1]);
    //     cmd = ft_split(argv[2], ' ');
    //     execve(cmd[0], cmd, envp); //ejecuto el comando y sale por p[1]
    //     perror("Error en execve 1.");
    //     exit(1);
    // }
    // pid2 = fork(); //segundo hijo
    // if (pid2 == 0)
    // {
    //     fd_out = open(argv[argc-1], O_CREAT | O_WRONLY | O_TRUNC, 0644); //abro el fichero de escritura
    //     dup2(p[0], 0); //ahora el stdin va a apuntar al pipe de lectura
    //     dup2(fd_out, 1); //ahora la stdout va a apuntar al fichero de salida
    //     close(fd_out);
    //     close(p[0]);
    //     close(p[1]); //cierro el pipe de escritura, ya que no voy a escribir nada
    //     cmd = ft_split(argv[3], ' ');
    //     printf("comando completo 2: %s", argv[3]);
    //     execve(cmd[0], cmd, envp);
    //     perror("Error en execve 2.");
    //     exit(1);
    // }
    // waitpid(pid1, NULL, 0);
    // waitpid(pid2, &status, 0);
    close(p[0]);
    close(p[1]);
    return 0;
    // return (status >> 8);
}