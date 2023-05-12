/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 09:51:36 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:43:00 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmanystr(char const *s, char c)
{
	int	str_count;
	int	i;

	str_count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			++i;
		++str_count;
		while (s[i] == c && s[i] != '\0')
			++i;
	}
	return (str_count);
}

static int	get_strlen(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		++i;
	while (s[i + j] != c && s[i + j] != '\0')
		++j;
	return (j);
}

static void	freearray(char **arr, int row)
{
	while (row >= 0)
	{
		--row;
		free(arr[row]);
	}
	free(arr);
}

static char	**loop(char const *s, char c, int i, char **arr)
{
	int		row;
	int		skip;
	int		count;

	row = 0;
	skip = 0;
	count = 0;
	while (row < howmanystr(s, c) && s != NULL)
	{
		count = get_strlen(&s[i + skip], c);
		arr[row] = ft_substr(s, i + skip, count);
		if (!arr[row])
		{
			freearray(arr, row);
			return (NULL);
		}
		i = i + count + 1;
		++row;
		while (i + skip <= (int)ft_strlen(s) && s[i + skip] == c)
		{
			++skip;
			++count;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_calloc(howmanystr(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] == c)
		++i;
	arr = loop(s, c, i, arr);
	if (!arr)
		return (NULL);
	return (arr);
}
