/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_logic
*/

#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;
typedef struct scene scene_t;
typedef struct game game_t;

void handle_event_game(scene_t *, game_t *, sfRenderWindow *);
void handle_event_main_menu(scene_t *, game_t *, sfRenderWindow *);
void handle_event_options(scene_t *, game_t *, sfRenderWindow *);
void handle_event_infos(scene_t *, game_t *, sfRenderWindow *);
void handle_event_in_game_menu(scene_t *, game_t *, sfRenderWindow *);
sfBool check_joystick_button_pressed(int);
void handle_joystick_game(sfEvent, game_t *);
void handle_joystick_main_menu(sfEvent, game_t *, scene_t *);
void handle_key_pressed_game(game_t *, sfKeyCode, scene_t *);

#endif /* !GAME_LOGIC_H_ */
