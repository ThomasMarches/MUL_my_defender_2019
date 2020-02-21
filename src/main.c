/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** main
*/

#include "define.h"
#include "my_graph.h"
#include "my_runner.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    if (window == NULL)
        return (NULL);
    window->width = WINDOW_WIDTH;
    window->height = WINDOW_HEIGHT;
    window->bits = WINDOW_BITS_PER_PIXEL;
    window->framerate = WINDOW_FRAMERATE;
    window->name = (char *)WINDOW_NAME;
    window->window = make_window(window, sfClose);
    set_window_icon(window->window, (char *) ICON_PATH);
    return (window);
}

int my_runner(int argc, char **argv)
{
    char *map = read_map(argv[1]);
    game_t *game = init_game(map);
    sfRenderWindow *window = NULL;
    sfMusic *music = sfMusic_createFromFile(MENU_MUSIC_PATH);
    int display = MAIN_MENU_SCENE;

    if (music == NULL || game == NULL)
        return (84);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    window  = game->window->window;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window) && display >= 0) {
        display = game->scene_loop[display](game, window);
    }
    destroy_game(game);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    return (0);
}

int check_params(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    else if (!my_strcmp(argv[1], (char *)USAGE_FLAG))
        return (1);
    else
        return (0);
}

int main(int argc, char **argv, char **env)
{
    bool has_display = false;
    int param = 0;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp(env[i], (char *)ENV_DISPLAY))
            has_display = true;
    if (has_display == false)
        return (84);
    param = check_params(argc, argv);
    if (param == 1) {
        write(1, USAGE, my_strlen(USAGE));
        return (0);
    }
    return (my_runner(argc, argv));
}