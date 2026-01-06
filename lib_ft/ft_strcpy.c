/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:17:54 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:33:04 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The  strcpy()  function  copies  the string pointed to by src, including the
terminating null byte ('\0'), to the buffer pointed to by dest.  The strings
may not overlap, and the destination string dest must be large enough to re‐
ceive the copy.  Beware of buffer overruns!  (See BUGS.)
*/
char	*ft_strcpy(char *dst, const char *src, size_t size)
{
	char	*tmp;

	tmp = (char *)src;
	while (*src && size && size--)
		*(dst++) = *(src++);
	*dst = '\0';
	return (tmp);
}
