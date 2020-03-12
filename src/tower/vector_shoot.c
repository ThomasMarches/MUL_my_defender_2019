/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** vector_shoot.c
*/

#include <math.h>
#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

bool update_bullet(game_object_t *object, scene_t *scene)
{
    set_bullet_vector(object, (game_object_t *) object->extend);
    move_object(object);
    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (tmp->type == ENNEMY && object->extend ==
        tmp && sfIntRect_intersects(&object->box, &tmp->box, NULL))
            return (false);
    return (true);
}

void set_bullet_vector(game_object_t *object, game_object_t *direction)
{
    int direction_x = 0;
    int direction_y = 0;
    sfVector2f shooting_dir = {1, 0};

    direction_y = object->pos.y - direction->pos.y;
    direction_x = object->pos.x - direction->pos.x;
    shooting_dir.y = sin(atan2(direction_y, direction_x)) * - 10;
    shooting_dir.x = cos(atan2(direction_y, direction_x)) * - 10;
    object->move = shooting_dir;
}

game_object_t *create_bullet(game_object_t *last, sfVector2f pos,
tower_type_t type, game_object_t *target)
{
    game_object_t *object = NULL;

    switch (type - 1) {
    case 0:
        object = create_game_object(last, (char *) NORMAL_BULLET, pos, BULLET);
        break;
    case 1:
        object = create_game_object(last, (char *) SLOW_BULLET, pos, BULLET);
        break;
    case 2:
        object = create_game_object(last, (char *) FIRE_BULLET, pos, BULLET);
        break;
    case 3:
        object = create_game_object(last, (char *) AOE_BULLET, pos, BULLET);
        break;
    }
    if (object == NULL)
        return (last);
    object->update = &update_bullet;
    object->z_index = 2;
    object->extend = (void *) target;
    object->box = (sfIntRect) {pos.x, pos.y, 50, 50};
    return (object);
}