/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:47:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/02/27 15:27:04 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printadr(va_list *args)
{
	int		count;

	count = 2;
	write(1, "0x", 2);
	count += ft_putnbr_base(va_arg(*args, unsigned long), count, 1);
	return (count);
}
