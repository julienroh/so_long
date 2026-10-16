/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroh <jroh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:39:14 by haoky             #+#    #+#             */
/*   Updated: 2025/10/13 13:26:28 by jroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_string(char *str);
int		print_number(int n);
int		print_unsigned(unsigned int n);
int		print_hexa(unsigned long long n);
int		print_hexa_upp(unsigned long long n);
int		ft_putnbr(void *ptr);
int		print_pointer(void *n);
int		ft_putchar(char c);
int		puthex_rec(unsigned long long n, const char *base);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif