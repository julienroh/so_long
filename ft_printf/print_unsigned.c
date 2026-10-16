/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:17:35 by haoky             #+#    #+#             */
/*   Updated: 2025/10/10 16:24:37 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_output(unsigned int n)
{
	if (n > 9)
		print_output(n / 10);
	ft_putchar_fd((n % 10 + '0'), 1);
}

int	print_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	print_output(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
