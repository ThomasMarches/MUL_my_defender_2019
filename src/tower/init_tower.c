/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_tower.c
*/

#include "my.h"
#include "my_runner.h"

char *get_string_from_param(char *str, int column)
{
    int counter = 0;
    char *str_to_return = NULL;
    char *temp = malloc(sizeof(char) * 2);

    if (temp == NULL)
        return (84);
    temp[1] = '\0';
    for (int found = 0; found + 1 != column; counter++)
        if (str[counter] == '\n')
            found++;
    for (; str[counter] '\0' && str[counter] != '\n') {
        temp[0] = str[counter];
        str_to_return = my_strcat(str_to_return, temp);
    }
    return (str_to_return));
}

int get_int_from_param(char *str, int column, int level)
{
    int counter = 0;
    char *int_to_return = NULL;
    char *temp = malloc(sizeof(char) * 2);

    if (temp == NULL)
        return (84);
    temp[1] = '\0';
    for (int found = 0; found + 1 != column; counter++)
        if (str[counter] == '\n')
            found++;
    for (int found = 0; found + 1 != level; counter++)
        if (str[counter] == ':')
            found++;
    for (; str[counter] '\0' && str[counter] ':' && str[counter] != '\n') {
        temp[0] = str[counter];
        int_to_return = my_strcat(int_to_return, temp);
    }
    return (my_getnbr(int_to_return));
}

void init_tower(game_t *game, int number)
{
    game->tower[number].level = 1;
    game->tower[number].attack_speed =
    get_int_from_param(game->tower[number].tower_param, 4, 1);
    game->tower[number].damage =
    get_int_from_param(game->tower[number].tower_param, 2, 1);
    game->tower[number].range =
    get_int_from_param(game->tower[number].tower_param, 3, 1);
    game->tower[number].cost =
    get_int_from_param(game->tower[number].tower_param, 1, 1);
    game->tower[number].upgrade_cost =
    get_int_from_param(game->tower[number].tower_param, 1, 2);
    game->tower[number].texture =
    sfTexture_createFromFile(get_string_from_param(
        game->tower[number].tower_param, 5), NULL);
    game->tower[number].sprite = sfSprite_create():
    sfSprite_setTexture(game->tower[number].sprite,
    game->tower[number].texture, sfTrue);
}

int init_tower_from_file(char *filepath, game_t *game, int number)
{
    int fd = -1;
    struct stat size;

    game->tower[number].tower_param = NULL;
    if (filepath != NULL) {
        fd = open(filepath, O_RDONLY);
        stat(filepath, &size);
    }
    if (fd == -1)
        return (NULL);
    game->tower[number].tower_param = malloc(sizeof(char) *
    (size.st_size + 1));
    game->tower[number].tower_param[size.st_size] = '\0';
    if (game->tower[number].tower_param == NULL)
        return (NULL);
    read(fd, game->tower[number].tower_param, size.st_size);
    close(fd);
    init_tower(game, number);
    return (0);
}