/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** bars
*/

#include "my_defender.h"
#include <SFML/Audio.h>

bool update_bar(game_object_t *bar, scene_t *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    int vol = sfListener_getGlobalVolume() / VOLUME_UNIT;
    int bar_width = BAR_WIDTH / VOLUME_UNIT;
    int bar_pos_x = VOLUME_BAR_X;
    sfIntRect rect = {0, 0, BAR_WIDTH, BAR_HEIGHT};

    if (bar->state == SELECTED)
        vol = (pos.x - bar_pos_x) / bar_width;
    if (!sfMouse_isButtonPressed(sfMouseLeft))
            bar->state = UNSELECTED;
    if (vol > MAX_VOLUME / VOLUME_UNIT)
        vol = MAX_VOLUME / VOLUME_UNIT;
    else if (vol < MIN_VOLUME)
        vol = MIN_VOLUME;
    rect.width = bar_width * vol;
    sfListener_setGlobalVolume(vol * VOLUME_UNIT);
    sfSprite_setTextureRect(bar->sprite, rect);
    update_appearing_object(bar, scene);
    return (true);
}

void bar_function(game_object_t *object, void *pt)
{
    object->state = SELECTED;
}

game_object_t *create_bar(game_object_t *last, char *path, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, BAR);

    object->state = UNSELECTED;
    object->callback = &bar_function;
    object->update = &update_bar;
    init_appearing_object(object);
    return (object);
}