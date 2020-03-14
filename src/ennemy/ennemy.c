/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy
*/

#include "my_defender.h"
#include "solver.h"
#include <stdlib.h>

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

bool move_ennemy(game_object_t *object)
{
    map_t *map = &((ennemy_t *) object->extend)->map;
    int dest = map->solve->index;
    int x = dest % (map->x + 1);
    int y = dest / (map->x + 1);

    object->move.x = (x * TILE_WIDTH) - object->pos.x;
    object->move.y = (y * TILE_HEIGHT) - object->pos.y;
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
        move_object(object);
    return (true);
}

bool update_ennemy(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = (ennemy_t *) object->extend;
    game_object_t *tmp2 = NULL;
    game_object_t *tmp = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type !=
    TOWER_BOARD; tmp = tmp->next);
    if (((ennemy_t *) object->extend)->map.solve->child == NULL)
        increase_board_value(((board_t *) tmp->extend)->life, -1, "Life : ");
    if (((board_t *) tmp->extend)->life->score <= (unsigned long long) 0)
        scene->display = END_SCENE;
    ennemy->position_on_map += ennemy->speed;
    update_game_object_frame(object);
    if (((ennemy_t *) object->extend)->map.solve->child != NULL && ennemy->life > 0)
        return (move_ennemy(object));
    increase_board_value(((board_t *) tmp->extend)->points, 10, "Points : ");
    for (tmp = scene->objects_list; tmp; tmp = tmp2) {
        tmp2 = tmp->next;
        if (tmp->type == BULLET && ((game_object_t *) tmp->extend) == object)
            destroy_game_object(scene, tmp);
    }
    return (false);
}

void init_ennemy_anim(game_object_t *object)
{
    object->anim[0].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[0].loop = true;
    object->anim[0].frame_id = 0;
    object->anim[0].restart_id = 0;
    object->anim[1].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_LEFT;
    object->anim[1].loop = true;
    object->anim[1].frame_id = 0;
    object->anim[1].restart_id = 0;
    object->anim[2].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_TOP;
    object->anim[2].loop = true;
    object->anim[2].frame_id = 0;
    object->anim[2].restart_id = 0;
    object->anim[3].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_DOWN;
    object->anim[3].loop = true;
    object->anim[3].frame_id = 0;
    object->anim[3].restart_id = 0;
}

game_object_t *create_ennemy(game_object_t *last, int i, map_t *map, int id)
{
    if (id == 0)
        return (create_ennemy1(last, i, map));
    else
        return (create_ennemy2(last, i, map));
}