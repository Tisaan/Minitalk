/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:15:48 by tseche            #+#    #+#             */
/*   Updated: 2025/12/16 19:00:17 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	while (*s)
		write(fd, s++, 1);
	return (len);
}

int	conversion(char c, va_list args)
{
	char	*tmp;
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putlchar((char)va_arg(args, int));
	else if (c == 's')
	{
		tmp = va_arg(args, char *);
		if (!tmp)
			count += ft_putlstr_fd("(null)", 1);
		else
			count += ft_putlstr_fd(tmp, 1);
	}
	else if (ft_isoneof(c, "diuxX"))
		count += conversionnbr(c, args);
	else if (c == 'p')
		count += ft_convertptr(va_arg(args, void *));
	else
		count += ft_putlchar(c);
	return (count);
}

int	conversionnbr(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putlnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
	{
		count += ft_putnbrbase_fd(va_arg(args, unsigned int),
				"0123456789", 10);
	}
	else if (c == 'x')
	{
		count += ft_putnbrbase_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 16);
	}
	else if (c == 'X')
	{
		count += ft_putnbrbase_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%' && s++)
				count += ft_putlchar('%');
			else if (*s)
				count += conversion(*s++, args);
		}
		else
			count += ft_putlchar(*s++);
	}
	va_end(args);
	return (count);
}
