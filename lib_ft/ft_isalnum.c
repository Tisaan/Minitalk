/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:23:03 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:24:14 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checks for an alphanumeric character;
 it is equivalent to (isalpha(c) || isdigit(c)).
*/
int	ft_isalnum(int c)
{
	return (((c >= (int) 'A' && c <= (int) 'Z')
			|| (c >= (int) 'a' && c <= (int) 'z'))
		|| (c >= (int) '0' && c <= (int) '9'));
}
