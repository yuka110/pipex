/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 09:52:25 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/11 10:42:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//putchar and increment counter
int	ft_printchar_fd(char c, int fd)
{
	int	len;

	len = 1;
	write(fd, &c, 1);
	return (len);
}

//putstr and increment counter
int	ft_printstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = (int) ft_strlen(s);
	write(fd, s, len);
	return (len);
}

//putnbr and return counter
int	ft_printnbr_fd(int n, int fd, int len)
{
	long int	nbr;

	nbr = (long int) n;
	if (nbr < 0)
	{
		len += ft_printchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		len = ft_printnbr_fd((nbr / 10), fd, len);
	}
	len += ft_printchar_fd((nbr % 10) + '0', 1);
	return (len);
}

//put unsigned nbr and  return counter
int	ft_printunsigned_fd(unsigned int u, int fd, int len)
{
	if (u > 9)
		len += ft_printnbr_fd((u / 10), fd, len);
	len += ft_printchar_fd((u % 10) + '0', 1);
	return (len);
}
