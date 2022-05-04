/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:21:30 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/05/04 12:58:20 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long int nbr, char *base)
{
	unsigned int	numbase;
	int				count;

	if (!base)
		return (0);
	numbase = (unsigned int)ft_strlen(base);
	count = 1;
	if (nbr < 0)
	{
		count += 1;
		nbr *= (-1);
	}
	while (nbr / numbase)
	{
		nbr = nbr / numbase;
		count++;
	}
	return (count);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	unsigned int	numbase;

	if (!base)
		return (0);
	numbase = (unsigned int)ft_strlen(base);
	if (nbr >= 0 && nbr < numbase)
		ft_putchar(base[nbr]);
	else if (nbr >= numbase)
	{
		ft_putnbr_base(nbr / numbase, base);
		ft_putnbr_base(nbr % numbase, base);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
	}
	return (ft_nbrlen(nbr, base));
}
