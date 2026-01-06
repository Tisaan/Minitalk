/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:58:07 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:43:18 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The calloc() function allocates memory for an array  of  nmemb  elements  of
size  bytes  each and returns a pointer to the allocated memory.  The memory
is set to zero.  If nmemb or size is 0, then calloc() returns  either  NULL,
or  a  unique pointer value that can later be successfully passed to free().
If the multiplication of nmemb and size would result  in  integer  overflow,
then  calloc() returns an error.  By contrast, an integer overflow would not
be detected in the following call to malloc(), with the result that  an  in‐
correctly sized block of memory would be allocated:
malloc(nmemb * size);
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;

	if (nmemb == 0 || size == 0 || !nmemb || !size)
	{
		ptr = (void *)malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, n));
}
