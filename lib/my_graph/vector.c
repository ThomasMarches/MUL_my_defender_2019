/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** vector
*/

#include "my_graph.h"
#include <SFML/Graphics.h>

sfVector2f move_vector(int start_x, int start_y, int dest_x, int dest_y)
{
    sfVector2f vector;

    vector.x = (dest_x - start_x) / 40;
    vector.y = (dest_y - start_y) / 40;

    return (vector);
}