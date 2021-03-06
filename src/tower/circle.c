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
    game_object_t *button = tower->button;
    sfIntRect box = {object->pos.x, object->pos.y, 50, 50};
    scene_t *scene = pt;
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);

    if (tower->draw_range == 0)
        tower->draw_range = 1;
    else if (!sfIntRect_contains(&box, pos.x, pos.y))
        tower->draw_range = 0;
    if (button == NULL)
        return;
    else {
        if ((button->state == 0 && tower->level != 3))
            button->state = 1;
        else if (!sfIntRect_contains(&box, pos.x, pos.y) || tower->level == 3)
            button->state = 0;
    }
}

void create_range_circle(game_object_t *object)
{
    tower_t *tower = (tower_t *) object->extend;
    sfVector2f position = {0, 0};
    int calc = tower->range * 65;

    tower->pos = object->pos;
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