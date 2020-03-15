/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_tower_extend
*/

#include "my_defender.h"
#include <stdlib.h>

tower_t *create_tower_extend(tower_type_t type, sfVector2f pos)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL)
        return (NULL);
    tower->type = type;
    tower->level = 1;
    tower->delay = 0;
    tower->tower_param = init_tower_from_file((char *) \
    FILEPATH_TABLE[type - 1]);
    if (tower->tower_param == NULL)
        return (NULL);
    tower->aoe = get_int_from_param(tower->tower_param, 7, 1);
    tower->slow = get_int_from_param(tower->tower_param, 6, 2);
    tower->draw_range = 0;
    tower->attack_speed = get_int_from_param(tower->tower_param, 4, 1);
    tower->damage = get_int_from_param(tower->tower_param, 3, 1);
    tower->range = get_int_from_param(tower->tower_param, 2, 1);
    tower->cost = get_int_from_param(tower->tower_param, 1, 1);
    tower->upgrade_cost = get_int_from_param(tower->tower_param, 1, 2);
    return (tower);
}