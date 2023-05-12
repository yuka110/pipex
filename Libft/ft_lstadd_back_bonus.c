/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 16:48:28 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/09 18:42:26 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (!new)
		return ;
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		node = ft_lstlast(*lst);
		node -> next = new;
	}
}
