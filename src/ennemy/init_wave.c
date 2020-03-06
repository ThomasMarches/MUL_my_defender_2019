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
#include <stdlib.h>

void generate_ennemys(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp = NULL;

    for (int i = 0; i < object->state; i++) {
        tmp = create_ennemy(scene->objects_list);
        scene->objects_list = (tmp) ? tmp : scene->objects_list;
    }
}

bool update_wave(game_object_t *object, scene_t *scene)
{
    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (tmp->type == ENNEMY)
            return (true);
    object->state += 1;
    generate_ennemys(object, scene);
    return (true);
}

game_object_t *init_wave(game_t *game, game_object_t *last)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    init_game_object(object);
    object->draw = NULL;
    object->update = &update_wave;
    return (object);
}