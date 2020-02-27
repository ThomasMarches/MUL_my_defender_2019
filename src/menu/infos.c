/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** infos
*/

#include "my_defender.h"
#include <stdlib.h>

game_object_t *create_infos_objects(void)
{
    game_object_t *object = NULL;

    object = create_game_object(object, (char *)INFOS_TITLE, (sfVector2f) \
    {INFOS_TITLE_X, INFOS_TITLE_Y}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_animated_object(object, (char *)TITLE_UNDERLINE_PATH, \
    (sfVector2f) {TITLE_UNDERLINE_X, TITLE_UNDERLINE_Y}, \
    (sfIntRect **)TITLE_UNDERLINE_FRAME_KEYS);
    object->type = FlEUR;
    object = create_animated_object(object, (char *)INFOS_CONTENT_PATH, \
    (sfVector2f) {0, 0}, (sfIntRect **)INFOS_CONTENT_FRAME_KEYS);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object->type = INFO;
    object = create_button(object, (char *) ARROW_PATH, (sfVector2f) \
    {INFOS_ARROW_LEFT_X, INFOS_ARROW_Y}, (sfIntRect **)ARROW_LEFT_FRAME_KEYS);
    object->callback = &infos_left_arrow_function;
    object = create_button(object, (char *) ARROW_PATH, (sfVector2f) \
    {INFOS_ARROW_RIGHT_X, INFOS_ARROW_Y}, (sfIntRect **)ARROW_RIGHT_FRAME_KEYS);
    object->callback = &infos_right_arrow_function;
    return (object);
}

scene_t *create_infos_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_infos;
    scene->z_index_deepth = 0;
    scene->objects_list = create_infos_objects();
    scene->objects_list = create_text_button(scene->objects_list, (char *) \
    RETURN_BUTTON_PATH, (sfVector2f) {RETURN_BUTTON_X, RETURN_BUTTON_Y});
    scene->objects_list->callback = &return_button_function;
    return (scene);
}