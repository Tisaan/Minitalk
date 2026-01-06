/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:13:23 by tseche            #+#    #+#             */
/*   Updated: 2025/12/17 16:04:30 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strlen() function calculates the length of the string pointed to by s,
excluding the terminating null byte ('\0').
*/
size_t	ft_strlen(const char *src)
{
	char	*sc;

	sc = (char *)src;
	while (*src)
		src++;
	return (src - sc);
}
