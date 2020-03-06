/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy
*/

#include "my_defender.h"

bool update_ennemy(game_object_t *object, scene_t *scene)
{
    return (true);
}

void callback_ennemy(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
}

ennemy_t *create_ennemy_struct(void)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->slow = 0;
    ennemy->life = 10;
    return (ennemy);
}

game_object_t *create_ennemy(game_object_t *last)
{
    game_object_t *object = create_game_object(last, "truc", (sfVector2f) {0, 0}, ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct();
    if (object->extend == NULL) {
        free(object);
        return (NULL);
    }
    object->update = &update_ennemy;
    object->callback = &callback_ennemy;
    object->z_index = 2;
    return (object);
}