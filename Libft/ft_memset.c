/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:40:43 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/13 13:16:33 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	char			*arr;

	i = 0;
	a = (unsigned char) c;
	arr = (char *) b;
	while (i < len)
	{
		arr[i] = a;
		++i;
	}
	return ((void *)arr);
}
