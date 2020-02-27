/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** spikes
*/

#include "my_defender.h"

game_object_t *create_spike(game_object_t *last, sfVector2f pos)
{
    last = create_game_object(last, (char *)SPIKES_PATH, pos, TRAP);
    if (last == NULL)
        return (NULL);
    last->move = (sfVector2f) {PLAYER_DASH_SPEED, 0};
    last->box = (sfIntRect) {(int) pos.x, (int) pos.y, SPIKE_WIDTH, \
    SPIKE_HEIGHT};
    last->z_index = PLAYER_GROUND;
    last->update = &update_tile;
    return (last);
}