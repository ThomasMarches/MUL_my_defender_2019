/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** update_ennemy
*/

#include "my_defender.h"

void update_ennemy_direction(game_object_t *object)
{
    if (object->move.x > 0 && object->state != 0)
        update_game_object_state(object, 0);
    else if (object->move.x < 0 && object->state != 1)
        update_game_object_state(object, 1);
    else {
        if (object->move.y > 0 && object->state != 3)
            update_game_object_state(object, 3);
        else if (object->move.y < 0 && object->state != 2)
            update_game_object_state(object, 2);
    }
}

void check_ennemy_slow(game_object_t *object)
{
    ennemy_t *ennemy = object->extend;

    if (ennemy->slow > 0) {
        object->move.x *= 1.0 - (ennemy->slow / 100.0);
        object->move.y *= 1.0 - (ennemy->slow / 100.0);
        ennemy->slow -= 5;
    }
    move_object(object);
}

bool move_ennemy(game_object_t *object)
{
    map_t *map = &((ennemy_t *) object->extend)->map;
    int dest = map->solve->index;

    object->move.x = ((dest % (map->x + 1)) * TILE_WIDTH) - object->pos.x;
    object->move.y = ((dest / (map->x + 1)) * TILE_HEIGHT) - object->pos.y;
    if (object->move.x > ((ennemy_t *) object->extend)->speed)
        object->move.x = ((ennemy_t *) object->extend)->speed;
    else if (object->move.x < -((ennemy_t *) object->extend)->speed)
        object->move.x = -((ennemy_t *) object->extend)->speed;
    if (object->move.y > ((ennemy_t *) object->extend)->speed)
        object->move.y = ((ennemy_t *) object->extend)->speed;
    else if (object->move.y < -((ennemy_t *) object->extend)->speed)
        object->move.y = -((ennemy_t *) object->extend)->speed;
    update_ennemy_direction(object);
    if (object->move.x == 0 && object->move.y == 0) {
        map->solve = map->solve->child;
        move_ennemy(object);
    } else
        check_ennemy_slow(object);
    return (true);
}

bool kill_ennemy(game_object_t *object, game_object_t *tmp, \
game_object_t *tmp2, scene_t *scene)
{
    if (((ennemy_t *) object->extend)->map.solve->child != NULL)
        update_board_value(((board_t *) tmp->extend)->points, 10, \
        "Points : ");
    for (tmp = scene->objects_list; tmp; tmp = tmp2) {
        tmp2 = tmp->next;
        if (tmp->type == BULLET && ((game_object_t *) tmp->extend) == object)
            destroy_game_object(scene, tmp);
    }
    return (false);
}

bool update_ennemy(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = (ennemy_t *) object->extend;
    game_object_t *tmp2 = NULL;
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != TOWER_BOARD; tmp = tmp->next);
    if (((ennemy_t *) object->extend)->map.solve->child == NULL)
        update_board_value(((board_t *) tmp->extend)->life, -1, "Life : ");
    if (((board_t *) tmp->extend)->life->score <= (unsigned long long) 0)
        scene->display = END_SCENE;
    ennemy->position_on_map += ennemy->speed;
    update_game_object_frame(object);
    if (((ennemy_t *) object->extend)->map.solve->child != NULL && \
    ennemy->life > 0)
        return (move_ennemy(object));
    return (kill_ennemy(object, tmp, tmp2, scene));
}