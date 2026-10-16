/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:57:11 by haoky             #+#    #+#             */
/*   Updated: 2025/10/13 10:28:48 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply_char(va_list args, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = print_char(va_arg(args, int));
	else if (c == 's')
		result = print_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		result = print_number(va_arg(args, int));
	else if (c == 'u')
		result = print_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		result = print_char('%');
	else if (c == 'x')
		result = print_hexa((unsigned long long)va_arg(args, unsigned int));
	else if (c == 'X')
		result = print_hexa_upp((unsigned long long)va_arg(args, unsigned int));
	else if (c == 'p')
		result = print_pointer(va_arg(args, void *));
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += print_char(str[i]);
		else
		{
			count += ft_apply_char(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	result;
// 	int	vrai_result;
// 	vrai_result = printf(" %p %p\n ", (void *)0, (void *)0);
// 	printf ("%p %p\n",vrai_result);
// 	result = ft_printf(" %p %p\n ", (void *)0, (void *)0);
// 	printf ("%p %p\n",result);
// 	return (0);
// }
