/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:22:29 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:06:50 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The  memset() function fills the first n bytes of the memory area pointed to
       by s with the constant byte c.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	void	*src;

	src = s;
	while (n--)
		*(unsigned char *)s++ = (unsigned char)c;
	return (src);
}
