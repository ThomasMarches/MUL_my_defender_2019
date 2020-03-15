/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** define
*/

#ifndef ENNEMY_H_
#define ENNEMY_H_

#include "solver.h"

typedef struct ennemy {
    map_t map;
    int slow;
    int life;
    int max_life;
    int speed;
    int position_on_map;
} ennemy_t;

game_object_t *create_ennemy(game_object_t *, int, map_t *, int);
game_object_t *create_ennemy1(game_object_t *, int, map_t *);
game_object_t *create_ennemy2(game_object_t *, int, map_t *);
void init_ennemy_anim(game_object_t *);
game_object_t *init_wave(game_object_t *);
bool update_ennemy(game_object_t *, scene_t *);
void draw_ennemy(sfRenderWindow *, game_object_t *);
void init_ennemy(game_object_t *);

#endif /* !ENNEMY_H_ */
