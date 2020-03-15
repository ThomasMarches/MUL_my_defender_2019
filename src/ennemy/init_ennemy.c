/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_ennemy
*/

#include "my_defender.h"
#include <stdlib.h>

void init_ennemy(game_object_t *object)
{
    object->anim = malloc(sizeof(anim_t) * 4);
    if (object->anim != NULL)
        init_ennemy_anim(object);
    object->state = 0;
    object->update = &update_effect;
    object->move = (sfVector2f) {1, 0};
    init_game_object_frame(object);
    object->update = &update_ennemy;
    object->draw = &draw_ennemy;
    object->z_index = 2;
}