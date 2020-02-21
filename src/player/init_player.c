/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include "my_runner.h"
#include <stdlib.h>

void init_player_attack_sound_effect(anim_t *anims)
{
    anims[ATTACKING_TOP].sound_loop = false;
    anims[ATTACKING_TOP].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
    anims[ATTACKING_DOWN].sound_loop = false;
    anims[ATTACKING_DOWN].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
    anims[ATTACKING_RIGHT].sound_loop = false;
    anims[ATTACKING_RIGHT].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_ATTACKING_SOUND_PATH);
}

void init_player_anim_sound_effect(anim_t *anims)
{
    anims[RUNNING].sound_loop = true;
    anims[RUNNING].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_RUNNING_SOUND_PATH);
    anims[JUMPING].sound_loop = false;
    anims[JUMPING].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_JUMPING_SOUND_PATH);
    anims[FALLING].sound_loop = true;
    anims[FALLING].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_FALLING_SOUND_PATH);
    anims[DASHING].sound_loop = false;
    anims[DASHING].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_DASHING_SOUND_PATH);
    anims[DOUBLE_JUMPING].sound_loop = false;
    anims[DOUBLE_JUMPING].sound_buffer = \
    sfSoundBuffer_createFromFile(PLAYER_DOUBLE_JUMPING_SOUND_PATH);
    anims[DEAD].sound_loop = false;
    anims[DEAD].sound_buffer = NULL;
}

game_object_t *init_player(game_object_t *last)
{
    game_object_t *player = NULL;
    sfVector2f pos = {PLAYER_START_X, PLAYER_START_Y};

    player = create_game_object(last, (char *)PLAYER_SPRITE_PATH, pos, PLAYER);
    if (player == NULL)
        return (NULL);
    player->update = &player_update;
    player->move = (sfVector2f){PLAYER_SPEED_X, PLAYER_SPEED_Y};
    player->state = RUNNING;
    player->z_index = PLAYER_DISPLAY;
    player->anim = malloc(sizeof(anim_t) * 10);
    if (player->anim == NULL)
        return (NULL);
    else
        init_player_anim(player->anim);
    player->delta_t = NULL;
    player->sound_effect = sfSound_create();
    if (player->anim == NULL || player->sound_effect == NULL)
        return (NULL);
    init_game_object_frame(player);
    return (player);
}