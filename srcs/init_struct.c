/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:28:02 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/21 23:22:22 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("cmd[%d] = %s\n", i, tab[i]);
		i++;
	}
}

void	print_struct(void)
{
	t_list	*lst;
	int		i;

	lst = _lst();
	i = 0;
	while (lst)
	{
		printf("lst[%d] = %s\n", i, lst->data->cmd[0]);
		//print io_file//
		//print cmd with print tab//
		printf("lst[%d] io %s\n", i, lst->data->io_file);
		lst = lst->next;
		i++;
	}
}

void  init(void)
{
    t_data  *data;

    data = _data();
    data->ac = -1;
    data->fd_in = -1;
    data->fd_out = -1;
    data->child = -1;
    // -1 pour eviter les segfault car sinon 0 valide//
}

void    init_struct(int ac, char **av, char **env)
{
    t_data  *data;

    data = _data();
    data->ac = ac;
    data->av = av;
    data->env = env;
    init();
}

void	init_list(char **av)
{
	t_list	*lst;
	t_data	*data;
	
	lst = _lst();
	data = _data();
	lst->data = malloc(sizeof(t_data));
	lst->data->cmd = ft_split(av[2], ' ');
	lst->data->io_file = av[1];
	data->cmd = ft_split(av[3], ' ');
	data->io_file = av[4];
	ft_lstadd_back(&lst, ft_lstnew(data));
}
