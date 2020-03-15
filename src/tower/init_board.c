/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_board
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

board_t *config_board_text(board_t *info)
{
    char *tmp = NULL;

    info->wave->text = init_text(info->wave->score_text, 1700, 840, \
    (char *) FONT_PATH);
    info->life->text = init_text(info->life->score_text, 1070, 840, \
    (char *) FONT_PATH);
    info->points->text = init_text(info->points->score_text, 1325, 840, \
    (char *) FONT_PATH);
    sfText_setCharacterSize(info->points->text, 70);
    sfText_setCharacterSize(info->life->text, 70);
    sfText_setCharacterSize(info->wave->text, 70);
    tmp = my_nbr_to_str(100);
    init_price_txt(info, tmp);
    return (info);
}

board_t *create_board_text(board_t *info)
{
    char *tmp = NULL;

    info->wave = malloc(sizeof(score_t));
    info->points = malloc(sizeof(score_t));
    info->life = malloc(sizeof(score_t));
    if (info == NULL || info->wave == NULL || info->points == NULL || \
    info->life == NULL)
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