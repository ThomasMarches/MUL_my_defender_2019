/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy
*/

#include "my_defender.h"
#include "solver.h"
#include <stdlib.h>

bool move_ennemy(game_object_t *object)
{
    map_t *map = &((ennemy_t *) object->extend)->map;
    int dest = map->solve->index;
    int x = dest % (map->x + 1);
    int y = dest / (map->x + 1);

    object->move.x = (x * TILE_WIDTH) - object->pos.x;
    object->move.y = (y * TILE_HEIGHT) - object->pos.y;
    if (object->move.x > 5)
        object->move.x = 5;
    else if (object->move.x < -5)
        object->move.x = -5;
    if (object->move.y > 5)
        object->move.y = 5;
    else if (object->move.y < -5)
        object->move.y = -5;
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
    ennemy->position_on_map += 1;
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

ennemy_t *create_ennemy_struct(int i, map_t *path)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->position_on_map = -i;
    ennemy->slow = 0;
    ennemy->life = 50;
    ennemy->map = *path;
    return (ennemy);
}

void init_ennemy_anim(game_object_t *object)
{
    object->anim[0].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[0].loop = true;
    object->anim[0].frame_id = 0;
    object->anim[0].restart_id = 0;
    object->anim[1].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[1].loop = true;
    object->anim[1].frame_id = 0;
    object->anim[1].restart_id = 0;
    object->anim[2].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[2].loop = true;
    object->anim[2].frame_id = 0;
    object->anim[2].restart_id = 0;
    object->anim[3].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[3].loop = true;
    object->anim[3].frame_id = 0;
    object->anim[3].restart_id = 0;
}

game_object_t *create_ennemy(game_object_t *last, int i, map_t *map)
{
    game_object_t *object = create_game_object(last, \
    "templates/mobs/ennemy.png", (sfVector2f) {((map->in % (map->x + 1)) *
    TILE_WIDTH) - i * TILE_WIDTH, (map->in / (map->x + 1)) * TILE_WIDTH},
    ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct(i, map);
    if (object->extend == NULL) {
        free(object);
        return (NULL);
    }
    object->anim = malloc(sizeof(anim_t) * 4);
    if (object->anim != NULL)
        init_ennemy_anim(object);
    object->state = 0;
    object->update = &update_effect;
    object->move = (sfVector2f) {1, 0};
    init_game_object_frame(object);
    object->update = &update_ennemy;
    object->z_index = 2;
    return (object);
}