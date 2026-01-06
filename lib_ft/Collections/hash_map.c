/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:49:13 by tseche            #+#    #+#             */
/*   Updated: 2025/12/18 12:40:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

void	map_init(
	t_map *map,
	size_t key_size,
	size_t value_size,
	bool (*cmp)(const void *, const void *)
	)
{
	map->count = 0;
	map->capacity = 0;
	map->entries = NULL;
	map->key_size = key_size;
	map->value_size = value_size;
	map->cmp = cmp;
}

void	map_free(t_map *map)
{
	free(map->entries);
	map->count = 0;
	map->capacity = 0;
	map->entries = NULL;
	map->key_size = 0;
	map->value_size = 0;
}

inline uint32_t	hash_function(void *key, int length)
{
	uint8_t		*bytes;
	uint32_t	hash;
	int			i;

	bytes = (uint8_t *)key;
	hash = 2166136261u;
	i = 0;
	while (i < length)
	{
		hash ^= bytes[i++];
		hash *= 16777619;
	}
	return (hash);
}

int	grow_capacity(int current_capacity)
{
	if (current_capacity == 0)
		return (8);
	current_capacity *= 2;
	if (current_capacity < 0)
		return (2147483647);
	return (current_capacity);
}

int	map_size(t_map *map)
{
	return (map->count);
}
