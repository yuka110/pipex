/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 11:50:56 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/11 10:42:33 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//print hexadecimal upper and increment counter
int	ft_printhexup_fd(unsigned long X, int fd, int len)
{
	unsigned long	nbr;

	nbr = X;
	if ((nbr / 16) != 0)
		len = ft_printhexup_fd((nbr / 16), fd, len);
	if ((nbr % 16) < 10)
	{
		len += ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		len += ft_printchar_fd((nbr % 16) + 55, fd);
	}
	if (nbr == X)
		return (len);
	return (0);
}

//print hexadecimal lower and increment counter
int	ft_printhexlow_fd(unsigned long x, int fd, int len)
{
	unsigned long	nbr;

	nbr = x;
	if ((nbr / 16) != 0)
		len = ft_printhexlow_fd((nbr / 16), fd, len);
	if ((nbr % 16) < 10)
	{
		len += ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		len += ft_printchar_fd((nbr % 16) + 87, fd);
	}
	if (nbr == x)
		return (len);
	return (0);
}

//print address and increment counter
int	ft_printvoid_fd(void *p, int fd, int len)
{
	len = ft_printstr_fd("0x", fd);
	len = ft_printhexlow_fd((unsigned long)p, fd, len);
	return (len);
}
