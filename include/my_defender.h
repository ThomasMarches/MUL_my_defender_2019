/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#define ABS(x)  x = (x < 0) ? - x : x

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "player.h"
#include "game_logic.h"
#include "map.h"
#include "menu_runner.h"
#include "scene_runner.h"
#include "const.h"
#include "my_graph.h"
#include "my_game.h"
#include "tower.h"

typedef struct game_object game_object_t;

typedef enum {
    JUMP_KEY = sfKeySpace,
    RELEASED = sfEvtKeyReleased,
    PRESSED = sfEvtKeyPressed,
} event;

typedef struct score {
    unsigned long long int score;
    sfText *text;
    char *score_text;
} score_t;

game_t *init_game();
int game_loop(game_t *, sfRenderWindow *);
void destroy_game(game_t *);
void draw_game(scene_t *, game_t *, sfRenderWindow *);

void update_physics(game_object_t *, scene_t *);
void increase_score(game_t *);
void init_score(game_t *);
void save_score(game_t *game);

#endif /* !MY_RUNNER_H_ */
