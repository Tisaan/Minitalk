/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoneof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:18:01 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:24:33 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check if c is equal to any of the character of set
*/
int	ft_isoneof(int c, char *set)
{
	while (*set)
	{
		if (*set == (char)c)
			return (1);
		set++;
	}
	return (0);
}
