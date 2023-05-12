/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 20:43:33 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:42:54 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	size_t	i;

	a = (char) c;
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == a)
			return ((char *) s + i);
		++i;
	}
	return (NULL);
}
