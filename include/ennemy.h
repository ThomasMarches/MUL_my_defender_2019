/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** define
*/

#ifndef ENNEMY_H_
#define ENNEMY_H_

typedef struct ennemy {
    sfVector2f *path;
    int slow;
    int life;
    int position_on_map;
} ennemy_t;

game_object_t *create_ennemy(game_object_t *, int);

#endif /* !ENNEMY_H_ */
