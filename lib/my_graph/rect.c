/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** rect
*/

#include <SFML/Graphics.h>

sfIntRect update_rect(int height, int width, int x, int y)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.top = y;
    rect.left = x;
    return (rect);
}