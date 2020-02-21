/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_graph
*/

#include <SFML/Graphics.h>

#ifndef MY_GRAPH_H_
#define MY_GRAPH_H_

typedef struct window_s {
    int width;
    int height;
    int bits;
    int framerate;
    char *name;
    sfRenderWindow *window;
} window_t;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfBool displayed;
    int width;
    int height;
} cursor_t;

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    int x;
    int y;
    sfUint8 *pixels;
} framebuffer_t;

sfRenderWindow *make_window(window_t *, sfUint32);
window_t *init_window(void);
framebuffer_t *framebuffer_create(unsigned int, unsigned int, int, int);
void framebuffer_destroy(framebuffer_t *);
void my_put_pixels(framebuffer_t *, unsigned int, unsigned int, sfColor);
framebuffer_t **make_frames(unsigned int width, unsigned int height, int x, \
int y);
void display_frames(framebuffer_t **, sfRenderWindow *);
void destroy_frames(framebuffer_t **);
sfVector2f move_vector(int, int, int, int);
cursor_t init_cursor(char *);
void draw_cursor(cursor_t, sfRenderWindow *);
sfIntRect update_rect(int, int, int, int);
sfText *init_text(char *, int, int, char *);
void update_text(sfText *, sfColor, sfVector2f, int);
void center_text(sfText *, int);
void set_window_icon(sfRenderWindow *, char *);
#endif /* !MY_GRAPH_H_ */
