/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu
*/

#ifndef MENU_RUNNER_H_
#define MENU_RUNNER_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;
typedef struct scene scene_t;
typedef struct game game_t;

void play_button_function(game_object_t *, void *);
void options_button_function(game_object_t *, void *);
void exit_button_function(game_object_t *, void *);
void infos_button_function(game_object_t *, void *);
void return_button_function(game_object_t *, void *);
void infos_right_arrow_function(game_object_t *, void *);
void infos_left_arrow_function(game_object_t *, void *);
void main_menu_button_function(game_object_t *, void *);

int main_menu_loop(game_t *, sfRenderWindow *);
int options_loop(game_t *, sfRenderWindow *);
int in_game_menu_loop(game_t *, sfRenderWindow *, scene_t *);
int infos_loop(game_t *, sfRenderWindow *);
int end_loop(game_t *, sfRenderWindow *);

void draw_main_menu(scene_t *, game_t *, sfRenderWindow *);
void draw_end_menu(scene_t *, game_t *, sfRenderWindow *);
void draw_options(scene_t *, game_t *, sfRenderWindow *);

game_object_t *create_indicator(game_object_t *, char *, sfVector2f);
game_object_t *create_bar(game_object_t *, char *, sfVector2f);

int do_in_game_menu(game_t *, scene_t *);
void close_in_game_menu(scene_t *, sfRenderWindow *, scene_t *, game_t *);

#endif /* !MENU_H_ */
