/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** player_input
*/

#include "my_defender.h"

static void player_input_space(game_t *game)
{
    if (game->player->move.y == 0 && game->player->state == RUNNING) {
        game->player->move.y = - JUMP_SPEED;
        update_game_object_state(game->player, JUMPING);
    }
    if (game->player->state == FALLING && game->player->delta_t == NULL) {
        game->player->move.y = - JUMP_SPEED;
        game->player->delta_t = sfClock_create();
        game->player->pos.x -= PLAYER_DOUBLE_JUMPING_OFFSET;
        update_game_object_state(game->player, DOUBLE_JUMPING);
    }
}

static void player_input_a(game_t *game)
{
    if (game->player->pos.x <= PLAYER_START_X && game->player->state != \
    DOUBLE_JUMPING) {
        game->player->move.x += PLAYER_DASH_SPEED;
        game->player->pos.x += PLAYER_DASH_OFFSET;
        update_game_object_state(game->player, DASHING);
    }
}

static void player_input_x(game_t *game)
{
    if (game->player->state == ATTACKING_RIGHT \
    || game->player->state == DOUBLE_JUMPING\
    || game->player->state == ATTACKING_TOP\
    || game->player->state == ATTACKING_DOWN)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && game->player->state != RUNNING) {
        game->player->pos.x -= PLAYER_ATTACKING_DOWN_OFFSET;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        update_game_object_state(game->player, ATTACKING_DOWN);
    } else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        game->player->pos.x -= PLAYER_ATTACKING_TOP_OFFSET;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        update_game_object_state(game->player, ATTACKING_TOP);
    } else {
        game->player->pos.x -= PLAYER_ATTACKING_RIGHT_OFFSET;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        update_game_object_state(game->player, ATTACKING_RIGHT);
    }
}

void player_input_keyboard(game_t *game, int key)
{
    switch (key) {
    case sfKeySpace:
        player_input_space(game);
        break;
    case sfKeyA:
        player_input_a(game);
        break;
    case sfKeyX:
        player_input_x(game);
        break;
    }
}