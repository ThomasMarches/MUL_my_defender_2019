/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_menu
*/

#include "tower.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_defender.h"

void callback_tower_menu(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(scene->window);
    int id = (mouse_pos.x - object->pos.x) / 125;

    if (id < 0 || id > 3)
        return;
    object->state = id + 1;
}

game_object_t *create_tower_menu(game_object_t *last)
{
    game_object_t *menu = create_game_object(last, (char *) TOWER_MENU_PATH, (sfVector2f) {20, 810}, TOWER_MENU);

    if (menu == NULL)
        return (last);
    menu->z_index = 3;
    menu->callback = &callback_tower_menu;
    menu->box = (sfIntRect) {20, 850, 500, 138};
    return (menu);
}