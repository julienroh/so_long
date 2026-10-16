/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:53:43 by haoky             #+#    #+#             */
/*   Updated: 2025/10/10 15:41:45 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int n)
{
	int	result;
	int	nb;

	result = 0;
	nb = n;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		result++;
	}
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		return (11);
	if (nb == 0)
		return (1);
	return (result);
}
