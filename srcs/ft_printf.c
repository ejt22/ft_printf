/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:34:01 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/05/04 12:59:07 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conv(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_conv(va_list args, char c)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putaddress(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = 0;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conv(str[i + 1], "cspdiuxX%"))
		{
			count += ft_conv(args, str[i + 1]);
			i += 2;
		}
		else if (str[i] == '%' && !(is_conv(str[i + 1], "cspdiuxX%")))
			i++;
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}
