/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** player_utils
*/

#include "my_runner.h"

game_object_t *find_player(scene_t *scene)
{
    for (game_object_t *object = scene->objects_list; object; \
    object = object->next) {
        if (object->type == PLAYER)
            return (object);
    }
    return (NULL);
}