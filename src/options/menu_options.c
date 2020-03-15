/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu_options
*/

#include "my_defender.h"
#include <stdlib.h>

static game_object_t *create_option_object_list2(game_object_t *object)
{
    object = create_game_object(object, (char *) BAR_BACKGROUND_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_game_object(object, (char *)BACKGROUND_INFO, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    return (object);
}

static game_object_t *create_option_object_list(void)
{
    game_object_t *object = NULL;

    object = create_game_object(object, (char *)OPTION_TITLE, (sfVector2f) \
    {OPTION_TITLE_X, OPTION_TITLE_Y}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_animated_object(object, (char *)TITLE_UNDERLINE_PATH, \
    (sfVector2f) {TITLE_UNDERLINE_X, TITLE_UNDERLINE_Y}, \
    (sfIntRect **)TITLE_UNDERLINE_FRAME_KEYS);
    object->type = FLEUR;
    object = create_indicator(object, (char *)INDICATOR_PATH, \
    (sfVector2f) {INDICATOR_X, INDICATOR_Y});
    object = create_bar(object, (char *) BAR_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y});
    object->box = (sfIntRect) {VOLUME_BAR_X - BAR_BOX_OFFSET / 2, \
    VOLUME_BAR_Y, BAR_WIDTH, BAR_HEIGHT + BAR_BOX_OFFSET};
    return (create_option_object_list2(object));
}

void draw_options(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text((char *)GLOBAL_VOLUME_TEXT, VOLUME_BAR_X - 270, \
    VOLUME_BAR_Y - 45, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    display_scene(scene, window);
    sfRenderWindow_drawText(window, text, NULL);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_display(window);
    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

scene_t *init_options_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->display = OPTION_SCENE;
    scene->handle_event = &handle_event_options;
    scene->z_index_deepth = 0;
    scene->objects_list = create_option_object_list();
    scene->objects_list = create_text_button(scene->objects_list, (char *) \
    RETURN_BUTTON_PATH, (sfVector2f) {RETURN_BUTTON_X, RETURN_BUTTON_Y});
    scene->objects_list->callback = &return_button_function;
    if (scene->objects_list == NULL)
        return (NULL);
    scene->window = game->window->window;
    return (scene);
}