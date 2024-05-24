/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julessainthorant <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:23:02 by julessainthor     #+#    #+#             */
/*   Updated: 2024/05/24 11:33:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef unsigned int			t_ui_;
typedef unsigned long long int	t_uli_;
typedef long long int			t_li_;

//# define UNSIGNED_MAX 4294967295;
//# define UNSIGNED_SPECIAL(a, b) ((b == 1) ? (4294967295 + b) : (b))
# define NORM_MACRO(x, is_ui_) (x < 0 && is_ui_ == 0) ? 1 : 0

int	ft_printf(const char *format, ...);
int	ft_putchar_l(char c);
int	ft_putstr_l(char *s);
int	ft_put_ptr_l(t_uli_ i);
int	ft_putnbr_base_l(t_li_ i, char *base, size_t e);
int	ft_print_unsigned(unsigned int i);
int	ft_unsigned_putnbr_base_l(unsigned int a, char *b);

#endif
