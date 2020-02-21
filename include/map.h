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
    SPIKE = 50
} tile_id;

game_object_t *init_background(game_object_t *);
game_object_t *init_player_ground(game_object_t *, char *);
bool update_tile(game_object_t *, scene_t *);
char *read_map(char *);
game_object_t *start_chunks(game_object_t *);

game_object_t *create_spike(game_object_t *, sfVector2f);
game_object_t *create_ground(game_object_t *, sfVector2f);

game_object_t *generate_trap(game_object_t *, game_object_t *);
game_object_t *generate_mobs(game_object_t *);
game_object_t *generate_layer(game_object_t *, game_object_t *);
game_object_t *generate_ground(game_object_t *, game_object_t *);
game_object_t *generate_floor(game_object_t *, float, int, int);
game_object_t *create_layer(game_object_t *, int, int, int);

#endif /* !MAP_H_ */
