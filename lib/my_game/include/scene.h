/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;

////////////////////////////////////////////////////////////
/// \brief Struct scene used for to handle each scene
////////////////////////////////////////////////////////////
typedef struct scene {
    void (*handle_event)(struct scene *, struct game *, sfRenderWindow *);      /**< Function that handle window event for this scene*/
    game_object_t *objects_list;                                                /**< List of object of this scene*/
    sfColor background_color;                                                   /**< Color of the background of this scene*/
    int z_index_deepth;                                                         /**< Max deepth of z_index for objects display*/
    int display;                                                                /**< The displayed scene used for switch between scene*/
    int joystick_coord_id;                                                      /**< The coord to simulate the mouse for joystick*/
    sfRenderWindow *window;                                                     /**< sfRenderWindow used for display*/
} scene_t;

////////////////////////////////////////////////////////////
/// \brief Display a scene
///
/// Clear the window with the background color and then draw each object of the scene
///
/// \param struct scene scene to be displayed
/// \param sfRenderWindow window to display the scene
////////////////////////////////////////////////////////////
void display_scene(scene_t *, sfRenderWindow *);

////////////////////////////////////////////////////////////
/// \brief Destroy a scene
///
/// Destroy the objects of the scene and free the struct
///
/// \param struct scene scene to be destroyed
////////////////////////////////////////////////////////////
void destroy_scene(scene_t *);

#endif /* !SCENE_H_ */
