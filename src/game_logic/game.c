/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game
*/

#include "my_defender.h"
#include <stdlib.h>
#include <SFML/Audio.h>

int check_map_at_start(void)
{
    char *raw_map = get_map("maps/map");

    if (raw_map == NULL)
        return (84);
    if (is_map_valid(raw_map, "maps/map") == 84)
        return (84);
    return (0);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    if (check_map_at_start() == 84) {
        free(game);
        return (NULL);
    }
    game->difficulty = 10;
    game->window = init_window();
    init_score(game);
    game->cursor = init_cursor((char *)CURSOR_PATH);
    if (game->window == NULL || game->score == NULL)
        return (NULL);
    game->scene_loop[MAIN_MENU_SCENE] = &main_menu_loop;
    game->scene_loop[GAME_SCENE] = &game_loop;
    game->scene_loop[OPTION_SCENE] = &options_loop;
    game->scene_loop[INFOS_SCENE] = &infos_loop;
    game->scene_loop[END_SCENE] = &end_loop;
    srand((unsigned int) game);
    return (game);
}

void free_score(score_t *score)
{
    sfFont_destroy((sfFont *)sfText_getFont(score->text));
    sfText_destroy(score->text);
    free(score->score_text);
    free(score);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free_score(game->score);
    sfSprite_destroy(game->cursor.sprite);
    sfTexture_destroy(game->cursor.texture);
    free(game);
}