/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_wave.c
*/

#include "my.h"
#include "my_defender.h"
#include "ennemy.h"
#include "my_game.h"
#include <solver.h>
#include <stdlib.h>

void generate_ennemys(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp = NULL;

    for (int i = 0; i < object->state; i++) {
        tmp = create_ennemy(scene->objects_list, i, (map_t *) object->extend);
        scene->objects_list = (tmp) ? tmp : scene->objects_list;
    }
}

bool update_wave(game_object_t *object, scene_t *scene)
{
    static int delay = -150;
    game_object_t *tmp2 = NULL;

    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next) {
        if (tmp->type == ENNEMY)
            return (true);
        if (tmp->type == TOWER_BOARD)
            tmp2 = tmp;
    }
    delay++;
    if (delay == 150) {
        object->state += 1;
        generate_ennemys(object, scene);
        delay = 0;
        increase_board_value(((board_t *) tmp2->extend)->wave, 1, "Wave : ");
    }
    return (true);
}

map_t *compute_path(void)
{
    char *raw_map = get_map("maps/map");
    map_t *map_s = malloc(sizeof(map_t));

    if (map_s == NULL || raw_map == NULL) {
        if (map_s != NULL)
            free(map_s);
        if (raw_map != NULL)
            free(raw_map);
        return (NULL);
    }
    *map_s = init_map(raw_map);
    if (map_s->map == NULL) {
        free(map_s);
        return (NULL);
    }
    else if (solve(map_s) == 84) {
        free(map_s->map);
        free(map_s);
        return (NULL);
    }
    return (map_s);
}

game_object_t *init_wave(game_object_t *last)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    init_game_object(object);
    object->draw = NULL;
    object->next = last;
    object->state = 0;
    object->update = &update_wave;
    object->extend = (void *) compute_path();
    if (object->extend == NULL) {
        printf("NUL\n");
        free(object);
        return (NULL);
    }
    return (object);
}