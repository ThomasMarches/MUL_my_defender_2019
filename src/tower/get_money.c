/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_tower
*/

#include "my_defender.h"
#include "tower.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int update_money(game_object_t *object, int price)
{
    game_object_t *tmp = NULL;
    board_t *info = NULL;
    int check = 0;

    for (tmp = object; tmp && tmp->type != TOWER_BOARD; tmp = tmp->next);
    if (!tmp)
        return (0);
    info = (board_t *) tmp->extend;
    if (info->points->score >= price)
        increase_board_value(info->points, price * - 1, "Points : ");
    return (info->points->score);
}