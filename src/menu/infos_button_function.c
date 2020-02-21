/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** infos_button_function
*/

#include "my_runner.h"

void infos_left_arrow_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != INFO; tmp = tmp->next);
    if (tmp == NULL)
        return;
    if (tmp->anim[0].frame_id == 0) {
        for (int i = 0; tmp->anim[0].frames_key[i + 1] != NULL; i++)
            tmp->anim[0].frame_id = i;
        update_game_object_frame(tmp);
    } else
        update_game_object_frame_reversed(tmp);
}

void infos_right_arrow_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != INFO; tmp = tmp->next);
    if (tmp == NULL)
        return;
    if (tmp->anim[0].frames_key[tmp->anim[0].frame_id + 1] == NULL)
        tmp->anim[0].frame_id = -1;
    update_game_object_frame(tmp);
}