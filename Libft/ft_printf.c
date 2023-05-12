/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:30:32 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/11 10:47:20 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//put counter inside each ft_put* function - so no need to include libft
int	whichtype(int i, va_list ap, const char *format)
{
	int	addcount;

	addcount = 0;
	i += 1;
	if (format[i] == 'c')
		addcount = ft_printchar_fd(va_arg(ap, int), 1);
	if (format[i] == 's')
		addcount = ft_printstr_fd(va_arg(ap, char *), 1);
	if (format[i] == 'p')
		addcount = ft_printvoid_fd(va_arg(ap, void *), 1, 0);
	if (format[i] == 'd' || format[i] == 'i')
		addcount = ft_printnbr_fd(va_arg(ap, int), 1, 0);
	if (format[i] == 'u')
		addcount = ft_printunsigned_fd(va_arg(ap, unsigned int), 1, 0);
	if (format[i] == 'x')
		addcount = ft_printhexlow_fd(va_arg(ap, unsigned int), 1, 0);
	if (format[i] == 'X')
		addcount = ft_printhexup_fd(va_arg(ap, unsigned int), 1, 0);
	if (format[i] == '%')
		addcount = ft_printchar_fd('%', 1);
	return (addcount);
}

/* The printf utility formats and prints its arguments, after the first, 
under control of the format.  return #of characters printed */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;
	int		len;

	i = 0;
	count = 0;
	len = ft_strlen(format);
	va_start(ap, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			count += whichtype(i, ap, format);
			i++;
		}
		else
			count += ft_printchar_fd(format[i], 1);
		i++;
	}
	va_end (ap);
	return (count);
}
