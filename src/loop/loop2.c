/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** loop2
*/

#include "my_defender.h"

int end_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_end_menu();
    scene_index display = END_SCENE;

    if (scene == NULL)
        scene->display = -1;
    scene->window = window;
    update_text(game->score->text, sfWhite, (sfVector2f) {400, 400}, 48);
    center_text(game->score->text, WINDOW_WIDTH);
    update_text(game->highscore->text, sfWhite, (sfVector2f) {400, 300}, 48);
    center_text(game->highscore->text, WINDOW_WIDTH);
    while (sfRenderWindow_isOpen(window) && scene->display == END_SCENE) {
        scene->handle_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_end_menu(scene, game, window);
    }
    close_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}