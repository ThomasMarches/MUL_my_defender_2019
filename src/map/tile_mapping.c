/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** map
*/

#include "my_defender.h"
#include "my.h"

int is_map_valid(char *map, char *map_name);

void callback_tile(game_object_t *object, scene_t *scene)
{

}

game_object_t *generate_tile(game_object_t *last, int id, int x, int y)
{
    game_object_t *tile = NULL;

    switch (id) {
    case '2':
        tile = create_game_object(last, GROUND_PATH, (sfVector2f) {x, y},
        GROUND);
        break;
    case '1':
        tile = create_game_object(last, GRASS_PATH, (sfVector2f) {x, y}, GRASS);
        break;
    // etc...
    }
    if (tile == NULL)
        return (NULL);
    tile->callback = &callback_tile;
    return (tile);
}

game_object_t *generate_map(game_object_t *last, char *path)
{
    char **map = my_str_to_word_array(get_map(path), "\n"); // recupére la map;
    game_object_t *tmp = NULL;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            tmp = generate_tile(last, map[i][j], j * TILE_WIDTH, i *
            TILE_HEIGHT);
            last = (tmp != NULL) ? tmp : last;
        }
    return (last);
}