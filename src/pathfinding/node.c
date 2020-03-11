/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** node
*/

#include "solver.h"
#include <stdbool.h>
#include <stdlib.h>

bool add_node(node_t **list, node_t data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return (false);
    *node = data;
    node->next = *list;
    *list = node;
    return (true);
}

void remove_node(node_t **list, node_t *node)
{
    node_t *tmp = *list;

    if (tmp == node) {
        *list = node->next;
        free(node);
        return;
    }
    for (; tmp && tmp->next != node; tmp = tmp->next);
    tmp->next = node->next;
    free(node);
}

void free_list(node_t *list)
{
    node_t *tmp = NULL;

    for (; list;) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void move_node(node_t **l1, node_t **l2, node_t *node)
{
    node_t *tmp = *l1;

    if (tmp == node) {
        *l1 = tmp->next;
        node->next = *l2;
        *l2 = node;
        return;
    }
    for (; tmp && tmp->next != node; tmp = tmp->next);
    if (!tmp)
        return;
    tmp->next = node->next;
    node->next = *l2;
    *l2 = node;
}