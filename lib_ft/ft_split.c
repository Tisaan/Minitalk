/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:36:17 by tseche            #+#    #+#             */
/*   Updated: 2025/10/29 13:34:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == charset)
			i++;
		if (!str[i])
			break ;
		while (str[i] != charset && str[i])
			i++;
		++count;
	}
	return (count);
}

static char	**ft_algo_split(char *str, char charset, char	**split)
{
	int		j;
	int		i;
	int		start;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != charset && (i == 0 || str[i - 1] == charset))
			start = i;
		if (str[i] != charset && (!str[i + 1] || str[i + 1] == charset))
		{
			split[j] = ft_strndup((char *)str, start, i);
			if (!split[j++])
			{
				ft_freeptr((void **)split);
				return (NULL);
			}
		}
	}
	return (split);
}

/*
Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer.
*/
char	**ft_split(char const *str, char charset)
{
	char	**split;

	if (!str)
		return (NULL);
	split = ft_calloc(sizeof(char *), (count_words((char *)str, charset) + 1));
	if (!split)
		return (NULL);
	split = ft_algo_split((char *)str, charset, split);
	return (split);
}
