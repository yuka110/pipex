/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:23:19 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:41:41 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int		copy;
	int		digit;

	copy = n;
	digit = 0;
	if (copy == 0)
		++digit;
	if (copy < 0)
	{
		++digit;
		copy = copy * -1;
	}
	while (copy > 0)
	{
		copy = copy / 10;
		++digit;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = count_digit(n);
	i = count - 1;
	num = ft_calloc((count + 1), sizeof(char));
	if (!num)
		return (NULL);
	if (n < 0)
		n = n * -1;
	while (i >= 0 && n >= 0)
	{
		num[i] = (n % 10) + 48;
		--i;
		n = n / 10;
	}
	if (num[0] == '0')
		num[0] = '-';
	return (num);
}
