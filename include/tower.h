/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower
*/

#ifndef TOWER_H_
#define TOWER_H_

typedef enum tower_type {
    NORMAL,
    FIRE,
    TOWER_MENU,
    ICE
} tower_type_t;

typedef struct tower_s {
    int level;
    int attack_speed;
    int damage;
    int range;
    int cost;
    int upgrade_cost;
    char *tower_param;
    tower_type_t type;
} tower_t;

#endif /* !TOWER_H_ */