/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main_loop
*/

#include "rpg.h"

static void analyse_events(win_t *win, rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        check_input(win, rpg->input);
    }
}

int main_loop(win_t *win, rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(win->win)) {
        win->deltaT = DELTAT(win->time);
        sfClock_restart(win->time);
        manage_player(win, rpg->player, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        analyse_events(win, rpg);
        sfRenderWindow_drawSprite(win->win, rpg->asset->player.sp, NULL);
        sfRenderWindow_display(win->win);
    }
    return 0;
}
