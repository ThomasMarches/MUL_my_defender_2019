/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** handle_key_pressed
*/

#include "my_defender.h"

void handle_key_pressed_game(game_t *game, sfKeyCode key, scene_t *scene)
{
    if (key == sfKeyEscape)
        scene->display = do_in_game_menu(game, scene);
}