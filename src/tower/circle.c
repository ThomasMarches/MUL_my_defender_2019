/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_board.c
*/

#include <math.h>
#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void create_range_circle(game_object_t *object)
{
    tower_t *tower = (tower_t *) object->extend;

    tower->circle = sfCircleShape_create();
    sfCircleShape_setPosition(tower->circle, object->pos);
    sfCircleShape_setRadius(tower->circle, tower->range * 65);
}