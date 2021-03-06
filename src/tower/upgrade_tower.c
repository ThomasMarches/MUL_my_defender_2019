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

void update_tower_circle(tower_t *tower)
{
    int calc = tower->range * 65;
    sfVector2f position = {0, 0};

    position.x = tower->pos.x - calc + 30.5;
    position.y = tower->pos.y - calc + 34;
    sfCircleShape_setRadius(tower->circle, tower->range * 65);
    sfCircleShape_setPosition(tower->circle, position);
    tower->draw_range = 0;
    tower->display_upgrade = 0;
}

void upgrade_tower(tower_t *tower, tower_type_t type)
{
    char *tmp = NULL;

    tower->level += 1;
    tower->delay = 0;
    tower->aoe = get_int_from_param(tower->tower_param, 7, tower->level);
    tower->slow = get_int_from_param(tower->tower_param, 6, tower->level);
    tower->draw_range = 0;
    tower->attack_speed = get_int_from_param(tower->tower_param, 4, \
    tower->level);
    tower->damage = get_int_from_param(tower->tower_param, 3, tower->level);
    tower->range = get_int_from_param(tower->tower_param, 2, \
    tower->level);
    tower->cost = get_int_from_param(tower->tower_param, 1, tower->level);
    tower->upgrade_cost = get_int_from_param(tower->tower_param, 1, \
    tower->level + 1);
    update_tower_circle(tower);
    tmp = my_nbr_to_str(tower->upgrade_cost);
    sfText_setString(tower->upgrade_txt, tmp);
    free(tmp);
}

void draw_upgrade_button(sfRenderWindow *window, game_object_t *object)
{
    if (object->state == 1)
        sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void upgrade_button_callback(game_object_t *object, void *pt)
{
    game_object_t *tower = ((game_object_t *) object->extend);

    if (((tower_t *)tower->extend)->level < 3 && update_money(object, \
    ((tower_t *)tower->extend)->upgrade_cost))
        upgrade_tower(tower->extend, ((tower_t *)tower->extend)->type);
    return;
}

void create_upgrading_content(tower_t *tower, sfVector2f pos, \
game_object_t *object)
{
    sfVector2f position = pos;
    char *tmp = NULL;

    position.y -= 50;
    tower->button = create_game_object(object, (char *) UPGRADE_BUTTON_PATH, \
    pos, UPGRADE_BUTTON);
    if (tower->button != NULL) {
        tower->button->callback = &upgrade_button_callback;
        tower->button->box = (sfIntRect) {pos.x, pos.y, 50, 50};
        tower->button->draw = &draw_upgrade_button;
        tower->button->extend = object;
    }
    tower->display_upgrade = 0;
    tmp = my_nbr_to_str(tower->upgrade_cost);
    tower->upgrade_txt = init_text(tmp, \
    pos.x + 50, pos.y - 50, (char *) FONT_PATH);
    free(tmp);
}