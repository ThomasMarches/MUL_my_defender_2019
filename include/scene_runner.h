/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scene
*/

#ifndef SCENE_RUNNER_H_
#define SCENE_RUNNER_H_

#include <SFML/Graphics.h>

typedef struct game game_t;
typedef struct game_object game_object_t;
typedef struct scene scene_t;

typedef enum {
    GAME_SCENE,
    MAIN_MENU_SCENE,
    OPTION_SCENE,
    INFOS_SCENE,
    END_SCENE,
    IN_GAME_MENU_SCENE,
    NULL_SCENE,
} scene_index;

void init_scenes(game_t *, char *);
scene_t *init_game_scene(game_t *, char *);
scene_t *create_main_menu(void);
scene_t *create_in_game_menu(void);
scene_t *create_end_menu(void);
scene_t *create_infos_menu(void);
void handle_framerate(sfClock *, scene_t *, game_t *);
scene_t *init_options_scene(game_t *);
void close_scene(scene_t *, sfRenderWindow *, sfClock *, game_t *);
bool disappear_scene_objects(scene_t *);

#endif /* !SCENE_H_ */
