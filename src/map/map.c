/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** map
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

char *read_map(char *path)
{
    int fs = -1;
    char *map = NULL;
    struct stat size;

    if (path != NULL) {
        fs = open(path, O_RDONLY);
        stat(path, &size);
    }
    if (fs == -1)
        return (NULL);
    map = malloc(sizeof(char) * (size.st_size + 1));
    map[size.st_size] = '\0';
    if (map == NULL)
        return (NULL);
    read(fs, map, size.st_size);
    close(fs);
    return (map);
}