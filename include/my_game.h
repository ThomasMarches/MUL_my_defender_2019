/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** my_game
*/

#ifndef MY_GAME_H_
#define MY_GAME_H_

#include <SFML/Graphics.h>

#include "game_object.h"
#include "scene.h"
#include "menu.h"
#include "my_graph.h"

typedef struct game game_t;
typedef struct score score_t;
typedef struct cursor cursor_t;

////////////////////////////////////////////////////////////
/// \brief Structure containing global variable of the game
////////////////////////////////////////////////////////////
typedef struct game {
    window_t *window;                                       /**< Struct window, from my_graph lib, used to handle the variable of the window*/
    char *map;                                              /**< String representing the map of the game*/
    int difficulty;
    int (*scene_loop[5]) (game_t *, sfRenderWindow *);      /**< Array of function for all scene*/
    game_object_t *player;                                  /**< Struct game_object reference to the main object of the game*/
    score_t *score;                                         /**< Struct that handle the text variable for the score*/
    score_t *highscore;                                     /**< Struct that handle the text variable for the highscore*/
    cursor_t cursor;                                        /**< Struct cursor to handle cursor image and pos*/
}game_t;

#endif /* !MY_GAME_H_ */
