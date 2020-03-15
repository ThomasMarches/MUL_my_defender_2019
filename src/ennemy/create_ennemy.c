/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_ennemy
*/

#include "my_defender.h"
#include <stdlib.h>

void draw_ennemy(sfRenderWindow *window, game_object_t *object)
{
    sfRectangleShape *rect = NULL;
    ennemy_t *ennemy = object->extend;
    sfVector2f new_vec =  (sfVector2f) {(48 * (ennemy->life / \
    (double) ennemy->max_life)), 10};

    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    rect = sfRectangleShape_create();
    if (rect == NULL)
        return;
    sfRectangleShape_setSize(rect, new_vec);
    sfRectangleShape_setFillColor(rect, sfGreen);
    sfRectangleShape_setPosition(rect, (sfVector2f) {object->pos.x, \
    object->pos.y - 10});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

ennemy_t *create_ennemy_struct2(int i, map_t *path)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->position_on_map = -i;
    ennemy->slow = 0;
    ennemy->life = 100;
    ennemy->max_life = ennemy->life;
    ennemy->speed = 3;
    ennemy->map = *path;
    return (ennemy);
}

game_object_t *create_ennemy2(game_object_t *last, int i, map_t *map)
{
    game_object_t *object = create_game_object(last, \
    "templates/mobs/ennemy_2.png", (sfVector2f) {((map->in % (map->x + 1)) *
    TILE_WIDTH) - i * TILE_WIDTH, (map->in / (map->x + 1)) * TILE_WIDTH},
    ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct2(i, map);
    if (object->extend == NULL) {
        free(object);
        return (NULL);
    }
    init_ennemy(object);
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
    ennemy->max_life = ennemy->life;
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
    init_ennemy(object);
    return (object);
}