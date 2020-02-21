/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** handle_event
*/

#include "my_runner.h"
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
    sfBool joymoved = false;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            is_click_on_object(scene, event.mouseButton, game);
        else if (event.type == sfEvtJoystickMoved)
            joymoved = true;
        if ((event.type == sfEvtMouseMoved && joymoved == false) || \
        event.type != sfEvtMouseMoved)
            handle_joystick_main_menu(event, game, scene);
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
        if (event.type == sfEvtKeyPressed)
            handle_key_pressed_game(game, event.key.code, scene);
        else if (event.type == sfEvtKeyReleased &&  event.key.code == \
        sfKeySpace && game->player->state == JUMPING) {
            if (game->player->move.y < JUMP_SPEED_MIN)
            game->player->move.y = - JUMP_SPEED_MIN;
            update_game_object_state(game->player, FALLING);
        }
        handle_joystick_game(event, game);
    }
}