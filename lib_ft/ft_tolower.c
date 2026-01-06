/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:08:25 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:41:37 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
These functions convert lowercase letters to uppercase, and vice versa.

If  c  is a lowercase letter, toupper() returns its uppercase equivalent, if
an uppercase representation exists in the current locale.  Otherwise, it re‐
turns  c.  The toupper_l() function performs the same task, but uses the lo‐
cale referred to by the locale handle locale.
If c is an uppercase letter, tolower() returns its lowercase equivalent,  if
a  lowercase representation exists in the current locale.  Otherwise, it re‐
turns c.  The tolower_l() function performs the same task, but uses the  lo‐
cale referred to by the locale handle locale.
If  c is neither an unsigned char value nor EOF, the behavior of these func‐
tions is undefined.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
