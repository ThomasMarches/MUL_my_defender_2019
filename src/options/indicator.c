/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** indicator
*/

#include "my_defender.h"
#include <SFML/Audio.h>

bool update_indicator(game_object_t *object, scene_t *scene)
{
    int vol = sfListener_getGlobalVolume() / VOLUME_UNIT;

    object->pos.x = (float)INDICATOR_X + (BAR_WIDTH / VOLUME_UNIT) * (vol - 1);
    sfSprite_setPosition(object->sprite, object->pos);
    update_appearing_object(object, scene);
    return (true);
}

game_object_t *create_indicator(game_object_t *last, char *path, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, DECOR);

    object->update = &update_indicator;
    object->type = DECOR;
    object->callback = NULL;
    object->z_index = 0;
    init_appearing_object(object);
    return (object);
}