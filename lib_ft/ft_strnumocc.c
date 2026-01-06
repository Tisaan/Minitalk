/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnumocc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:10:09 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 18:35:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
get the number of occurence of c in s;
*/
size_t	ft_strnumocc(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c && ++count && s++)
		;
	return (count);
}
