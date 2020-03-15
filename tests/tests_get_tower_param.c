/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tests_get_tower_param.c
*/

#include "my.h"
#include "my_defender.h"
#include <unistd.h>

Test(tests_get_tower_param, tests_get_tower_param_function)
{
    char *tower_param = get_map("tower1");

    cr_assert_eq(tower_param, "100:150:200 \
    3:4:5 \
    10:15:20 \
    1:1,5:2 \
    templates/tower/icon_tower1.png \
    slow:0/0/0 \
    multi_damage:0/0/0");

}