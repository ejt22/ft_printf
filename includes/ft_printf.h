/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:39:09 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/05/04 12:52:37 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_nbrlen(long int nbr, char *base);
int		ft_putnbr_base(long int nbr, char *base);
int		ft_nbrlen_ul(unsigned long nbr, char *base);
void	ft_putnbr_base_ul(unsigned long nbr, char *base);
int		ft_putaddress(void *p);
int		is_conv(char c, char *set);
int		ft_conv(va_list args, char c);
int		ft_printf(const char *str, ...);

#endif
