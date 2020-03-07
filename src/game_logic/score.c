/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** score
*/

#include "my_defender.h"
#include "my.h"
#include "my_graph.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void init_score(game_t *game)
{
    score_t *score = NULL;
    char *tmp = NULL;

    score = malloc(sizeof(score_t));
    game->score = score;
    if (score == NULL)
        return;
    score->score = 0;
    tmp = my_nbr_to_str(0);
    score->score_text = my_strcat((char *)BASE_SCORE, tmp);
    free(tmp);
    score->text = init_text(score->score_text, 0, 0, (char *) FONT_PATH);
}

void increase_score(game_t *game)
{
    char *tmp = NULL;

    game->score->score += 1;
    free (game->score->score_text);
    tmp = my_nbr_to_str(game->score->score);
    game->score->score_text = my_strcat((char *)BASE_SCORE, tmp);
    free(tmp);
    sfText_setString(game->score->text, game->score->score_text);
}