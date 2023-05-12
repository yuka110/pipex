/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 20:43:45 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:43:46 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	else
	{
		while (i + j <= len - 1 && haystack[i + j] && needle[j])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j])
			{
				++j;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
			if (haystack[i + j])
				++i;
		}
		return (NULL);
	}
}
