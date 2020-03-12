/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_ennemy
*/

#include "my_defender.h"
#include <stdlib.h>

ennemy_t *create_ennemy_struct2(int i, map_t *path)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->position_on_map = -i;
    ennemy->slow = 0;
    ennemy->life = 100;
    ennemy->speed = 3;
    ennemy->map = *path;
    return (ennemy);
}

game_object_t *create_ennemy2(game_object_t *last, int i, map_t *map)
{
    game_object_t *object = create_game_object(last, \
    "templates/mobs/ennemy.png", (sfVector2f) {((map->in % (map->x + 1)) *
    TILE_WIDTH) - i * TILE_WIDTH, (map->in / (map->x + 1)) * TILE_WIDTH},
    ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct2(i, map);
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

ennemy_t *create_ennemy_struct1(int i, map_t *path)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->position_on_map = -i;
    ennemy->slow = 0;
    ennemy->life = 50;
    ennemy->speed = 5;
    ennemy->map = *path;
    return (ennemy);
}

game_object_t *create_ennemy1(game_object_t *last, int i, map_t *map)
{
    game_object_t *object = create_game_object(last, \
    "templates/mobs/ennemy.png", (sfVector2f) {((map->in % (map->x + 1)) *
    TILE_WIDTH) - i * TILE_WIDTH, (map->in / (map->x + 1)) * TILE_WIDTH},
    ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct1(i, map);
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