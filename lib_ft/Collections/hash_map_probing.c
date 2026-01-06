/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_probing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:02:07 by tseche            #+#    #+#             */
/*   Updated: 2025/12/18 13:13:17 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static int	handle_null_entry(t_map *map, uint8_t *entry, t_probing_data *data)
{
	if (is_null(entry + map->key_size, map->value_size))
	{
		if (data->tombstone != NULL)
			return (0);
		return (1);
	}
	else if (data->tombstone == NULL)
		data->tombstone = entry;
	return (0);
}

static uint8_t	*search_or_insert(t_map *map, void *entries,
		void *key, t_probing_data *data)
{
	uint8_t	*entry;

	while (1)
	{
		entry = entries + (data->index * data->entry_size);
		if (is_null(entry, map->key_size))
		{
			if (handle_null_entry(map, entry, data))
				return (entry);
		}
		else if (map->cmp(entry, key))
			return (entry);
		data->index = (data->index + 1) % map->capacity;
	}
}

uint8_t	*linear_probing(t_map *map, void *entries, void *key)
{
	t_probing_data	data;

	data.entry_size = map->key_size + map->value_size;
	data.hash = hash_function(key, map->key_size);
	data.index = data.hash % map->capacity;
	data.tombstone = NULL;
	return (search_or_insert(map, entries, key, &data));
}

void	map_print(t_map *map, void (*print_value)(void *))
{
	size_t	entry_size;
	int		i;
	uint8_t	*entry;
	bool	first;

	write(1, "{", 1);
	entry_size = map->key_size + map->value_size;
	i = 0;
	first = true;
	while (i < map->capacity)
	{
		entry = ((uint8_t *)map->entries) + (i++ * entry_size);
		if (!is_null(entry, map->key_size))
		{
			if (!first)
				write(1, ", ", 2);
			ft_printf("%s: ", (char *)entry);
			print_value(entry + map->key_size);
			fflush(stdout);
			first = false;
		}
	}
	write(1, "}\n", 2);
}

