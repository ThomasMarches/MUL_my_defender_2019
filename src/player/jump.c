/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** jump
*/

#include "my_runner.h"

void compute_jump(game_object_t *player)
{
    if (player->move.y > FALLING_MAX_SPEED)
        player->move.y = FALLING_MAX_SPEED;
    if (player->state == JUMPING && player->move.y > 0) {
        update_game_object_state(player, FALLING);
    }
    else if (player->state == JUMPING && (!sfKeyboard_isKeyPressed(JUMP_KEY) \
    && (check_joystick_button_pressed(0)))) {
        if (player->move.y < JUMP_SPEED_MIN)
            player->move.y = - JUMP_SPEED_MIN;
        update_game_object_state(player, FALLING);
    }
}