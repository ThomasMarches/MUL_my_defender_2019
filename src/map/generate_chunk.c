/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** generate_chunk
*/

#include "my_defender.h"
#include <stdlib.h>
#include <time.h>

game_object_t *generate_ground(game_object_t *last, game_object_t *chunk)
{
    int width = 0;
    int height = TILE_MAX_HEIGHT;
    bool was_last_a_pit = false;

    srand(time(NULL));
    for (int i = 0; i < CHUNK_WIDTH;) {
        width = rand() % MAX_FLOOR_WIDTH;
        width = (width > 0) ? width : 1;
        if (width * TILE_WIDTH + i > CHUNK_WIDTH)
            width = (CHUNK_WIDTH - i) / TILE_WIDTH;
        if (i == 0 || i + width * TILE_WIDTH == CHUNK_WIDTH || rand() % 4 > 0 \
        || was_last_a_pit == true) {
            last = generate_floor(last, chunk->pos.x + (float)i, width, height);
            height = (int)last->pos.y;
            was_last_a_pit = false;
        } else
            was_last_a_pit = true;
        i += (width * TILE_WIDTH);
    }
    return (last);
}

game_object_t *generate_layer(game_object_t *last, game_object_t *chunk)
{
    int width = 0;
    int height = TILE_MAX_HEIGHT;

    srand(time(NULL));
    for (game_object_t *object = last; object; object = object->next) {
        width = (rand() % MAX_FLOOR_WIDTH);
        if (object->type == SOLID && object->pos.x >= chunk->pos.x\
        && rand() % 3 == 0) {
            height = object->pos.y - ((rand() % 3) + 4) * TILE_HEIGHT;
            last = create_layer(last, object->pos.x, width, height);
        }
    }
    return (last);
}

game_object_t *generate_trap(game_object_t *last, game_object_t *chunk)
{
    for (game_object_t *object = last; object; object = object->next) {
        if (object->type == SOLID && object->pos.x >= chunk->pos.x\
        && rand() % 10 == 0) {
            last = create_spike(last, (sfVector2f) {object->pos.x, \
            object->pos.y - TILE_HEIGHT * 2});
        }
    }
    return (last);
}

game_object_t *generate_mobs(game_object_t *last)
{
    return (last);
}