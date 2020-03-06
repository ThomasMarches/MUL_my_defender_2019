/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;
typedef struct scene scene_t;

typedef enum {
    FRONT,
    PLAYER_GROUND,
    PLAYER_DISPLAY,
} z_index_game;

typedef enum {
    GROUND_GENERATION,
    LAYER_GENERATION,
    TRAP_GENERATION,
    MOBS_GENERATION,
} chunk_generation_state;

typedef enum {
    GROUND = 49,
    GRASS = 50,
    BASE = 51,
    ROCK = 52
} tile_id;

game_object_t *generate_map(game_object_t *, char *);
char *get_map(char *);
int is_map_valid(char *, char *);
game_object_t *create_tower_menu(game_object_t *);

#endif /* !MAP_H_ */
