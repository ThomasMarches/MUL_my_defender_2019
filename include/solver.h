/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int x;
    int y;
} vector_t;

typedef struct node {
    int cost;
    int index;
    struct node *parent;
    struct node *next;
} node_t;

typedef struct map {
    int x;
    int y;
    char *map;
    int out;
    node_t *l1;
    node_t *l2;
} map_t;

map_t init_map(char *);
int solver(char *);
node_t *get_best_node(node_t **);
bool add_node(node_t **, node_t);
int add_neigbours(node_t *, map_t *);
int free_and_leave(map_t *, int);
void remove_node(node_t **, node_t *);
void free_list(node_t *);
void move_node(node_t **, node_t **, node_t *);
void print_result(node_t *, map_t *);

#endif /* !SOLVER_H_ */
