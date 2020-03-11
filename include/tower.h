/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower
*/

#include "my_defender.h"

#ifndef TOWER_H_
#define TOWER_H_

typedef enum tower_type {
    NORMAL,
    FIRE,
    ICE
} tower_type_t;

typedef struct board_s {
    score_t *wave;
    score_t *life;
    score_t *points;
} board_t;

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

game_object_t *create_tower(game_object_t *, sfVector2f, tower_type_t);
void increase_board_value(score_t *score, int number, char *str);
void draw_board(sfRenderWindow *window, game_object_t *);

#endif /* !TOWER_H_ */