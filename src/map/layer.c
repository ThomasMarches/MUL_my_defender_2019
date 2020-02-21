/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** layer
*/

#include "my_runner.h"

game_object_t *create_layer(game_object_t *last, int start_x, int width, \
int height) {
    sfIntRect layer_check_box = {start_x - TILE_WIDTH, height - 3 * \
    TILE_HEIGHT, (width + 3) * TILE_WIDTH, 7 * TILE_HEIGHT};

    if (height < 0)
        return (last);
    for (game_object_t *object = last; object; object = object->next) {
        if (object->type == SOLID && \
        sfIntRect_intersects(&layer_check_box, &object->box, NULL))
            return (last);
    }
    for (int i = 0; i < width; i++) {
        last = create_ground(last, (sfVector2f) \
        {(float) (start_x + i * TILE_WIDTH), (float) height});
    }
    return (last);
}