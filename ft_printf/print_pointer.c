/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:50:53 by haoky             #+#    #+#             */
/*   Updated: 2025/10/13 10:29:48 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	addr = (unsigned long long)ptr;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count += print_char('0');
	count += print_char('x');
	count += print_hexa(addr);
	return (count);
}
// int	main(void)
// {
// 	int	x = 42;
// 	int	*ptr = &x;
// 	printf("%p\n", ptr);
// 	printf("%d\n", ft_putnbr(ptr));
// 	return (0);
// }
