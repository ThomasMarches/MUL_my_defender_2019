/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** vector_shoot.c
*/

#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void update_bullet(game_object_t *object)
{
    sfSprite_move(object->sprite, object->move);
}

void set_bullet_vector(game_object_t *object, game_object_t *direction)
{
    int direction_x = 0;
    int direction_y = 0;
    sfVector2f shooting_dir = {1, 0};

    direction->pos = sfSprite_getPosition(direction->sprite);
    object->pos = sfSprite_getPosition(object->sprite);
    direction_y = object->pos.y - direction->pos.y;
    direction_x = object->pos.x - direction->pos.x;
    if (direction->pos.x < object->pos.x)
        shooting_dir.x = -1;
    shooting_dir.y = direction_y / direction_x;
    object->move = shooting_dir;
}

game_object_t *create_bullet(game_object_t *last, sfVector2f pos,
tower_type_t type)
{
    game_object_t *object = NULL;

    switch (type) {
    case 0:
        object = create_game_object(last, NORMAL_BULLET, pos, BULLET);
        break;
    case 1:
        object = create_game_object(last, SLOW_BULLET, pos, BULLET);
        break;
    case 2:
        object = create_game_object(last, FIRE_BULLET, pos, BULLET);
        break;
    case 3:
        object = create_game_object(last, AOE_BULLET, pos, BULLET);
        break;
    }
    if (object == NULL)
        return (NULL);
    object->update = &update_bullet;
    object->z_index = 2;
    return (object);
}