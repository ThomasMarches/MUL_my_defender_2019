/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** get_infos
*/

#include <stdlib.h>
#include "my_defender.h"
#include "my.h"

char *get_string_from_param(char *str, int column)
{
    int counter = 0;
    char *str_to_return = malloc(sizeof(char));
    char *temp = malloc(sizeof(char) * 2);
    char *tmp = NULL;

    str_to_return[0] = '\0';
    if (temp == NULL)
        return (NULL);
    temp[1] = '\0';
    for (int found = 0; found + 1 != column; counter++)
        if (str[counter] == '\n')
            found++;
    for (; str[counter] != '\0' && str[counter] != '\n'; counter++) {
        temp[0] = str[counter];
        tmp = my_strcat(str_to_return, temp);
        free(str_to_return);
        str_to_return = tmp;
    }
    free(temp);
    return (str_to_return);
}

int get_int_from_param(char *str, int column, int level)
{
    int counter = 0;
    char *int_to_return = malloc(sizeof(char));
    char *temp = malloc(sizeof(char) * 2);
    char *tmp = NULL;

    int_to_return[0] = '\0';
    if (temp == NULL)
        return (84);
    temp[1] = '\0';
    for (int found = 0; found + 1 != column; counter++)
        if (str[counter] == '\n')
            found++;
    for (int found = 0; found + 1 != level && str[counter] != '\0'; counter++)
        if (str[counter] == ':')
            found++;
    for (; str[counter] != '\0' && str[counter] != ':' && str[counter]
    != '\n'; counter++) {
        temp[0] = str[counter];
        tmp = my_strcat(int_to_return, temp);
        free(int_to_return);
        int_to_return = tmp;
    }
    free(temp);
    return (my_getnbr(int_to_return));
}