/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:07:25 by zvandeven         #+#    #+#             */
/*   Updated: 2023/02/24 18:42:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printnbr(int nbr, int len, char *base)
{
	long int	lnbr;
	int			count;

	count = 0;
	lnbr = nbr;
	if (lnbr != 0)
	{
		count = ft_printnbr(lnbr / len, len, base) + 1;
	}
	ft_putchar(base[lnbr % len]);
	return (count);
}

int	ft_putnbr_base(unsigned int nbr, int count, int b)
{
	int		len;
	char	*base;

	len = 0;
	if (b == 1)
		base = "0123456789abcdef";
	if (b == 2)
		base = "0123456789ABCDEF";
	while (base[len] != '\0')
	len ++;
	count = ft_printnbr(nbr, len, base);
	return (count);
}
