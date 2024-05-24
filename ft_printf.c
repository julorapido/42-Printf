/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julessainthorant <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:58:03 by julessainthor     #+#    #+#             */
/*   Updated: 2024/05/24 11:32:54 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_arg(const char f_, void *arg)
{
	int	l;

	l = 0;
	if ((f_ == 'd' || f_ == 'i' || f_ == 'u' || f_ == 'x'
			|| f_ == 'X') && ((int)((size_t) arg)) == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (f_ == 'c')
		l += ft_putchar_l((int)((size_t) arg));
	else if (f_ == 's')
		l += ft_putstr_l((char *) arg);
	else if (f_ == 'p')
		l += ft_put_ptr_l((t_uli_) arg);
	else if ((f_ == 'd' || f_ == 'i'))
		l += ft_putnbr_base_l((int)((size_t) arg), "0123456789", 0);
	else if (f_ == 'u')
		l += ft_putnbr_base_l((t_ui_)((size_t) arg), "0123456789", 1);
	else if (f_ == 'x')
		l += ft_putnbr_base_l((t_ui_)((size_t) arg), "0123456789abcdef", 1);
	else if (f_ == 'X')
		l += ft_putnbr_base_l((t_ui_)((size_t) arg), "0123456789ABCDEF", 1);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		ft_printf_len;
	va_list	args;

	i = 0;
	ft_printf_len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%' && s[i + 1] != '\0')
		{
			ft_printf_len += ft_arg(s[i + 1], va_arg(args, void *));
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			if (s[i + 1] == '%' && s[i] == '%')
				i++;
			ft_printf_len++;
		}
		i++;
	}
	va_end(args);
	return (ft_printf_len);
}

/*
int main(void)
{
	//const int a = printf("printf = [%i, %c, %p, %s, %X, %u, %x, %d] %% \n", 
	//2147483647, p[1], &p, p, -201, 0, -2147483647, -10);
	//const int b = ft_printf("printf = [%i, %c, %p, %s, %X, %u, %x, %d] %% \n", 
	//2147483647, p[1], &p, p, -201, 0, -2147483647, -10);
	printf("%d vs %d \n", 0, b);
	return 0;
}*/
