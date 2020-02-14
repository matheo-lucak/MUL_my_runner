/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int error(char **env)
{
    char *display = "DISPLAY";
    int i = -1;

    if (env == NULL || env[0] == NULL)
        return (84);
    while (env[++i] != NULL)
        if (my_strcmp(env[i], display) == 0)
            return (0);
    return (84);
}

void print_rules(void)
{
    my_putstr("\nUSAGE:\n\t ./my_runner [-FLAG] [MAP ...]\n\n");
    my_putstr("OPTIONS:\n");
    my_putstr("\t-m\t\tLaunch game menu\n");
    my_putstr("\t-i\t\tLaunch game in infinity mode\n");
    my_putstr("\t-e\t\tLaunch game in edit mode\n");
    my_putstr("\t-m\t\tLaunch menu\n");
    my_putstr("\t-h\t\tPrint the usage and quit\n");
    my_putstr("\t Put [MAP ...] as param with [-i] and [-m]");
    my_putstr("\nWelcome to MACRON_RUN\n\n");
    my_putstr("/!\\ RULES /!\\:\n");
    my_putstr("\t-RUN\n");
    my_putstr("\t-Don't get caught by gilet jaune\n\n");
    my_putstr("\tCOMMANDS:\n");
    my_putstr("\t\tSprint -> Right\n");
    my_putstr("\t\tJump   -> Up\n");
}

int main(int ac, char **av, char **env)
{
    if (error(env) == 84 || ac == 1)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        print_rules();
    if (av[1][0] != '-')
        launch_game(PLAY, av + 1);
    if (ac > 2 && my_strcmp(av[1], "-i") == 0)
        launch_game(PLAY_INF, av + 2);
    if (ac == 2 && my_strcmp(av[1], "-e") == 0)
        launch_game(EDIT, NULL);
    if (ac > 2 && my_strcmp(av[1], "-m") == 0)
        launch_game(MENU, av + 2);
    return (0);
}