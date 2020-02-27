/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** get_map_info.c
*/

#include "my.h"
#include "my_defender.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int is_path_valid(char *map, char *map_name)
{
    int counter = 0;

    for (; map[counter] != '\0' && map[counter] != 'X'; counter++);
    if (map[counter] != 'X')
        return (84);
    if (map[counter] - 1 != '1' && map[counter] + 1 != '1' &&
    map[counter] - 22 != '1' && map[counter] + 22 != '1') {
        my_putstr(my_strcat(map_name, CASLTE_NOT_REACHABLE));
        return (84);
    }
    return (0);
}

int check_map_content(int number_of_grass, int number_of_castle,
int number_of_path, char *map_name)
{
    if (number_of_castle > 1) {
        my_putstr(my_strcat(map_name, TOO_MANY_CASTLE));
        return (84);
    } else if (number_of_grass == 0) {
        my_putstr(my_strcat(map_name, NOT_ENOUGH_GROUND));
        return (84);
    }
    if (number_of_path == 0) {
        my_putstr(my_strcat(map_name, NOT_ENOUGH_PATH));
        return (84);
    } else if (number_of_castle == 0) {
        my_putstr(my_strcat(map_name, NOT_ENOUGH_CASTLE));
        return (84);
    }
    return (0);
}

int is_map_valid(char *map, char *map_name)
{
    int number_of_path = 0;
    int number_of_grass = 0;
    int number_of_castle = 0;

    for (int counter = 0; map[counter] != '\0'; counter++) {
        if (map[counter] == 'X')
            number_of_castle++;
        if (map[counter] == '1')
            number_of_path++;
        if (map[counter] == '2')
            number_of_grass++;
    }
    if (check_map_content(number_of_grass, number_of_castle,
    number_of_path, map_name) == 84)
        return (84);
    return (is_map_valid(map, map_name));
}

char *get_map(char *filepath_to_map)
{
    int fd = -1;
    char *map = NULL;
    struct stat size;

    if (filepath_to_map != NULL) {
        fd = open(filepath_to_map, O_RDONLY);
        stat(filepath_to_map, &size);
    }
    if (fd == -1)
        return (NULL);
    map = malloc(sizeof(char) * (size.st_size + 1));
    map[size.st_size] = '\0';
    if (map == NULL)
        return (NULL);
    read(fd, map, size.st_size);
    close(fd);
    return (map);
}