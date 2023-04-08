/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** move_player
*/

#include "rpg.h"

void move_player(player_t *player, sfVector2f dir)
{
    player->pos.y += dir.y;
    player->pos.x += dir.x;
    player->rect = (sfFloatRect){player->pos.x - 32,
        player->pos.y - 32, 64, 64};
}