/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** in_game_menu
*/

#include "my_defender.h"
#include <stdlib.h>

void main_menu_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = MAIN_MENU_SCENE;
}

game_object_t *create_in_game_menu_objects(void)
{
    game_object_t *object = NULL;

    object = create_text_button(object, (char *)CONTINUE_BUTTON_PATH, \
    (sfVector2f) {CONTINUE_BUTTON_X, CONTINUE_BUTTON_Y});
    object->callback = &play_button_function;
    object = create_text_button(object, (char *)OPTION_BUTTON_PATH, \
    (sfVector2f) {OPTION_BUTTON_X, OPTION_BUTTON_Y_IN_GAME});
    object->callback = &options_button_function;
    object = create_text_button(object, (char *)MAIN_MENU_BUTTON_PATH, \
    (sfVector2f) {MAIN_MENU_BUTTON_X, MAIN_MENU_BUTTON_Y});
    object->callback = &main_menu_button_function;
    return (object);
}

scene_t *create_in_game_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_in_game_menu;
    scene->z_index_deepth = 0;
    scene->objects_list = create_in_game_menu_objects();
    scene->objects_list = create_animated_object(scene->objects_list, \
    (char *) TOP_FLEUR_PATH, (sfVector2f) {TOP_FLEUR_X, TOP_FLEUR_Y}, \
    (sfIntRect **) TOP_FLEUR_FRAME_KEYS);
    scene->objects_list->type = FlEUR;
    scene->objects_list = create_animated_object(scene->objects_list, \
    (char *) BOTTOM_FLEUR_PATH, (sfVector2f) {BOTTOM_FLEUR_X, BOTTOM_FLEUR_Y}, \
    (sfIntRect **) BOTTOM_FLEUR_FRAME_KEYS);
    scene->objects_list->type = FlEUR;
    scene->objects_list = create_game_object(scene->objects_list, \
    (char *) IN_GAME_MENU_BACKGROUND, (sfVector2f) {0, 0}, DECOR);
    scene->display = IN_GAME_MENU_SCENE;
    return (scene);
}

void close_in_game_menu(scene_t *scene, sfRenderWindow *window, scene_t *last, \
game_t *game)
{
    static float frame = 0.0;
    sfClock *clock = sfClock_create();
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
        display_scene(last, window);
        draw_objects(scene->objects_list, window, 0);
        draw_cursor(game->cursor, window);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
}

int do_in_game_menu(game_t *game, scene_t *scene)
{
    int display = IN_GAME_MENU_SCENE;

    sfSound_pause(game->player->sound_effect);
    while (display != MAIN_MENU_SCENE && display != GAME_SCENE && \
    display != -1 && sfRenderWindow_isOpen(game->window->window)) {
        if (display != IN_GAME_MENU_SCENE) {
            display = game->scene_loop[display](game, game->window->window);
            display = (display == MAIN_MENU_SCENE) ? \
            IN_GAME_MENU_SCENE : display;
        } else
            display = in_game_menu_loop(game, game->window->window, scene);
    }
    sfSound_play(game->player->sound_effect);
    return (display);
}