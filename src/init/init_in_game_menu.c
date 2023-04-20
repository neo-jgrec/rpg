/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_in_game_menu
*/

#include "rpg.h"


static const char *button_name_main[] = {
    "MENU",
    "SETTINGS",
    "INVENTORY",
    "SKILLS",
    "SAVE"
};

void replace_elements_in_game_menus(rpg_t *rpg)
{
    size_t i = 0;
    size_t padding = 100;
    const sfView *view = sfRenderWindow_getView(rpg->win->win);
    sfVector2f view_pos = sfView_getCenter(view);
    sfVector2f view_size = sfView_getSize(view);
    button_t *button = NULL;

    TAILQ_FOREACH(button, &rpg->menu->in_game_menu->nav_buttons, next) {
        struct button_s *prev = TAILQ_PREV(button, nav_buttons, next);
        if (i == 0) {
            button->pos.x = view_pos.x - view_size.x / 2 + 10;
            button->pos.y = view_pos.y - view_size.y / 2;
            i++;
            continue;
        } else if (i == 1) {
            button->pos.x = view_pos.x - view_size.x / 2 / 1.5;
        } else
            button->pos.x = prev->pos.x + prev->size.x + padding;
        button->pos.y = view_pos.y - view_size.y / 2 / 1.5;
        i++;
    }
    sfRectangleShape_setPosition(rpg->menu->in_game_menu->bg, (sfVector2f)
    {view_pos.x - view_size.x / 2 / 1.5, view_pos.y - view_size.y / 2 / 1.5});
    sfRectangleShape_setSize(rpg->menu->in_game_menu->bg,
        (sfVector2f){view_size.x / 1.5, view_size.y / 1.5});
}

static void init_buttons(rpg_t *rpg)
{
    TAILQ_INIT(&rpg->menu->in_game_menu->nav_buttons);
    button_t *button = malloc(sizeof(button_t));
    sfVector2f size_array[] = {{TEXT_SIZE_LEN(button_name_main[0], 30), 30},
        {TEXT_SIZE_LEN(button_name_main[1], 30), 30},
        {TEXT_SIZE_LEN(button_name_main[2], 30), 30},
        {TEXT_SIZE_LEN(button_name_main[3], 30), 30},
        {TEXT_SIZE_LEN(button_name_main[4], 30), 30}};

    for (int i = 0; i < 5; i++) {
        button = malloc(sizeof(button_t));
        button->name = (char *)button_name_main[i];
        button->size = size_array[i];
        button->shape = sfRectangleShape_create();
        button->action = NULL;
        TAILQ_INSERT_TAIL(&rpg->menu->in_game_menu->nav_buttons, button, next);
    }
}

void init_in_game_menu(rpg_t *rpg)
{
    rpg->menu->in_game_menu = malloc(sizeof(in_game_menu_t));
    rpg->menu->in_game_menu->bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rpg->menu->in_game_menu->bg, (sfColor){0, 0,
        0, 200});
    rpg->menu->in_game_menu->panel_type = NONE_PANEL;
    rpg->menu->in_game_menu->text = sfText_create();
    init_buttons(rpg);
}
