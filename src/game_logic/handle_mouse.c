/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** handle_mouse
*/

#include "my_runner.h"

void is_click_on_object(scene_t *scene, sfMouseButtonEvent mouse_button, \
game_t *game)
{
    game_object_t *object = scene->objects_list;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window->window);
    int x = pos.x;
    int y = pos.y;

    if (mouse_button.button != sfMouseLeft)
        return;
    for (; object; object = object->next) {
        if (object->callback != NULL && sfIntRect_contains(&object->box, x, y))
            object->callback(object, scene);
    }
}