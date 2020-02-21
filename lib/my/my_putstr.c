/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_putstr.c
*/

void my_putstr(char *string)
{
    for (int counter = 0; string[counter != '\0']; counter++)
        write(1, &string[counter], 1);
}