/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** ground
*/

#include "my_defender.h"
#include <stdlib.h>

game_object_t *create_ground(game_object_t *last, sfVector2f pos)
{
    last = create_game_object(last, (char *)GROUND_PATH, pos, SOLID);
    if (last == NULL)
        return (NULL);
    last->move = (sfVector2f) {PLAYER_DASH_SPEED, 0};
    last->box = (sfIntRect) {(int) pos.x, (int) pos.y, GROUND_WIDTH, \
    GROUND_HEIGHT};
    last->z_index = PLAYER_GROUND;
    last->update = &update_tile;
    return (last);
}

game_object_t *generate_floor(game_object_t *last, float start_x, int width, \
int height)
{
    int sign = rand() % 2;

    if (sign == 0)
        height -= (rand() % 5) * TILE_HEIGHT;
    else
        height += (rand() % 5) * TILE_HEIGHT ;
    if (height / TILE_HEIGHT < 2)
        height = TILE_HEIGHT * 2;
    else if (height > TILE_MAX_HEIGHT)
        height = TILE_MAX_HEIGHT;
    for (int i = 0; i < width; i++) {
        last = create_ground(last, (sfVector2f) \
        {(float) (start_x + i * TILE_WIDTH), (float) height});
    }
    return (last);
}