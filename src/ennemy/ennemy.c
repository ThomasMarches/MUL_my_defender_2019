/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy
*/

#include "my_defender.h"
#include "solver.h"
#include <stdlib.h>

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