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
    ICE,
    AOE
} tower_type_t;

typedef struct board_s {
    score_t *wave;
    score_t *life;
    score_t *points;
    sfText *price_tower1;
    sfText *price_tower2;
    sfText *price_tower3;
    sfText *price_tower4;
} board_t;

typedef struct tower_s {
    sfCircleShape *circle;
    sfSprite *upgrade_spr;
    sfTexture *upgrade_text;
    sfText *upgrade_txt;
    bool display_upgrade;
    int level;
    int slow;
    int aoe;
    int attack_speed;
    int damage;
    int range;
    bool draw_range;
    int cost;
    int delay;
    int upgrade_cost;
    char *tower_param;
    tower_type_t type;
} tower_t;

game_object_t *create_tower(game_object_t *, sfVector2f, tower_type_t);
void increase_board_value(score_t *score, int number, char *str);
void draw_board(sfRenderWindow *window, game_object_t *);
void get_ennemy_to_shoot(game_object_t *, scene_t *scene);
void create_range_circle(game_object_t *);
void draw_range_circle(game_object_t *, void *);
void set_bullet_vector(game_object_t *object, game_object_t *direction);
game_object_t *create_bullet(game_object_t *last, sfVector2f pos, tower_type_t type, game_object_t *);
int update_money(game_object_t *object, int price);
tower_t *create_upgrading_content(tower_t *tower, sfVector2f pos);
tower_t *upgrade_tower(tower_t *tower, tower_type_t type, int n);
int get_int_from_param(char *, int, int);
char *get_string_from_param(char *, int);

#endif /* !TOWER_H_ */