/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:23:21 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:31:30 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
checks for an alphabetic character; in the standard "C" locale,
it is equivalent to (isupper(c) || islower(c)).  In some locales, there may
be  additional  characters  for which isalpha() is true—letters which
are neither uppercase nor lowercase.

*/
int	ft_isalpha(int c)
{
	return ((c >= (int) 'A' && c <= (int) 'Z')
		|| (c >= (int) 'a' && c <= (int) 'z'));
}
