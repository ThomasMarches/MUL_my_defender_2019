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
    draw_cursor(game->cursor, window);
    sfRenderWindow_display(window);
}

scene_t *init_game_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    update_text(game->score->text, sfWhite, (sfVector2f) {0, 0}, 60);
    scene->background_color = GAME_BACKGROUND_COLOR;
    scene->handle_event = &handle_event_game;
    scene->objects_list = generate_map(NULL, "maps/map");
    scene->objects_list = create_tower_menu(scene->objects_list);
    scene->objects_list = create_board(scene->objects_list);
    scene->objects_list = init_wave(scene->objects_list);
    scene->z_index_deepth = 5;
    scene->window = game->window->window;
    game->score->score = 0;
    return (scene);
}
