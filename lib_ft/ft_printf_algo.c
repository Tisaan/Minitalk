/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 09:28:43 by tseche            #+#    #+#             */
/*   Updated: 2025/12/16 19:00:25 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigitsbase(size_t n, size_t size_set)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n > size_set - 1)
	{
		n /= size_set;
		++count;
	}
	++count;
	return (count);
}

int	ft_putnbrbase_fd(size_t nbr, char *set, size_t size)
{
	int	count;

	count = ft_countdigitsbase(nbr, size);
	if (nbr >= size)
		ft_putnbrbase_fd(nbr / size, set, size);
	ft_putlchar(set[nbr % size]);
	return (count);
}

int	ft_convertptr(void *p)
{
	size_t		size;
	uintptr_t	addr;

	size = 0;
	if (!p)
	{
		ft_putlstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		addr = (uintptr_t)p;
		ft_putlstr_fd("0x", 1);
		ft_putnbrbase_fd(addr, "0123456789abcdef", 16);
		size = 2 + ft_countdigitsbase(addr, 16);
		return (size);
	}
}

int	ft_putlnbr_fd(int nbr, int fd)
{
	int	count;

	count = ft_count_digits(nbr);
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putlnbr_fd(nbr / 10, fd);
	ft_putlchar((nbr % 10) + '0');
	return (count);
}

int	ft_putlchar(char c)
{
	write(1, &c, 1);
	return (1);
}
