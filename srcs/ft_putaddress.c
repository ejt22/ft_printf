/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:22:55 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/05/04 12:58:43 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen_ul(unsigned long nbr, char *base)
{
	unsigned long	numbase;
	int				count;

	if (!base)
		return (0);
	numbase = (int)ft_strlen(base);
	count = 1;
	while (nbr / numbase)
	{
		nbr = nbr / numbase;
		count++;
	}
	return (count);
}

void	ft_putnbr_base_ul(unsigned long nbr, char *base)
{
	unsigned long	numbase;

	if (!base)
		return ;
	numbase = (unsigned long)ft_strlen(base);
	if (nbr >= 0 && nbr < numbase)
		ft_putchar(base[nbr]);
	else if (nbr >= numbase)
	{
		ft_putnbr_base_ul(nbr / numbase, base);
		ft_putnbr_base_ul(nbr % numbase, base);
	}
}

int	ft_putaddress(void *p)
{
	unsigned long	nbr;
	char			*base;

	nbr = (unsigned long)p;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	ft_putnbr_base_ul(nbr, base);
	return (ft_nbrlen_ul(nbr, base) + 2);
}
