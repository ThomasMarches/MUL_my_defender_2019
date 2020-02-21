/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** player_ground
*/

#include "my_runner.h"
#include <SFML/Graphics.h>

bool update_tile(game_object_t *object, scene_t *scene)
{
    move_object(object);
    if (object->pos.x < - (float)object->box.width)
        return (false);
    return (true);
}

game_object_t *compute_tile(game_object_t *last, char id, sfVector2f pos)
{
    switch (id) {
        case GROUND:
            return (create_ground(last, pos));
            break;
        case SPIKE:
            return (create_spike(last, pos));
    }
    return (last);
}

game_object_t *init_player_ground(game_object_t *last, char *map)
{
    int x = 0;
    int y = 0;
    bool is_first = true;

    if (map == NULL)
        return (start_chunks(last));
    for (int i = 0; map[i] != '\0'; i++, x++) {
        if (map[i] == '\n') {
            y++;
            x = -1;
        } else if (map[i] != ' ') {
            last = compute_tile(last, map[i], \
            (sfVector2f){x  * TILE_WIDTH, y * TILE_HEIGHT});
            is_first = false;
        }
        if (is_first == false && last == NULL)
            return (NULL);
    }
    return (last);
}