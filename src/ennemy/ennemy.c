/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy
*/

#include "my_defender.h"
#include <stdlib.h>

bool update_ennemy(game_object_t *object, scene_t *scene)
{
    static int frame= 0;
    ennemy_t *ennemy = (ennemy_t *) object->extend;

    if (ennemy->life <= 0)
        return (false);
    ennemy->position_on_map += 1;
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    if (object->pos.x > WINDOW_WIDTH)
        return (false);
    sfSprite_setPosition(object->sprite, object->pos);
    frame++;
    if (frame == 4) {
        frame = 0;
        update_game_object_frame(object);
    }
    return (true);
}


ennemy_t *create_ennemy_struct(int i)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->position_on_map = -i;
    ennemy->slow = 0;
    ennemy->life = 1000;
    return (ennemy);
}

void init_ennemy_anim(game_object_t *object)
{
    object->anim[0].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[0].loop = true;
    object->anim[0].frame_id = 0;
    object->anim[0].restart_id = 0;
    object->anim[1].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[1].loop = true;
    object->anim[1].frame_id = 0;
    object->anim[1].restart_id = 0;
    object->anim[2].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[2].loop = true;
    object->anim[2].frame_id = 0;
    object->anim[2].restart_id = 0;
    object->anim[3].frames_key = (sfIntRect **) FIRST_ENNEMY_RECT_RIGHT;
    object->anim[3].loop = true;
    object->anim[3].frame_id = 0;
    object->anim[3].restart_id = 0;
}

game_object_t *create_ennemy(game_object_t *last, int i)
{
    game_object_t *object = create_game_object(last, \
    "templates/mobs/ennemy.png", (sfVector2f) {- i * TILE_WIDTH, 0}, ENNEMY);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) create_ennemy_struct(i);
    if (object->extend == NULL) {
        free(object);
        return (NULL);
    }
    object->anim = malloc(sizeof(anim_t) * 4);
    init_ennemy_anim(object);
    object->state = 0;
    object->update = &update_effect;
    object->move = (sfVector2f) {5, 0};
    init_game_object_frame(object);
    object->update = &update_ennemy;
    object->z_index = 2;
    return (object);
}