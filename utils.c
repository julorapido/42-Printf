/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julessainthorant <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:30:45 by julessainthor     #+#    #+#             */
/*   Updated: 2024/05/24 11:29:17 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar_l(char i)
{
	write(1, &(i), 1);
	return (1);
}

int	ft_putstr_l(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_l(t_li_ nbr, char *base, size_t is_unsigned)
{
	int	size_base;
	int	nbr_final[200];
	int	i;
	int	j;

	j = NORM_MACRO(nbr, is_unsigned);
	i = 0;
	size_base = 0;
	if (nbr < 0 && is_unsigned == 0)
	{
		nbr = -nbr;
		ft_putchar_l('-');
	}
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	j += i;
	while (--i >= 0)
		ft_putchar_l(base[nbr_final[i]]);
	return (j);
}

int	ft_put_ptr_l(t_uli_ i)
{
	t_uli_	hex;
	char	p[40];
	int		o;
	int		q;

	o = 0;
	if (i == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (i > 0)
	{
		hex = i % 16;
		i /= 16;
		if (hex > 9)
			p[o++] = (char)((hex - 10) + 'a');
		else
			p[o++] = (char)(hex + '0');
	}
	q = o;
	while (o-- > 0)
		write(1, &p[o], 1);
	return (q + 2);
}
