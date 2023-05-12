/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 12:28:38 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:43:21 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		prelen;
	size_t		suflen;
	size_t		i;
	size_t		j;

	prelen = ft_strlen(s1);
	suflen = ft_strlen(s2);
	arr = malloc((prelen + suflen + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (arr == NULL)
		return (NULL);
	while (i < prelen)
	{
		arr[i] = s1[i];
		++i;
	}
	while (i + j < prelen + suflen)
	{
		arr[i + j] = s2[j];
		++j;
	}
	arr[i + j] = '\0';
	return (arr);
}

/*
	arr = (char *)ft_memcpy(arr, s1, prelen);
	arr = (char *)ft_memcpy(arr + prelen, s2, suflen);
	arr[prelen + suflen] = '\0';
	return (arr);
*/