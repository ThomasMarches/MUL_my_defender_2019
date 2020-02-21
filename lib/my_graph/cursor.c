/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** cursor
*/

#include "my_graph.h"

cursor_t init_cursor(char *path)
{
    cursor_t cursor;
    sfFloatRect rect;

    cursor.texture = sfTexture_createFromFile(path, NULL);
    cursor.sprite = sfSprite_create();
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    rect = sfSprite_getLocalBounds(cursor.sprite);
    cursor.width = (int)rect.width;
    cursor.height = (int)rect.height;
    cursor.displayed = sfTrue;
    return (cursor);
}

void draw_cursor(cursor_t cursor, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_float;

    if (cursor.displayed == sfTrue) {
        pos_float.x = pos.x - cursor.width / 2;
        pos_float.y = pos.y - cursor.height / 2;
        sfSprite_setPosition(cursor.sprite, pos_float);
        sfRenderWindow_drawSprite(window, cursor.sprite, NULL);
    }
}