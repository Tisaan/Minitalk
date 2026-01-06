/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:52:13 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:32:16 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the character ’c’ to the specified file
descriptor.
*/
void	ft_putchar_fd(char c, int fd)
{
	int	err;

	err = (int)write(fd, (void *)&c, (size_t)1);
	if (err == -1)
		return ;
}
