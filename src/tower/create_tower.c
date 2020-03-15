/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_tower
*/

#include "my_defender.h"
#include "tower.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

bool update_tower(game_object_t *object, scene_t *scene)
{
    tower_t *tower = (tower_t *) object->extend;

    tower->delay++;
    if (tower->attack_speed != 0 && tower->delay == WINDOW_FRAMERATE / \
    tower->attack_speed) {
        tower->delay = 0;
        get_ennemy_to_shoot(object, scene);
    }
    return (true);
}

char *init_tower_from_file(char *filepath)
{
    int fd = -1;
    struct stat size;
    char *tower_param = NULL;

    if (filepath != NULL) {
        fd = open(filepath, O_RDONLY);
        stat(filepath, &size);
    }
    if (fd == -1)
        return (NULL);
    tower_param = malloc(sizeof(char) * (size.st_size + 1));
    if (tower_param == NULL)
        return (NULL);
    if (read(fd, tower_param, size.st_size) == -1)
        return (NULL);
    tower_param[size.st_size] = '\0';
    close(fd);
    return (tower_param);
}

void draw_tower(sfRenderWindow *window, game_object_t *object)
{
    tower_t *tower = (tower_t *) object->extend;
    game_object_t *button = tower->button;

    if (tower->draw_range == 1)
        sfRenderWindow_drawCircleShape(window, tower->circle, NULL);
    if (button != NULL && button->state == 1 && tower->level != 3) {
        sfRenderWindow_drawText(window, tower->upgrade_txt, NULL);
    }
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void init_tower(game_object_t *object, tower_t *tower, sfVector2f pos)
{
    object->update = &update_tower;
    object->draw = &draw_tower;
    object->z_index = 2;
    object->extend = (void *) tower;
    object->box = (sfIntRect) {pos.x, pos.y, TILE_WIDTH, TILE_HEIGHT};
    create_range_circle(object);
    create_upgrading_content(tower, pos, object);
}

game_object_t *create_tower(game_object_t *last, sfVector2f pos, \
tower_type_t type)
{
    tower_t *tower = create_tower_extend(type, pos);
    game_object_t *object = NULL;
    char *path = get_string_from_param(tower->tower_param, 5);

    if (tower == NULL)
        return (NULL);
    if (update_money(last, tower->cost) == false) {
        free(tower);
        return (NULL);
    }
    object = create_game_object(last, path, pos, TOWER);
    free(path);
    if (object == NULL)
        return (NULL);
    init_tower(object, tower, pos);
    return ((tower->button) ? tower->button : object);
}