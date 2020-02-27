/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** chunk
*/

#include "my_defender.h"
#include <stdlib.h>

game_object_t *create_chunk(game_object_t *, unsigned int);

game_object_t *generate_chunk(game_object_t *chunk, game_object_t *list)
{
    switch (chunk->state) {
        case GROUND_GENERATION:
            list = generate_ground(list, chunk);
            break;
        case LAYER_GENERATION:
            list = generate_layer(list, chunk);
            break;
        case TRAP_GENERATION:
            list = generate_trap(list, chunk);
            break;
        case MOBS_GENERATION:
            list = generate_mobs(list);
            break;
    }
    chunk->state += 1;
    sfClock_restart(chunk->delta_t);
    return (list);
}

bool update_chunk(game_object_t *chunk, scene_t *scene)
{
    sfTime time = {0};

    if (chunk->delta_t != NULL) {
        time = sfClock_getElapsedTime(chunk->delta_t);
        if (time.microseconds >= 1000000)
            scene->objects_list = generate_chunk(chunk, scene->objects_list);
        if (chunk->state > 3) {
            sfClock_destroy(chunk->delta_t);
            chunk->delta_t = NULL;
        }
    }
    move_object(chunk);
    if (chunk->pos.x < 0.0) {
        scene->objects_list = create_chunk(scene->objects_list, \
        (int)chunk->pos.x + CHUNK_WIDTH * 2);
        return (false);
    }
    return (true);
}

game_object_t *create_chunk(game_object_t *last, unsigned int x)
{
    game_object_t *chunk = malloc(sizeof(game_object_t));

    if (chunk == NULL)
        return (NULL);
    init_game_object(chunk);
    chunk->update = &update_chunk;
    chunk->sprite = sfSprite_create();
    chunk->delta_t = sfClock_create();
    chunk->next = last;
    chunk->type = CHUNK;
    chunk->pos = (sfVector2f) {(float)x, 0};
    chunk->move = (sfVector2f) {PLAYER_DASH_SPEED, 0};
    return (chunk);
}

game_object_t *start_chunks(game_object_t *last)
{
    int height = TILE_MAX_HEIGHT;
    game_object_t *chunk = NULL;

    for (int i = 0; i < TILES_PER_CHUNK; i++) {
        last = create_ground(last, (sfVector2f) {i * TILE_WIDTH, height});
    }
    last = create_chunk(last, 0);
    last->state = 3;
    last = create_chunk(last, CHUNK_WIDTH);
    chunk = last;
    last = generate_chunk(chunk, last);
    last = generate_chunk(chunk, last);
    last = generate_chunk(chunk, last);
    last = generate_chunk(chunk, last);
    return (last);
}