/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** init_map
*/

#include "solver.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

void print_result(node_t *node, map_t *map)
{
    for (node_t *tmp = node; tmp; tmp = tmp->parent)
        map->map[tmp->index] = 'o';
}

int free_and_leave(map_t *map, int ret)
{
    if (map->l1 != NULL)
        free_list(map->l1);
    if (map->l2 != NULL)
        free_list(map->l2);
    return (ret);
}

map_t init_map(char *raw_map)
{
    map_t map = {0, 0, NULL, 0, NULL, NULL};

    map.map = raw_map;
    for (; map.map[map.x] != '\n' && map.map[map.x] != '\0'; map.x++);
    for (int i = 0; map.map[i] != '\0'; i++)
        if (map.map[i] == '\n')
            map.y++;
    for (; map.map[map.out] != '\0' && map.map[map.out] != '4'; map.out++);
    return (map);
}