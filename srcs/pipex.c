/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:38:37 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/21 23:41:26 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    executer(void)
{
	int     i;
	int     status;
	char    **paths;
	t_list	*lst;
	
	lst = _lst();
	i = 0;
	paths = ft_get_paths(lst->data->env);
	if (paths == NULL)
		ft_error("error : path not found", 1);
	while (paths[i])
	{
		lst->data->cmdpt = ft_strjoin(paths[i], "/");
		lst->data->cmdpt = ft_strjoin(lst->data->cmdpt, lst->data->cmd[0]);
		if (access(lst->data->cmdpt, F_OK) == 0)
			break ;
		i++;
	}
	if (paths[i] == NULL)
		ft_error("error : cmd not found", 1);
	if (execve(lst->data->cmdpt, lst->data->cmd, lst->data->env) == -1)
		ft_error("error : cmd not found", 1);
}

/*void executer(char *str, char **env)
{
	pid_t pid;
	int i;
	char **cmdpt;
	char **path;
	int status;

	i = 0;
	path = ft_get_paths(env);
	if (path == NULL)
		perror("path");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) 
	{ // Processus fils
		execve(str, NULL, env); // Exécution de la commande
		perror("execve"); // Affichage d'un message d'erreur en cas d'échec
		exit(EXIT_FAILURE);
	}
	else { // Processus parent
		if (waitpid(pid, &status, 0) == -1) 
		{ // Attente de la fin du processus fils
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}*/

// redirection vers sortie fd[1] : sortie standart
void    first_cmd_exec(int *fd, char **av)
{
	int 	fd_in;
	t_data	*data;
	// ajt cmd parsing split ' '//
	
	data = _data();
	fd_in = open(av[1], O_RDONLY);
	// if (fd_out < 0)
	// 	ft_perror("error : open file");
	dup2(fd[1], STDOUT_FILENO); // ecrit dans fd[1]
	dup2(fd_in, 0); // lit dans fd[0]
	// close les fds non utilisés
	// p child : écriture
	data->cmd = ft_split(av[2], ' ');
	executer();
	// av[2] : premiere cmd a executer
	close(fd[0]);
	close(fd_in);
	close(fd[1]);
}

// 2nde cmd redirection vers entree fd[0] : entree standart
// void    second_cmd_exec(int *fd, char **av, char **env)
// {
// 	int fd_in;

// 	fd_in = open(av[4], O_RDONLY);
// 	if (fd_in < 0)
// 		ft_perror("error : open file");
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(fd_in, STDOUT_FILENO);
// 	close(fd[1]);
// 	close(fd_in);
// 	close(fd[0]);
// 	executer(av[3], env);
// }

void    pipex(int ac, char **av, char **env)
{
	int     fd[2];
	t_list	*lst;
	int     pid2;
	int     status;

	// if (ac < 5)
	// 	ft_error("error : arguments");
	if (ac == 5)
	{
		lst = _lst();
		init_list(av);
		lst->data->env = env;
		lst->data->pid = fork();
	// 	if (pid1 == -1)
	// 		ft_perror("[PID1] ERROR");
		if (lst->data->pid == 0)
			//child process
			first_cmd_exec(fd, av);
		waitpid(lst->data->pid, NULL, 0);
		// pid2 = fork();
		// if (pid2 == -1)
		// 	ft_perror("[PID2] ERROR");
		// else if (pid2 == 0)
		// 	//child2 process
		// 	second_cmd_exec(fd, av, env);
		// waitpid(pid2, NULL, 0);
		// parent_process(av, env, fd);
		// /*else
		// {
		// 	//parent process
		// 	waitpid(pid2, &status, 0);
		// }
		// */
		// close(fd[0]);
		// close(fd[1]);
	}
}

int main(int ac, char **av, char **env)
{
	pipex(ac, av, env);
	return (0);
}
