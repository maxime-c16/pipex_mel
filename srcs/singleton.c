/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:59:57 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/21 22:53:09 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_list	*_lst(void)
{
	static t_list	lst;
	static int		init = 0;

	if (init == 0)
	{
		init = 1;
		lst.data = malloc(sizeof(t_data));
		ft_bzero(&lst, sizeof(t_list));
	}
	return (&lst);
}

t_data	*_data(void)
{
	static t_data	data;
	static int		i = 0;
	
	if (i == 0)
	{
		ft_bzero(&data, sizeof(t_data));
		i++;
	}
	return (&data);
}
