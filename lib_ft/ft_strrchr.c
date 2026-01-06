/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:18:50 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:41:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strrchr() function returns a pointer to the last occurrence of the char‐
       acter c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	s += ft_strlen(s);
	if (!c)
		return ((char *)s);
	while (s >= tmp && *s != (unsigned char)c)
		s--;
	if (*s != (unsigned char)c)
		return (NULL);
	return ((char *)s);
}
