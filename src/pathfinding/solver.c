/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#include "solver.h"
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

int solve(map_t *map)
{
    node_t *actual = NULL;

    map->out = (strlen(map->map) - 2);
    if (add_node(&map->l1, (node_t) {0, 0, NULL, NULL}) == false)
        return (84);
    actual = map->l1;
    while (actual->index != map->out && map->l1 != NULL) {
        actual = get_best_node(&map->l1);
        if (add_neigbours(actual, map) == 84)
            return (free_and_leave(map, 84));
        move_node(&map->l1, &map->l2, actual);
    }
    if (actual->index == map->out)
        print_result(actual, map);
    else
        write(1, "non", 3);
    return (free_and_leave(map, 0));
}

int solver(char *raw_map)
{
    map_t map = {0, 0, NULL, 0, NULL, NULL};

    map = init_map(raw_map);
    return (solve(&map));
}