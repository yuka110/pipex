/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:28:21 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/13 13:17:35 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	x;

	i = 0;
	arr = (unsigned char *)s;
	x = (unsigned char) c;
	while (i < n)
	{
		if (arr[i] == x)
			return ((void *) arr + i);
		else
			++i;
	}
	return (NULL);
}
