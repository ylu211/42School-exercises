/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:52:31 by ylam              #+#    #+#             */
/*   Updated: 2022/01/24 17:53:45 by ylam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*llst;

	llst = *lst;
	while (llst)
	{
		tmp = llst->next;
		ft_lstdelone(llst, del);
		llst = tmp;
	}
	*lst = NULL;
}
