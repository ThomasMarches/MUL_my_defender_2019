/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** player
*/

#include <SFML/Graphics.h>

#ifndef PLAYER_H_
#define PLAYER_H_

typedef enum {
    RUNNING,
    JUMPING,
    FALLING,
    DASHING,
    ATTACKING_RIGHT,
    DOUBLE_JUMPING,
    ATTACKING_TOP,
    ATTACKING_DOWN,
    DEAD
} player_state;

typedef struct game_object game_object_t;
typedef struct scene scene_t;
struct game;
struct anim;

struct game_object *init_player(struct game_object *);
void compute_jump(struct game_object *);
bool player_update(struct game_object *, struct scene *);
void player_input_keyboard(struct game *, sfKeyCode);
void player_input_joystick(struct game *, int, sfEvent);
void player_dash_update(struct game_object *);
void player_attacking_update(struct game_object *, int, struct scene *);
void player_double_jump_update(struct game_object *);
void init_player_anim(struct anim *);
void init_player_anim_sound_effect(struct anim *);
void init_player_attack_sound_effect(struct anim *);
void check_player_env(game_object_t *, scene_t *);
game_object_t *find_player(scene_t *);

game_object_t *create_effect(game_object_t *, char *, sfVector2f, sfIntRect **);
bool update_effect(game_object_t *, scene_t *);
#endif /* !PLAYER_H_ */
