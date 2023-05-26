/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:59:12 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/21 23:17:25 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_error(char *msg, int exit_code)
{
	ft_putendl_fd(msg, 2);
	exit(exit_code);
}

void	free_cmds(char *cmd, char **cmds)
{
	int	i;

	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	if (cmds != NULL)
	{
		i = 0;
		while (cmds[i])
		{
			free(cmds[i]);
			cmds[i] = NULL;
			i++;
		}
		free(cmds);
		cmds = NULL;
	}
}

char    **ft_get_paths(char **env)
{
	int     i;
	char    **paths;

	i = 0;
	paths = NULL;
	// compare chaque caracteres apres path=
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	// chemin extrai avec split de la variable path et decoupé : //
	return (paths);
}
