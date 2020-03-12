/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_board.c
*/

#include <math.h>
#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

bool is_ennemy_in_range(game_object_t *object, game_object_t *ennemy)
{
    int distance1 = 0;
    int distance2 = 0;
    tower_t *tower = (tower_t *) object->extend;

    if (ennemy->type != ENNEMY)
        return (false);
    distance1 = (ennemy->pos.x - object->pos.x) *
    (ennemy->pos.x - object->pos.x);
    distance2 = (ennemy->pos.y - object->pos.y) *
    (ennemy->pos.y - object->pos.y);
    if (sqrt(distance1 + distance2) < tower->range * 65)
        return (true);
    return (false);
}

void shoot_aoe(game_object_t *object, game_object_t *tmp, scene_t *scene)
{
    game_object_t *reference = tmp;
    tower_t *tower = (tower_t *) object->extend;
    ennemy_t *ennemy = (ennemy_t *) tmp->extend;

    for (tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (reference->pos.x - tmp->pos.x < 50 && reference->pos.x - tmp->pos.x > 0
        && reference->pos.y - tmp->pos.y < 50 && reference->pos.y - tmp->pos.y > 0)
            ennemy->life = ennemy->life - tower->aoe;
}

void shoot_on_ennemy(game_object_t *object, game_object_t *tmp, scene_t *scene)
{
    tower_t *tower = (tower_t *) object->extend;
    ennemy_t *ennemy = (ennemy_t *) tmp->extend;

    if (tower->slow != 0)
        ennemy->slow = tower->slow;
    if (tower->aoe != 0)
        shoot_aoe(object, tmp, scene);
    else
        ennemy->life = ennemy->life - tower->damage;
    scene->objects_list = create_bullet(scene->objects_list, object->pos,
    tower->type);
    set_bullet_vector(scene->objects_list, tmp);
}

void get_ennemy_to_shoot(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp = NULL;
    game_object_t *tmp2 = NULL;
    int walk = 0;

    for (tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (tmp->type == ENNEMY && ((ennemy_t *) tmp->extend)->position_on_map > walk
        && is_ennemy_in_range(object, tmp)) {
            tmp2 = tmp;
            walk = ((ennemy_t *) tmp->extend)->position_on_map;
        }
    if (tmp2 == NULL)
        return;
    shoot_on_ennemy(object, tmp2, scene);
}