/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 11:59:12 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:42:33 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitcounter(long int n)
{
	long int	copy;
	int			digit;

	copy = n;
	digit = 0;
	if (copy == 0)
		++digit;
	if (copy < 0)
		copy = copy * -1;
	while (copy > 0)
	{
		copy = copy / 10;
		++digit;
	}
	return (digit);
}

static int	exponential(int base, long int exponent)
{
	long int	i;
	int			result;

	i = 0;
	result = 1;
	while (i < exponent)
	{
		result = result * base;
		++i;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	long int	digit;
	char		char_num;

	nbr = (long int) n;
	digit = digitcounter(nbr) - 1;
	char_num = '0';
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	while (digit >= 0 && nbr >= 0)
	{
		char_num = (nbr / exponential(10, digit)) + 48;
		ft_putchar_fd(char_num, fd);
		nbr = nbr % exponential(10, digit);
		--digit;
	}
}
