/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpyrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:00:14 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:39:11 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The memcpyrev() function copies n bytes from memory area src to memory area
dest in descending order. The memory areas must not overlap. 
Use memmove(3) if the memory  areas do overlap.
*/
void	*ft_memcpyrev(void *dest, const void *src, size_t n)
{
	while (n)
	{
		--n;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return ((void *)dest);
}
