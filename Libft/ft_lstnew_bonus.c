/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 16:49:21 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:40:49 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc (sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
