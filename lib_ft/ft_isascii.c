/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:37:48 by tseche            #+#    #+#             */
/*   Updated: 2025/10/18 21:03:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
checks whether c is a 7-bit unsigned char value that  fits  into  the
              ASCII character set.
*/
int	ft_isascii(int c)
{
	return (!((unsigned int)c >> 7));
}
