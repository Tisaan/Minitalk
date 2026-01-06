/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:02:46 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:34:16 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second.
A new string is created (using malloc(3)) to store the
results from the successive applications of f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	size_t	i;

	if (!s || !f)
		return (NULL);
	src = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!src)
		return (NULL);
	i = 0;
	while (s[i])
	{
		src[i] = (*f)(i, s[i]);
		++i;
	}
	src[i] = 0;
	return (src);
}
