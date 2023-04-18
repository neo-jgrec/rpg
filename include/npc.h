/*
** EPITECH PROJECT, 2023
** npc
** File description:
** npc
*/

#ifndef NPC_
    #define NPC_

    #define SP_MERCHANT merchant->sprite_info.sprite_npc

    #include "rpg.h"

    typedef struct anim_s {
        float clock_anim;
        int max_sec_anim;
        int max_anim;
    } anim_t;

    typedef struct sprite_npc_s {
        sfIntRect pos_anim;
        sprite_t sprite_npc;
        sfVector2f pos_npc;
    } snpc_t;

    typedef struct npc_struct {
        char *name;
        float clock_anim_selec;
        snpc_t sprite_info;
        anim_t anim;
        bool draw;
        struct npc_struct *next;
        struct npc_struct *prev;
    } npc_lt;

    typedef struct npc_list {
        size_t size;
        npc_lt *head;
        npc_lt *tail;
    } npc_l;

    typedef struct npc_s {
        npc_l *alchemist;
        npc_l *merchant;
        npc_l *chef;
        npc_l *priest;
    } npc_t;

    void init_merchant(npc_l *lst_merchant, char *name, sfVector2f pos);
    void init_npc_sprites(npc_t *npc);

    void init_npc(rpg_t *rpg);

#endif /* !NPC_ */