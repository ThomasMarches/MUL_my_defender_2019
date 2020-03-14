/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** upgrade_tower.c
*/

#include "my_defender.h"
#include "tower.h"
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

tower_t *create_upgrading_content(tower_t *tower, sfVector2f pos)
{
    sfVector2f position = pos;

    position.y -= 50;
    tower->upgrade_text = sfTexture_createFromFile(UPGRADE_BUTTON_PATH, NULL);
    tower->upgrade_spr = sfSprite_create();
    sfSprite_setTexture(tower->upgrade_spr, tower->upgrade_text, sfTrue);
    sfSprite_setPosition(tower->upgrade_spr, position);
    tower->display_upgrade = 0;
    tower->upgrade_txt = init_text(my_nbr_to_str(tower->upgrade_cost),
    pos.x + 50, pos.y - 50, (char *) FONT_PATH);
    return (tower);
}

tower_t *upgrade_tower(tower_t *tower, tower_type_t type, int n)
{
    if (tower->level == 3)
        return (tower);
    tower->level = n;
    tower->delay = 0;
    tower->aoe = get_int_from_param(tower->tower_param, 7, n);
    tower->slow = get_int_from_param(tower->tower_param, 6, n);
    tower->draw_range = 0;
    tower->attack_speed = get_int_from_param(tower->tower_param, 4, n);
    tower->damage = get_int_from_param(tower->tower_param, 3, n);
    tower->range = get_int_from_param(tower->tower_param, n, n);
    tower->cost = get_int_from_param(tower->tower_param, 1, n);
    tower->upgrade_cost = get_int_from_param(tower->tower_param, 1, n + 1);
    sfText_setString(tower->upgrade_txt, my_nbr_to_str(tower->upgrade_cost));
    return (tower);
}