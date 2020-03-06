/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_object
*/

#include "game_object.h"

void draw_object(sfRenderWindow *window, game_object_t *object)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void draw_objects(game_object_t *object, sfRenderWindow *window, \
int z_index_max)
{
    game_object_t *tmp = object;

    if (object == NULL)
        return;
    for (int i = z_index_max; i >= 0;) {
        if (object->texture != NULL && object->z_index == i && object->draw \
        != NULL)
            object->draw(window, object);
        object = object->next;
        if (object == NULL) {
            object = tmp;
            i--;
        }
    }
}