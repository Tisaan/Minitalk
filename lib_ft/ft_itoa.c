/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:33:23 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 20:36:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_intmin(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (str)
		ft_strcpy(str, "-2147483648", 12);
	return (str);
}

/*
Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;

	if (n == INT_MIN)
	{
		str = ft_intmin();
		return (str);
	}
	is_negative = (n < 0);
	if (is_negative)
		n = -n;
	len = ft_count_digits(n) + is_negative;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
