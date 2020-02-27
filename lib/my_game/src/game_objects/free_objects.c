/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_objects
*/

#include "my_game.h"
#include <stdlib.h>

void free_extend(game_object_t *object)
{
    if (object->type == TOWER) {
        free(object->extend);
    }
}

void free_anim(game_object_t *object)
{
    if (object->anim != NULL && object->sound_effect != NULL)
        for (int i = 0; object->anim[i].sound_buffer != NULL; i++)
            sfSoundBuffer_destroy(object->anim[i].sound_buffer);
    if (object->anim != NULL)
        free(object->anim);
}

void free_sprite_and_texture(game_object_t *object)
{
    if (object->sprite != NULL)
        sfSprite_destroy(object->sprite);
    if (object->texture != NULL)
        sfTexture_destroy(object->texture);
}

void destroy_game_object(scene_t *scene, game_object_t *prev, \
game_object_t *object)
{
    if (object == NULL)
        return;
    else {
        if (prev == NULL)
            scene->objects_list = object->next;
        else
            prev->next = object->next;
    }
    free_sprite_and_texture(object);
    if (object->sound_effect != NULL) {
        sfSound_stop(object->sound_effect);
        sfSound_destroy(object->sound_effect);
    }
    if (object->delta_t != NULL)
        sfClock_destroy(object->delta_t);
    free_anim(object);
    if (object->extend != NULL)
        free_extend(object->extend);
    free(object);
}

void destroy_object_list(scene_t *scene)
{
    while (scene->objects_list)
        destroy_game_object(scene, NULL, scene->objects_list);
}