/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:06:01 by haoky             #+#    #+#             */
/*   Updated: 2025/10/13 10:10:26 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	puthex_rec(unsigned long long n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += puthex_rec(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	print_hexa(unsigned long long n)
{
	const char	*base;
	int			count;

	base = "0123456789abcdef";
	count = 0;
	count = puthex_rec(n, base);
	return (count);
}

// int	ft_putnbr(void *ptr)
// {
// 	uintptr_t	addr;
// 	int	count;

// 	addr = (unsigned long)ptr;
// 	count += ft_putchar_fd('0', 1);
// 	count += ft_putchar_fd('x', 1);
// 	count += print_hexa(addr);
// 	return (count);
// }

// int	main(void)
// {
// 	int	x = 42;
// 	int	*ptr = &x;
// 	printf("%p\n", ptr);
// 	printf("%d\n", ft_putnbr(ptr));
// 	return (0);
// }
