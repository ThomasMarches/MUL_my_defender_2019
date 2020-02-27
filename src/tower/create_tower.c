/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_tower
*/

#include "my_defender.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int get_int_from_param(char *, int, int);
char *get_string_from_param(char *, int);


bool update_tower(game_object_t *object, scene_t *scene)
{
    tower_t *tower = (tower_t *) object->extend;
    return (true);
}

char *init_tower_from_file(char *filepath, game_t *game, int number)
{
    int fd = -1;
    struct stat size;
    char *tower_param = NULL;

    tower_param = NULL;
    if (filepath != NULL) {
        fd = open(filepath, O_RDONLY);
        stat(filepath, &size);
    }
    if (fd == -1)
        return (NULL);
    tower_param = malloc(sizeof(char) * (size.st_size + 1));
    if (tower_param == NULL)
        return (NULL);
    tower_param[size.st_size] = '\0';
    if (read(fd, tower_param, size.st_size) == -1)
        return (NULL);
    close(fd);
    return (NULL);
}

tower_t *create_tower_extend(tower_type_t type)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL)
        return (NULL);
    tower->type = type;
    tower->level = 1;
    tower->attack_speed = get_int_from_param(tower->tower_param, 4, 1);
    tower->damage = get_int_from_param(tower->tower_param, 2, 1);
    tower->range = get_int_from_param(tower->tower_param, 3, 1);
    tower->cost = get_int_from_param(tower->tower_param, 1, 1);
    tower->upgrade_cost = get_int_from_param(tower->tower_param, 1, 2);
    return (tower);
}

game_object_t *create_tower(game_object_t *last, char *path, sfVector2f pos, tower_type_t type)
{
    tower_t *tower = create_tower_extend(type);
    game_object_t *object = NULL;

    if (tower == NULL)
        return (NULL);
    object = create_game_object(last, get_string_from_param(tower->tower_param, 5), pos, TOWER);
    if (object == NULL)
        return (NULL);
    object->extend = (void *) tower;
    return (object);
}