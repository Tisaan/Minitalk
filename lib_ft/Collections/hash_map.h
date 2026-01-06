/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:40:48 by tseche            #+#    #+#             */
/*   Updated: 2026/01/06 14:55:03 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include "../libft.h"

# define MAX_LOAD 0.75

typedef struct s_map
{
	void	*entries;
	int		count;
	int		capacity;
	size_t	key_size;
	size_t	value_size;
	bool	(*cmp)(const void *, const void *);
}				t_map;

typedef struct s_probing_data
{
	size_t		entry_size;
	uint32_t	hash;
	uint32_t	index;
	uint8_t		*tombstone;
}	t_probing_data;

uint8_t			*linear_probing(t_map *map,
					void *entries,
					void *key);

void			map_init(t_map	*map,
					size_t key_size,
					size_t value_size,
					bool	(*cmp)(const void *, const void *)
					);

int				map_size(t_map *map);

void			map_free(t_map *map);

uint32_t		hash_function(void *key, int length);

int				grow_capacity(int current_capacity);

void			adjust_array(t_map *map);

bool			map_insert(t_map *map, void *key, void *value);

void			*map_get(t_map *map, void *key);

void			map_remove(t_map *map, void *key);

void			map_clear(t_map *map);

bool			is_null(uint8_t *bytes, size_t size);

void			map_print(t_map *map, void (*print_value)(void *));

#endif
