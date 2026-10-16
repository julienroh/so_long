/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:10:30 by haoky             #+#    #+#             */
/*   Updated: 2025/10/13 10:28:55 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_upp(unsigned long long n)
{
	const char	*base;
	int			count;

	base = "0123456789ABCDEF";
	count = 0;
	count = puthex_rec(n, base);
	return (count);
}

// int	main(void)
// {
// 	unsigned int	n = -101003;
// 	printf("%X\n", -101003);
// 	print_hexa(n);
// 	printf("%c", '\n');
// 	printf("%d", print_hexa(n));
// 	return (0);
// }
