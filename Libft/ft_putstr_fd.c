/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 11:50:42 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:42:39 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	i;

	count = ft_strlen(s);
	i = 0;
	while (i <= count && s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		++i;
	}
}
