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
#include <string.h>

void print_result(node_t *node, map_t *map)
{
    node_t *tmp2 = NULL;

    for (node_t *tmp = node; tmp; tmp = tmp->parent) {
        map->map[tmp->index] = 'o';
        tmp->child = tmp2;
        tmp2 = tmp;
    }
    map->solve = tmp2->child;
}

int free_and_leave(map_t *map, int ret)
{
    return (ret);
}

map_t init_map(char *raw_map)
{
    map_t map = {0, 0, NULL, 0, 0, NULL, NULL, NULL};

    map.map = raw_map;
    for (; map.map[map.x] != '\n' && map.map[map.x] != '\0'; map.x++);
    for (int i = 0; map.map[i] != '\0'; i++)
        if (map.map[i] == '\n')
            map.y++;
    for (; map.map[map.out] != '\0' && map.map[map.out] != '5'; map.out++);
    return (map);
}