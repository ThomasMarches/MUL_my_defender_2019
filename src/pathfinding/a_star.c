/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** a_star
*/

#include "solver.h"

node_t *get_best_node(node_t **list)
{
    node_t *node = *list;

    for (node_t *tmp = *list; tmp; tmp = tmp->next) {
        if (tmp->cost < node->cost)
            node = tmp;
    }
    return (node);
}

bool already_in_list(node_t *list, node_t node)
{
    for (node_t *tmp = list; tmp; tmp = tmp->next)
        if (tmp->index == node.index)
            return (true);
    return (false);
}

int add_neigbour(node_t *actual, map_t *map, int index)
{
    node_t node = {0, 0, NULL, NULL};

    if (index < 0 || index > (map->x + 1) * map->y || map->map[index] != 2)
        return (0);
    node.index = index;
    node.parent = actual;
    node.cost = actual->cost + 1 + map->out - index;
    if (already_in_list(map->l1, node) || already_in_list(map->l2, node))
        return (0);
    if (add_node(&map->l1, node) == false)
        return (84);
    return (0);
}

int add_neigbours(node_t *actual, map_t *map)
{
    int ret = add_neigbour(actual, map, actual->index - 1);

    ret = (ret == 84) ? ret : add_neigbour(actual, map, actual->index + 1);
    ret = (ret == 84) ? ret : add_neigbour(actual, map, actual->index - map->x - 1);
    ret = (ret == 84) ? ret : add_neigbour(actual, map, actual->index + map->x + 1);
    return (ret);
}