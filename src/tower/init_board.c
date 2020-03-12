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

board_t *config_board_text(board_t *info)
{
    info->wave->text = init_text(info->wave->score_text, 1700, 840, (char *) FONT_PATH);
    info->life->text = init_text(info->life->score_text, 1070, 840, (char *) FONT_PATH);
    info->points->text = init_text(info->points->score_text, 1325, 840,(char *) FONT_PATH);
    sfText_setCharacterSize(info->points->text, 70);
    sfText_setCharacterSize(info->life->text, 70);
    sfText_setCharacterSize(info->wave->text, 70);
    return (info);
}

board_t *create_board_text(board_t *info)
{
    char *tmp = NULL;

    info->wave = malloc(sizeof(score_t));
    info->points = malloc(sizeof(score_t));
    info->life = malloc(sizeof(score_t));
    if (info == NULL || info->wave == NULL || info->points == NULL || info->life == NULL)
        return (NULL);
    info->wave->score = 0;
    info->life->score = 10;
    info->points->score = 1000;
    tmp = my_nbr_to_str(info->wave->score);
    info->wave->score_text = my_strcat((char *)"Wave : ", tmp);
    free(tmp);
    tmp = my_nbr_to_str(info->life->score);
    info->life->score_text = my_strcat((char *)"Life : ", tmp);
    free(tmp);
    tmp = my_nbr_to_str(info->points->score);
    info->points->score_text = my_strcat((char *)"Points : ", tmp);
    free(tmp);
    return (info);
}

game_object_t *create_board(game_object_t *last)
{
    game_object_t *board = create_game_object(last, (char *) TOWER_BOARD_PATH, (sfVector2f) {0, 760}, TOWER_BOARD);
    board_t *info = malloc(sizeof(board_t));

    if (board == NULL|| info == NULL)
        return (last);
    info = create_board_text(info);
    info = config_board_text(info);
    board->z_index = 5;
    board->draw = &draw_board;
    board->extend = (void *) info;
    return (board);
}