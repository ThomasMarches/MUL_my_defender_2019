/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_extend
*/

#include "my_defender.h"
#include <stdlib.h>

void free_tower_board(board_t *board)
{
    free_score(board->life);
    free_score(board->wave);
    free_score(board->points);
    sfFont_destroy((sfFont *) sfText_getFont(board->price_tower1));
    sfFont_destroy((sfFont *) sfText_getFont(board->price_tower2));
    sfFont_destroy((sfFont *) sfText_getFont(board->price_tower3));
    sfFont_destroy((sfFont *) sfText_getFont(board->price_tower4));
    sfText_destroy(board->price_tower1);
    sfText_destroy(board->price_tower2);
    sfText_destroy(board->price_tower3);
    sfText_destroy(board->price_tower4);
}

void free_extend(game_object_t *object)
{
    if (object->type == TOWER) {
        free(((tower_t *) object->extend)->tower_param);
        sfFont_destroy((sfFont *) sfText_getFont(((tower_t *) \
        object->extend)->upgrade_txt));
        sfText_destroy(((tower_t *) object->extend)->upgrade_txt);
        sfCircleShape_destroy(((tower_t *) object->extend)->circle);
    } else if (object->type == TOWER_BOARD) {
        free_tower_board(((board_t *) object->extend));
    }
    if (object->type == WAVE) {
        free_list(((map_t *) object->extend)->l1);
        free_list(((map_t *) object->extend)->l2);
        free(((map_t *) object->extend)->map);
    } else if (object->type == BULLET || object->type == UPGRADE_BUTTON)
        return;
    free(object->extend);
}