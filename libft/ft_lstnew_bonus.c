/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:56:45 by mecauchy          #+#    #+#             */
/*   Updated: 2023/05/21 22:08:57 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elm;

	new_elm = malloc((sizeof(*new_elm)));
	if (!new_elm)
		return (NULL);
	ft_bzero(new_elm, sizeof(*new_elm));
	new_elm->data = (t_data *)content;
	new_elm->next = NULL;
	return (new_elm);
}
