##
## EPITECH PROJECT, 2020
## minishell1
## File description:
## deploy
##

ssh-keyscan -H git.epitech.eu >> ~/.ssh/known_hosts
git remote add deploy git@git.epitech.eu:/thomas.marches@epitech.eu/MUL_my_defender_2019
git push deploy master