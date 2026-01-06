/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:41:03 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:35:22 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The  memmove()  function  copies n bytes from memory area src to memory area
dest.  The memory areas may overlap: copying takes place as though the bytes
in  src are first copied into a temporary array that does not overlap src or
dest, and the bytes are then copied from the temporary array to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (!n)
		return (dest);
	if (dest > src)
		tmp = ft_memcpyrev(dest, src, n);
	else
		tmp = ft_memcpy(dest, src, n);
	return (tmp);
}
