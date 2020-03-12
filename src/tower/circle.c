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

void callback_tower(game_object_t *object, void *pt)
{
    tower_t *tower = (tower_t *) object->extend;

    if (tower->draw_range == 0)
        tower->draw_range = 1;
    else
        tower->draw_range = 0;
    if (tower->display_upgrade == 0)
        tower->display_upgrade = 1;
    else
        tower->display_upgrade = 0;
}

void create_range_circle(game_object_t *object)
{
    tower_t *tower = (tower_t *) object->extend;
    sfVector2f position = {0, 0};
    int calc = tower->range * 65;

    position.x = object->pos.x - calc + 30.5;
    position.y = object->pos.y - calc + 34;
    tower->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(tower->circle, sfTransparent);
    sfCircleShape_setOutlineColor(tower->circle, sfBlack);
    sfCircleShape_setOutlineThickness(tower->circle, 3);
    sfCircleShape_setRadius(tower->circle, tower->range * 65);
    sfCircleShape_setPosition(tower->circle, position);
    object->callback = &callback_tower;
}