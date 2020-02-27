/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** player_env
*/

#include "my_defender.h"

void compute_player_collide_spike(game_object_t *player, game_object_t *object)
{
    if (sfIntRect_intersects(&player->box, &object->box, NULL)) {
        update_game_object_state(player, DEAD);
    }
}

void check_player_env(game_object_t *player, scene_t *scene)
{
    for (game_object_t *object = scene->objects_list; object; \
    object = object->next) {
        if (object->type == TRAP && player->state != DASHING)
            compute_player_collide_spike(player, object);
    }
}