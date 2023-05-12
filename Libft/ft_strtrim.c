/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:29:55 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:43:59 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		suf;
	int		pre;
	int		newlen;

	if (s1 == NULL || set == NULL)
		return (0);
	pre = 0;
	suf = ft_strlen(s1);
	while (ft_strchr(set, s1[pre]) != NULL && s1[pre])
		++pre;
	while (ft_strchr(set, s1[suf - 1]) != NULL && pre < suf)
		--suf;
	newlen = suf - pre;
	if (newlen <= 0)
		newlen = 1;
	arr = ft_substr(s1, pre, newlen);
	return (arr);
}
