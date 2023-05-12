/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:29:36 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:43:39 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*arr1;
	unsigned char		*arr2;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && arr1[i] != '\0' && arr2[i] != '\0')
	{
		if (arr1[i] != arr2[i])
			break ;
		++i;
	}
	return ((int) arr1[i] - arr2[i]);
}
