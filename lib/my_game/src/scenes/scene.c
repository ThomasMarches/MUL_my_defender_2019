/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** scene
*/

#include "my_game.h"
#include <stdlib.h>

static const float MAX_FRAME_RANGE = 0.25;
static const float DELAY_BETWEEN_UPDATE = 1 / 30.0;
static const float SECOND_IN_MICRO = 1000000.0;

void destroy_scene(scene_t *scene)
{
    if (scene != NULL) {
        destroy_object_list(scene);
        free(scene);
    }
}

bool disappear_scene_objects(scene_t *scene)
{
    game_object_t *object = scene->objects_list;
    bool all_disappear = true;

    while (object) {
        if (object->type == FlEUR || object->type == BUTTON)
            update_game_object_frame_reversed(object);
        if (object->sprite_color.a != 0) {
            update_disappearing_object(object);
            all_disappear = false;
        }
        object = object->next;
    }
    return (all_disappear);
}

void close_scene(scene_t *scene, sfRenderWindow *window, sfClock *clock, \
game_t *game)
{
    static float frame = 0.0;
    static float accumulator = 0.0;
    bool is_closed = false;

    while (!is_closed) {
        frame = sfClock_getElapsedTime(clock).microseconds / SECOND_IN_MICRO;
        sfClock_restart(clock);
        if (frame > MAX_FRAME_RANGE)
            frame = MAX_FRAME_RANGE;
        accumulator += frame;
        while (accumulator >= DELAY_BETWEEN_UPDATE && is_closed == false) {
            is_closed = disappear_scene_objects(scene);
            accumulator -= DELAY_BETWEEN_UPDATE;
        }
        display_scene(scene, window);
        draw_cursor(game->cursor, window);
        sfRenderWindow_display(window);
    }
}

void display_scene(scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, scene->background_color);
    draw_objects(scene->objects_list, window, scene->z_index_deepth);
}