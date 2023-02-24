/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:51:29 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/02/24 18:47:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			s[] = "hello there";
	int				d;
	char			c;
	unsigned int 	u;

	d = 4000;
	c = 'X';
	u = -6;
	ft_printf("Value = %d\n", ft_printf("ft_printf for c = %c\n", c));
	printf("Value = %d\n", printf("   printf for c = %c\n", c));
	printf("\n");
	ft_printf("Value = %d\n", ft_printf("ft_print s0%s\n", NULL));
	printf("Value = %d\n", printf("   print s0%s\n", NULL));
	printf("\n");
	ft_printf("Value = %d\n", ft_printf("ft_print s%s\n", s));
	printf("Value = %d\n", printf("   print s%s\n", s));
	printf("\n");
	ft_printf("Value = %d\n", ft_printf("ft_printf for d = %d\n", d));
	printf("Value = %d\n", printf("   printf for d = %d\n", d));
	printf("\n");
	ft_printf("Value = %d\n", ft_printf("ft_printf for u = %u\n", u));
	printf("Value = %d\n", printf("   printf for u = %u\n", u));
	printf("\n");
	ft_printf("Value = %d\n", ft_printf("ft_printf just text\n"));
	printf("Value = %d\n", printf("   printf just text\n"));
	printf("\n");
	printf("Value = %d\n", ft_printf("ft_printf for x %x\n", u));
	printf("Value = %d\n", printf("   printf for x %x\n", u));
	printf("\n");
	printf("Value = %d\n", ft_printf("ft_printf for X %X\n", u));
	printf("Value = %d\n", printf("   printf for X %X\n", u));
}
