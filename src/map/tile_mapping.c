/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** map
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

void callback_tile(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    tower_type_t type = 0;
    game_object_t *tmp = NULL;

    if (object->type != GRASS)
        return;
    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next) {
        if (tmp->type == TOWER_MENU)
            type = tmp->state;
        if ((tmp != object && object->pos.x == tmp->pos.x && \
        object->pos.y == tmp->pos.y))
            return;
    }
    tmp = create_tower(scene->objects_list, object->pos, type);
    scene->objects_list = (tmp != NULL) ? tmp : scene->objects_list;
}

game_object_t *generate_tile(game_object_t *last, int id, int x, int y)
{
    switch (id) {
    case '2':
        return (create_game_object(last, (char *) GROUND_PATH, (sfVector2f) {x, y}, GROUND));
        break;
    case '1':
        return (create_game_object(last, (char *) GRASS_PATH, (sfVector2f) {x, y}, GRASS));
        break;
    case '3':
        return (create_game_object(last, (char *) ROCK_PATH, (sfVector2f) {x, y}, ROCK));
        break;
    case '5':
        return (create_game_object(last, (char *) BASE_PATH, (sfVector2f) {x - 100, y - 120}, BASE));
        break;
    default:
        return (NULL);
    }
}

game_object_t *generate_map(game_object_t *last, char *path)
{
    char **map = my_str_to_word_array(get_map(path), "\n");
    int i = 0;
    game_object_t *tmp = NULL;

    if (is_map_valid(get_map(path), path) == 84)
        return (NULL);
    for (; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            tmp = generate_tile(last, map[i][j], j * TILE_WIDTH, i *
            TILE_HEIGHT);
            last = (tmp != NULL) ? tmp : last;
            last->callback = &callback_tile;
            last->z_index = 4;
            last->z_index = (tmp != NULL && map[i][j] == '5') ? 0 : last->z_index;
            last->box = (sfIntRect) {last->pos.x, last->pos.y, TILE_WIDTH, TILE_HEIGHT};
        }
        free(map[i]);
    }
    free(map[i]);
    free(map);
    return (last);
}