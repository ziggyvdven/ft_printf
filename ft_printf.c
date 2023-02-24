/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:49 by zvandeven         #+#    #+#             */
/*   Updated: 2023/02/23 20:42:29 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include 	"printf.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_checkzero(long int a, int fd)
{
	if (a == 0)
	{
		write (fd, "0", 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		str[11];
	long int	tempn;
	int			i;

	i = 1;
	tempn = n;
	ft_checkzero(tempn, fd);
	if (tempn < 0)
	{
		write(fd, "-", 1);
		tempn = tempn * -1;
	}
	while (tempn > 0)
	{
		str[i] = tempn % 10 + 48;
		i++;
		tempn = tempn / 10;
	}
	i = i -1;
	while (i > 0)
	{
		write (fd, &str[i], 1);
		--i;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_numargs(const char *s)
{
	unsigned int	i;
	unsigned int	count;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '%')
		{
			count++;
			if (tmp[i + 1] == '%')
				i++;
		}
	i++;
	}
	printf("%d\n", count);
	return(count);
}


int ft_prspecifier(char c, va_list *args)
{
	if(c == 'c')
		ft_putchar(va_arg(*args, int));
	if(c == 's')
		ft_putstr(va_arg(*args, char*));
// 	if(c == 'p')
// • %p The void * pointer argument has to be printed in hexadecimal format.
	if(c == 'd')
		ft_putnbr_fd(va_arg(*args, int), 1);
	// if(c == 'i')
// • %i Prints an integer in base 10.
// 	if(c == 'u')
// • %u Prints an unsigned decimal (base 10) number.
// 	if(c == 'x')
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// 	if(c == 'X')
// • %X Prints a number in hexadecimal (base 16) uppercase format.
	if(c == '%')
		ft_putchar('%');
	return (0);
}


int ft_printf(const char *print_str, ...)
{
	int			i;
	va_list 	args;

	i = 0;
	va_start (args, print_str);
	while (print_str[i] != '\0')
	{	
		if (print_str[i] != '%')
			write(1, &print_str[i], 1);
		else if (print_str[i] == '%')
		{
			ft_prspecifier(print_str[i + 1], &args);
			i++;
		}
		i++;
	}
	va_end(args);
	return(i);
}

int main()
{
	char s[] = "hello";
	int  d;
	char c;
	
	d = 67;
	c = 'X';
	ft_printf("%s how are you all doing%% %d %c", s, d, c);
	printf("\n");
}


