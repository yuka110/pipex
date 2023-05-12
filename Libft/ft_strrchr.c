/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:29:43 by yitoh         #+#    #+#                 */
/*   Updated: 2022/10/22 15:01:55 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	size_t	i;

	a = (char) c;
	i = ft_strlen(str);
	if (str == '\0')
		return (NULL);
	else
	{
		while (i + 1 != 0)
		{
			if (str[i] == a)
				return ((char *)str + i);
			-- i;
		}
		return (NULL);
	}		
}
