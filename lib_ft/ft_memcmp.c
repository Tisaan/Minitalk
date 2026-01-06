/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:02 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:42:54 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcmp() function returns an integer less than,  equal  to,  or  greater
than  zero  if  the  first  n bytes of s1 is found, respectively, to be less
than, to match, or be greater than the first n bytes of s2.
For a nonzero return value, the sign is determined by the sign of  the  dif‐
ference  between the first pair of bytes (interpreted as unsigned char) that
differ in s1 and s2.
If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*lhv;
	unsigned char	*lhr;

	lhv = (unsigned char *)s1;
	lhr = (unsigned char *)s2;
	while (n && *lhv == *lhr)
	{
		lhv++;
		lhr++;
		n--;
	}
	if (n)
		return (*lhv - *lhr);
	return (0);
}
