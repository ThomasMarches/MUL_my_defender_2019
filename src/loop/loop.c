/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** loop
*/

#include "my_runner.h"

int infos_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_infos_menu();
    scene_index display = INFOS_SCENE;

    if (scene == NULL)
        scene->display = -1;
    else
        scene->display = INFOS_SCENE;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == INFOS_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_main_menu(scene, game, window);
    }
    close_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int in_game_menu_loop(game_t *game, sfRenderWindow *window, \
scene_t *last_scene)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_in_game_menu();
    scene_index display = IN_GAME_MENU_SCENE;

    if (scene == NULL)
        scene->display = -1;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == \
    IN_GAME_MENU_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        display_scene(last_scene, window);
        draw_objects(scene->objects_list, window, 0);
        draw_cursor(game->cursor, window);
        sfRenderWindow_display(window);
    }
    close_in_game_menu(scene, window, last_scene, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int main_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_main_menu();
    scene_index display = MAIN_MENU_SCENE;

    if (scene == NULL)
        scene->display = -1;
    else
        scene->display = MAIN_MENU_SCENE;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == MAIN_MENU_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_main_menu(scene, game, window);
    }
    close_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int options_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = init_options_scene(game);
    int display = OPTION_SCENE;

    if (scene == NULL)
        scene->display = -1;
    while (sfRenderWindow_isOpen(window) && scene->display == OPTION_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_options(scene, game, window);
    }
    close_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}

int game_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = init_game_scene(game, game->map);
    int display = GAME_SCENE;

    if (scene == NULL)
        scene->display = -1;
    else
        scene->display = GAME_SCENE;
    while (sfRenderWindow_isOpen(window) && scene->display == GAME_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_game(scene, game, window);
    }
    save_score(game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}