/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** handle_event
*/

#include "my_defender.h"
#include <SFML/Graphics.h>

void handle_event_infos(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            scene->display = MAIN_MENU_SCENE;
    }
}

void handle_event_in_game_menu(scene_t *scene, game_t *game, \
sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            scene->display = -1;
        }
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            scene->display = GAME_SCENE;
    }
}

void handle_event_main_menu(scene_t *scene, game_t *game, \
sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
    }
}

void handle_event_options(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            scene->display = MAIN_MENU_SCENE;
    }
}

void handle_event_game(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
    }
}