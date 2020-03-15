/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** update_tower_sprite
*/

#include "my_defender.h"

void update_tower_sprite(game_object_t *object)
{
    int level = ((tower_t *)object->extend)->level - 1;

    switch (((tower_t *)object->extend)->type) {
    case 1:
        sfSprite_setTextureRect(object->sprite, *TOWER1_TEXTURE_RECT[level]);
        break;
    case 2:
        sfSprite_setTextureRect(object->sprite, *TOWER2_TEXTURE_RECT[level]);
        break;
    case 3:
        sfSprite_setTextureRect(object->sprite, *TOWER3_TEXTURE_RECT[level]);
        break;
    case 4:
        sfSprite_setTextureRect(object->sprite, *TOWER4_TEXTURE_RECT[level]);
        break;
    }
}