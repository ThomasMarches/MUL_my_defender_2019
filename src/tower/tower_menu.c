/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_menu
*/

#include "my_defender.h"

void callback_tower_menu(game_object_t *object, void *pt)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow((sfRenderWindow *) pt);
    int id = mouse_pos.x % 60;

    if (id < 1 || id > 4)
        return;
    object->state = id;
}

game_object_t *create_tower_menu(game_object_t *last)
{
    game_object_t *menu = create_game_object(last, TOWER_MENU_PATH, (sfVector2f) {1550, 1000}, TOWER_MENU);

    menu->z_index = 2;
    menu->state = 0;
    menu->callback = &callback_tower_menu;
    return (menu);
}