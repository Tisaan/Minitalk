/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_grow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:03:26 by tseche            #+#    #+#             */
/*   Updated: 2026/01/06 14:55:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static void	update_map(t_map *map, uint8_t *new_entries, int new_capacity)
{
	free(map->entries);
	map->entries = new_entries;
	map->capacity = new_capacity;
}

static void	copy_entry(t_map *map, uint8_t *new_entries,
		uint8_t *old_entry)
{
	uint8_t	*dest;

	dest = linear_probing(map, new_entries, old_entry);
	ft_memcpy(dest, old_entry, map->key_size);
	ft_memcpy(dest + map->key_size, old_entry + map->key_size, map->value_size);
	map->count++;
}

static void	reinsert_entries(
	t_map *map,
	uint8_t *new_entries,
	size_t entry_size
)
{
	int		i;
	uint8_t	*old_entry;

	map->count = 0;
	i = -1;
	while (++i < map->capacity)
	{
		old_entry = ((uint8_t *)map->entries) + (i * entry_size);
		if (!is_null(old_entry, map->key_size))
			copy_entry(map, new_entries, old_entry);
	}
}

static uint8_t	*allocate_and_init_entries(int capacity, size_t entry_size)
{
	uint8_t	*new_entries;

	new_entries = malloc(capacity * entry_size);
	if (!new_entries)
		return (NULL);
	ft_memset(new_entries, 0, capacity * entry_size);
	return (new_entries);
}

void	adjust_array(t_map *map)
{
	int		new_capacity;
	size_t	entry_size;
	uint8_t	*new_entries;

	new_capacity = grow_capacity(map->capacity);
	entry_size = map->key_size + map->value_size;
	new_entries = allocate_and_init_entries(new_capacity, entry_size);
	if (!new_entries)
		return ;
	reinsert_entries(map, new_entries, entry_size);
	update_map(map, new_entries, new_capacity);
}
