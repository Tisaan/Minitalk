/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:30:48 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:42:16 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strcmp() function compares the two strings s1 and s2.  The locale is not
taken into account (for a locale-aware  comparison,  see  strcoll(3)).   The
comparison is done using unsigned characters.
strcmp() returns an integer indicating the result of the comparison, as fol‐
lows:
• 0, if the s1 and s2 are equal;
• a negative value if s1 is less than s2;
• a positive value if s1 is greater than s2.
The strncmp() function is similar, except it compares  only  the  first  (at
most) n bytes of s1 and s2.
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while ((src1[i] || src2[i]) && i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
