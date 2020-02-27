/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_scene
*/

#include "my_defender.h"
#include <stdlib.h>

void draw_game(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_drawText(window, game->score->text, NULL);
    sfRenderWindow_drawText(window, game->highscore->text, NULL);
    sfRenderWindow_display(window);
}

scene_t *init_game_scene(game_t * game, char *map)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    update_text(game->score->text, sfWhite, (sfVector2f) {0, 0}, 32);
    update_text(game->highscore->text, sfWhite, (sfVector2f) {0, 50}, 32);
    scene->background_color = GAME_BACKGROUND_COLOR;
    scene->handle_event = &handle_event_game;
    scene->objects_list = NULL;
    game->score->score = 0;
    return (scene);
}
