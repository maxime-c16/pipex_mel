/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:42 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/21 23:06:39 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <signal.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

// PROTOTYPE //

void    pipex(int ac, char **av, char **env);
void    first_cmd_exec(int *fd, char **av);
void    second_cmd_exec(int *fd, char **av, char **env);
void    executer(void);
char    **ft_get_paths(char **env);
void    ft_error(char *msg, int exit_code);
void	free_cmds(char *cmd, char **cmds);
void	init_list(char **av);
pid_t   fork(void);
void	print_tab(char **tab);


// STRUCTURE //

// SINGLETON //

t_list  *_lst(void);

t_data	*_data(void);

#endif
