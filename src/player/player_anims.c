/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** player_anims
*/

#include "my_runner.h"
#include <stdlib.h>

void init_player_attack_anim(anim_t *anims)
{
    anims[ATTACKING_TOP].frames_key = \
    (sfIntRect **)PLAYER_ATTACKING_TOP_FRAME_KEYS;
    anims[ATTACKING_TOP].loop = false;
    anims[ATTACKING_TOP].frame_id = 0;
    anims[ATTACKING_TOP].restart_id = 0;
    anims[ATTACKING_DOWN].frames_key = \
    (sfIntRect **)PLAYER_ATTACKING_DOWN_FRAME_KEYS;
    anims[ATTACKING_DOWN].loop = false;
    anims[ATTACKING_DOWN].frame_id = 0;
    anims[ATTACKING_DOWN].restart_id = 0;
    anims[ATTACKING_RIGHT].frames_key = \
    (sfIntRect **)PLAYER_ATTACKING_RIGHT_FRAME_KEYS;
    anims[ATTACKING_RIGHT].loop = false;
    anims[ATTACKING_RIGHT].frame_id = 0;
    anims[ATTACKING_RIGHT].restart_id = 0;
}

void init_player_other_anim(anim_t *anims)
{
    anims[DASHING].frames_key = (sfIntRect **)PLAYER_DASHING_FRAME_KEYS;
    anims[DASHING].loop = false;
    anims[DASHING].frame_id = 0;
    anims[DASHING].restart_id = 0;
    anims[DOUBLE_JUMPING].frames_key = \
    (sfIntRect **)PLAYER_DOUBLE_JUMPING_FRAME_KEYS;
    anims[DOUBLE_JUMPING].loop = false;
    anims[DOUBLE_JUMPING].frame_id = 0;
    anims[DOUBLE_JUMPING].restart_id = 0;
    anims[DEAD].frames_key = (sfIntRect **)PLAYER_RUNNING_FRAME_KEYS;
    anims[DEAD].loop = false;
    anims[DEAD].frame_id = 0;
    anims[DEAD].restart_id = 0;
}

void init_player_anim(anim_t *anims)
{
    anims[9].sound_buffer = NULL;
    anims[RUNNING].frames_key = (sfIntRect **)PLAYER_RUNNING_FRAME_KEYS;
    anims[RUNNING].loop = true;
    anims[RUNNING].frame_id = 0;
    anims[RUNNING].restart_id = 0;
    anims[JUMPING].frames_key = (sfIntRect **)PLAYER_JUMPING_FRAME_KEYS;
    anims[JUMPING].loop = true;
    anims[JUMPING].frame_id = 0;
    anims[JUMPING].restart_id = 0;
    anims[FALLING].frames_key = (sfIntRect **)PLAYER_FALLING_FRAME_KEYS;
    anims[FALLING].loop = true;
    anims[FALLING].frame_id = 0;
    anims[FALLING].restart_id = 4;
    init_player_other_anim(anims);
    init_player_attack_anim(anims);
    init_player_anim_sound_effect(anims);
    init_player_attack_sound_effect(anims);
}