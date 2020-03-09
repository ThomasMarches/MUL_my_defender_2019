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

void draw_board_text(sfRenderWindow *window, board_t *info)
{
    sfRenderWindow_drawText(window, info->wave->text, NULL);
    sfRenderWindow_drawText(window, info->life->text, NULL);
    sfRenderWindow_drawText(window, info->points->text, NULL);
}

board_t *create_board_text(void)
{
    board_t *info = malloc(sizeof(board_t));
    char *tmp = NULL;
    
    info->wave = malloc(sizeof(score_t));
    info->points = malloc(sizeof(score_t));
    info->life = malloc(sizeof(score_t));
    if (info == NULL || info->wave == NULL || info->points == NULL || info->life == NULL)
        return (NULL);
    info->wave->score = 1;
    info->life->score = 10;
    info->points->score = 0;
    tmp = my_nbr_to_str(info->wave->score);
    info->wave->score_text = my_strcat((char *)"Wave :", tmp);
    tmp = my_nbr_to_str(info->life->score);
    info->life->score_text = my_strcat((char *)"Life :", tmp);
    tmp = my_nbr_to_str(info->points->score);
    info->points->score_text = my_strcat((char *)"Points :", tmp);
    free(tmp);
    info->wave->text = init_text(info->wave->score_text, 800, 800, (char *) FONT_PATH);
    info->life->text = init_text(info->life->score_text, 900, 800, (char *) FONT_PATH);
    info->points->text = init_text(info->points->score_text, 1000, 800,(char *) FONT_PATH);
    return (info);
}

game_object_t *create_board(game_object_t *last)
{
    game_object_t *board = create_game_object(last, (char *) TOWER_BOARD_PATH, (sfVector2f) {0, 800}, TOWER_BOARD);

    if (board == NULL)
        return (last);
    board->z_index = 4;
    board->extend = create_board_text();
    if (board->extend == NULL)
        return (NULL);
    return (board);
}