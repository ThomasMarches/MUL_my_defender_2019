/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_board.c
*/

#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void increase_board_value(score_t *score, int number, char *str)
{
    char *tmp = NULL;

    score->score += number;
    free (score->score_text);
    tmp = my_nbr_to_str(score->score);
    score->score_text = my_strcat(str, tmp);
    free(tmp);
    sfText_setString(score->text, score->score_text);
}

void draw_board(sfRenderWindow *window, game_object_t *object)
{
    board_t *info = (board_t *) object->extend;

    draw_object(window, object);
    sfRenderWindow_drawText(window, info->life->text, NULL);
    sfRenderWindow_drawText(window, info->wave->text, NULL);
    sfRenderWindow_drawText(window, info->points->text, NULL);
}

void init_price_txt(board_t *info, char *tmp)
{
    info->price_tower1 = init_text(tmp, 100, 900, (char *) FONT_PATH);
    free(tmp);
    tmp = my_nbr_to_str(150);
    info->price_tower2 = init_text(tmp, 150, 900, (char *) FONT_PATH);
    free(tmp);
    tmp = my_nbr_to_str(100);
    info->price_tower3 = init_text(tmp, 200, 900, (char *) FONT_PATH);
    free(tmp);
    tmp = my_nbr_to_str(150);
    info->price_tower4 = init_text(tmp, 250, 900, (char *) FONT_PATH);
    free(tmp);
    sfText_setCharacterSize(info->price_tower1, 20);
    sfText_setCharacterSize(info->price_tower2, 20);
    sfText_setCharacterSize(info->price_tower3, 20);
    sfText_setCharacterSize(info->price_tower4, 20);
}

game_object_t *create_board(game_object_t *last)
{
    game_object_t *board = create_game_object(last, (char *) \
    TOWER_BOARD_PATH, (sfVector2f) {0, 760}, TOWER_BOARD);
    board_t *info = malloc(sizeof(board_t));

    if (board == NULL || info == NULL)
        return (last);
    info = create_board_text(info);
    info = config_board_text(info);
    board->z_index = 5;
    board->draw = &draw_board;
    board->extend = (void *) info;
    return (board);
}