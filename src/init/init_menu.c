/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_menu
*/

#include "rpg.h"

void settings_button(rpg_t *rpg);
void quit_button(rpg_t *rpg);
void play_button(rpg_t *rpg);

void back_button(rpg_t *rpg);
void res_button(rpg_t *rpg);

static void init_buttons(menu_t *menu)
{
    TAILQ_INIT(&menu->buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"PLAY", "SETTINGS", "QUIT"};
    void *buttons_functions[] = {play_button, settings_button, quit_button};
    sfVector2f buttons_pos[] = {{100, 300}, {100, 400}, {100, 500}};
    sfVector2f buttons_size[] = {{200, 50}, {200, 50}, {200, 50}};
    size_t nb_buttons = sizeof(buttons_names) / sizeof(char *);

    for (size_t i = 0; i < nb_buttons; i++) {
        button = malloc(sizeof(button_t));
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->buttons, button, next);
    }
}

static void init_button_res_settings(menu_t *menu)
{
    TAILQ_INIT(&menu->res_buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"1600x900", "1920x1080", "800x600"};
    void *buttons_functions[] = {NULL, NULL, NULL};
    sfVector2f buttons_pos[] = {{1900 / 2 - 100, 10}, {1900 / 2 - 100, 70}, {1900 / 2 - 100, 130}};
    sfVector2f buttons_size[] = {{200, 50}, {200, 50}, {200, 50}};
    size_t nb_buttons = sizeof(buttons_names) / sizeof(char *);

    for (size_t i = 0; i < nb_buttons; i++) {
        button = malloc(sizeof(button_t));
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->res_buttons, button, next);
    }
}

static void init_button_settings(menu_t *menu)
{
    TAILQ_INIT(&menu->settings_buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"<- BACK", "SOUND", "MUSIC", "FULLSCREEN"};
    void *buttons_functions[] = {back_button, NULL, NULL, res_button};
    sfVector2f buttons_pos[] = {{10, 10}, {100, 300}, {100, 400}, {100, 500}};
    sfVector2f buttons_size[] = {{200, 50}, {200, 50}, {200, 50}, {200, 50}};
    size_t nb_buttons = sizeof(buttons_names) / sizeof(char *);

    for (size_t i = 0; i < nb_buttons; i++) {
        button = malloc(sizeof(button_t));
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->settings_buttons, button, next);
    }
    init_button_res_settings(menu);
}

void init_menu(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->text = sfText_create();
    menu->font = sfFont_createFromFile("assets/Inter-Medium.ttf");
    menu->bg = sfRectangleShape_create();

    sfText_setString(menu->text, "THE RPG");
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, 100);
    sfText_setPosition(menu->text, (sfVector2f){500, 100});
    sfRectangleShape_setPosition(menu->bg, (sfVector2f){0, 0});
    sfRectangleShape_setSize(menu->bg, (sfVector2f){
        sfRenderWindow_getSize(rpg->win->win).x,
        sfRenderWindow_getSize(rpg->win->win).y});
    sfRectangleShape_setTexture(menu->bg,
    sfTexture_createFromFile("assets/menu/bg.png",
    NULL), sfTrue);
    init_buttons(menu);
    init_button_settings(menu);
    menu->scene = MAIN_MENU;
    rpg->menu = menu;
}
