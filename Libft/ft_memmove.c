/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:28:57 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:38:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	int			j;
	char		*arr1;
	const char	*arr2;

	i = 0;
	j = i;
	arr1 = (char *)dst;
	arr2 = (const char *)src;
	if (arr1 == 0 && arr2 == 0)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		j = i;
		while (i >= 0 && j >= 0)
			arr1[i--] = arr2[j--];
	}
	else
	{
		while (i < (int) len && j < (int) len)
			arr1[i++] = arr2[j++];
	}
	return (dst);
}
