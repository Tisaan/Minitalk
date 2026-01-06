/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:33:45 by tseche            #+#    #+#             */
/*   Updated: 2025/12/18 12:33:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

bool	map_insert(t_map *map, void *key, void *value)
{
	uint8_t	*entry;
	bool	is_new_key;

	if (map->count >= map->capacity * MAX_LOAD)
		adjust_array(map);
	entry = linear_probing(map, map->entries, key);
	is_new_key = is_null(entry, map->key_size);
	if (is_new_key && is_null(entry + map->key_size, map->value_size))
		map->count++;
	ft_memcpy(entry, key, map->key_size);
	ft_memcpy(entry + map->key_size, value, map->value_size);
	return (is_new_key);
}

void	*map_get(t_map *map, void *key)
{
	uint8_t	*entry;

	entry = linear_probing(map, map->entries, key);
	if (map->capacity == 0)
		return (NULL);
	if (is_null(entry, map->key_size))
		return (NULL);
	return (entry + map->key_size);
}

void	map_remove(t_map *map, void *key)
{
	uint8_t	*entry;

	entry = linear_probing(map, map->entries, key);
	if (map->count == 0)
		return ;
	ft_memset(entry, 0, map->key_size);
	ft_memset(entry + map->key_size, 0, map->value_size);
	ft_memset(entry + map->key_size + map->value_size - 1, 1, 1);
}

void	map_clear(t_map *map)
{
	size_t	entry_size;

	entry_size = map->key_size + map->value_size;
	ft_memset(map->entries, 0, map->capacity * entry_size);
	map->count = 0;
}

inline bool	is_null(uint8_t *bytes, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (bytes[i++] != 0)
			return (false);
	}
	return (true);
}
