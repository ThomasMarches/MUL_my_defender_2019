/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** GG_menu
*/

#include "my_runner.h"
#include <stdlib.h>

void restart_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = GAME_SCENE;
}

game_object_t *create_end_menu_objects(void)
{
    game_object_t *object = NULL;

    object = create_animated_object(object, (char *)GG_TOP_PATH, \
    (sfVector2f) {GG_TOP_X, GG_TOP_Y}, (sfIntRect **)GG_TOP_FRAME_KEYS);
    object->type = FlEUR;
    object = create_animated_object(object, (char *)GG_BOT_PATH, \
    (sfVector2f) {GG_BOT_X, GG_BOT_Y}, (sfIntRect **)GG_BOT_FRAME_KEYS);
    object->type = FlEUR;
    object = create_text_button(object, (char *)MAIN_MENU_BUTTON_PATH, \
    (sfVector2f) {MAIN_MENU_BUTTON_X, GG_MAIN_MENU_BUTTON_Y});
    object->callback = &main_menu_button_function;
    object = create_text_button(object, (char *)RESTART_PATH, \
    (sfVector2f) {RESTART_X, RESTART_Y});
    object->callback = &restart_button_function;
    return (object);
}

void draw_end_menu(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_drawText(window, game->score->text, NULL);
    sfRenderWindow_drawText(window, game->highscore->text, NULL);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_display(window);
}

scene_t *create_end_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_main_menu;
    scene->z_index_deepth = 0;
    scene->objects_list = create_end_menu_objects();
    scene->display = END_SCENE;
    return (scene);
}