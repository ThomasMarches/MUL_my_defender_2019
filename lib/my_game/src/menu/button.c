/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button
*/

#include "my_game.h"

bool update_button(game_object_t *object, scene_t *scene)
{
    update_game_object_frame(object);
    update_appearing_object(object, scene);
    return (true);
}

game_object_t *create_button(game_object_t *last, char *path, sfVector2f pos, \
sfIntRect **frame_keys)
{
    game_object_t *object = create_animated_object(last, path, pos, frame_keys);

    object->type = BUTTON;
    object->update = &update_button;
    return (object);
}