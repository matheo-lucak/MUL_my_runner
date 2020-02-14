/*
** EPITECH PROJECT, 2019
** duck_hunth
** File description:
** header for duck hunt
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef RUNNER_H
#define RUNNER_H

#define SCALE (10)

typedef enum game_mode
{
    PLAY,
    PLAY_INF,
    EDIT,
    MENU,
    PAUSE,
    LOSE,
    WIN
} game_mode_t;

typedef struct map
{
    char **map;
    char *path;
    struct map *next;
} map_t;

typedef struct win
{
    sfRenderWindow *window;
    map_t *map_data;
    sfClock *game_time;
    sfMusic *music;
    sfVideoMode video_mode;
    sfEvent event;
    game_mode_t gm;
    float game_speed;
    int score;
} win_t;

typedef enum elem
{
    PLAYER,
    PLAYER2,
    BACKGROUND,
    MIDDLEGROUND,
    GROUND,
    HOUSE,
    BARREL,
    HEALTH_BAR,
    STAMINA_BAR,
    CRATE,
    HAY_WAGON,
    WELL,
    CURSOR,
    MAP_NAME_FIELD,
    WOOD_T,
    WOOD_B,
    WOOD_L,
    WOOD_R,
    SPIKE,
    ITEM_BAR,
    B_PLAY,
    B_INF_PLAY,
    B_EDIT,
    SCORE_BAR,
    HSCORE_BAR,
    NONE
} elem_t;

typedef enum prop
{
    LIFE,
    STAMINA,
    SPEED,
    GRAVITY,
    FALL_SPEED,
    JUMP_SPEED,
    CLOCK,
    JUMP_CLOCK,
    IMAGE,
    DEFAULT_IMAGE,
    FALLING,
    JUMPING,
    RUNNING,
    BLOCKED,
    NORMAL_HITBOX,
    JUMP_HITBOX,
    BAR_FIELD,
    ORIGIN,
    TEXT,
    JUMP_SOUND,
    HIT_SOUND,
    HIT_SOUND2,
    SAVED_X
} prop_t;

typedef struct component
{
    sfClock *clock;
    void *data;
    sfImage *image;
    sfText *text;
    sfSound *sound;
    prop_t type;
    sfVector2i v2i;
    sfVector2f v2f;
    sfIntRect irect;
    int i;
    float f;
} component_t;

typedef struct game_obj
{
    component_t **comp;
    sfTexture *texture;
    sfSprite *sprite;
    struct game_obj *next;
    sfVector2f pos;
    sfIntRect l_rect;
    sfFloatRect g_rect;
    int comp_nb;
    elem_t type;
} game_obj_t;

typedef struct obj
{
    game_obj_t *player;
    game_obj_t *player2;
    game_obj_t *background;
    game_obj_t *middleground;
    game_obj_t *ground;
    game_obj_t *house;
    game_obj_t *prop;
    game_obj_t *health_bar;
    game_obj_t *stamina_bar;
    game_obj_t *item_bar;
    game_obj_t *cursor;
    game_obj_t *ghost;
    game_obj_t *b_play;
    game_obj_t *b_inf_play;
    game_obj_t *b_edit;
    game_obj_t *score_bar;
} obj_t;


int init_window(win_t *win , int width, int height, game_mode_t gm);

game_obj_t *create_game_obj(elem_t type);
void free_obj(game_obj_t *obj);
void set_l_rect(game_obj_t *obj, int width, int height);
void set_pos(game_obj_t *obj, float x, float y);
void set_g_rect(game_obj_t *obj);
int set_sprite(game_obj_t *obj, char const *path);

int set_comp_int(game_obj_t *obj, prop_t type, int nb);
int set_comp_float(game_obj_t *obj, prop_t type, float nb);
int set_comp_v2i(game_obj_t *obj, prop_t type, int x, int y);
int set_comp_v2f(game_obj_t *obj, prop_t type, float x, float y);
int set_comp_clock(game_obj_t *obj, prop_t type);
int reset_comp_clock(game_obj_t *obj, prop_t type);
int set_comp_image(game_obj_t *obj, prop_t type, char *path);
int set_comp_text(game_obj_t *obj, prop_t type, char *path, int size);
int set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume);

component_t *add_comp(game_obj_t *obj, prop_t type);
int find_comp(game_obj_t *obj, prop_t type);
void free_all_comp(game_obj_t *obj);

int create_player(game_obj_t *obj);
int create_player2(game_obj_t *obj);
int create_background(game_obj_t *obj);
int create_middleground(game_obj_t *obj);
int create_ground(game_obj_t *obj);
int create_house(game_obj_t *obj);
int create_barrel(game_obj_t *obj);
int create_health_bar(game_obj_t *obj);
int create_stamina_bar(game_obj_t *obj);
int create_crate(game_obj_t *obj);
int create_hay_wagon(game_obj_t *obj);
int create_well(game_obj_t *obj);
int create_cursor(game_obj_t *obj);
int create_map_name_field(game_obj_t *obj);
int create_wood_top(game_obj_t *obj);
int create_wood_bot(game_obj_t *obj);
int create_wood_left(game_obj_t *obj);
int create_wood_right(game_obj_t *obj);
int create_spike(game_obj_t *obj);
int create_item_bar(game_obj_t *obj);
int create_b_play(game_obj_t *obj);
int create_b_inf_play(game_obj_t *obj);
int create_b_edit(game_obj_t *obj);
int create_score_bar(game_obj_t *obj);
int create_hscore_bar(game_obj_t *obj);

void move_obj(win_t *win, game_obj_t *obj, float way);
void move_entity(game_obj_t *obj);
void move_env(win_t *win, obj_t *obj, int mode);
int expand_obj(game_obj_t *obj, elem_t type, int shift_min, int shift_max);
void clean_obj(game_obj_t **obj);
void disp_obj(win_t *win, game_obj_t *obj);
void anime_obj(game_obj_t *obj, elem_t type);
void is_blocked(game_obj_t *player, game_obj_t *prop);
void player_block(win_t *win, game_obj_t *player, game_obj_t *prop);
void is_falling(game_obj_t *player, game_obj_t *obj);
void is_jumping(game_obj_t *player);
void player_fall(game_obj_t *player);
void manage_player_pos(game_obj_t *player);
void fill_bar(game_obj_t *player, game_obj_t *bar);
void is_running(game_obj_t *player);
void move_cursor(win_t *win, obj_t *obj);
void reset_ghost(obj_t *obj);
void select_ghost_obj(obj_t *obj);
int create_prop(obj_t *obj, elem_t type, sfVector2f coord, float x_shift);
int create_prop_from_ghost(obj_t *obj, elem_t type, sfVector2f coord);
int expand_map(win_t *win, obj_t *obj, game_obj_t *prop);
float get_tail_x_pos(game_obj_t *prop);
int get_map_nb(map_t *map_data);
int generate_inf_map(win_t *win, obj_t *obj);
void entity_event(win_t *win, obj_t *obj);
void is_picked(game_obj_t *player, game_obj_t *obj);
void is_giletjauned(game_obj_t *player, game_obj_t *player2);
void is_pause(win_t *win);
void move_env(win_t *win, obj_t *obj, int mode);
void disp_env(win_t *win, obj_t *obj);
int is_end(win_t *win, obj_t *obj);
void set_score(win_t *win, game_obj_t *score_bar);
void disp_hscore(win_t *win, game_obj_t *score_bar);
void free_win(win_t *win);

void save_score(win_t *win);
int read_score(void);

void set_game_speed(win_t *win);
void set_game_score(win_t *win);
void set_game_var(win_t *win);

int create_map(char **map, obj_t *obj, float x_shift);
char **create_new_map(game_obj_t *prop, sfVector2i size);
sfVector2i get_map_size(game_obj_t *prop);
int write_new_map(char **map, char *path);

int inf_game_event(win_t *win, obj_t *obj);
int edit_game_event(win_t *win, obj_t *obj);
int menu_game_event(win_t *win, obj_t *obj);

int start_game(win_t *win, obj_t *obj, int init);
int start_edit_game(win_t *win, obj_t *obj, int init);
int start_menu_game(win_t *win, obj_t *obj, int init);
void close_edit_mode(win_t *win, obj_t *obj);

int set_null_obj(obj_t *obj);
int init_obj_player(obj_t *obj);
int init_obj_env(obj_t *obj);
int init_obj_inf_hud(obj_t *obj);
int init_obj_edit(obj_t *obj);
int init_obj_menu(obj_t *obj);
int init_window(win_t *win , int width, int height, game_mode_t gm);

int launch_game(game_mode_t gm, char **path);

int get_randnb(int min, int max);
char **read_map(char *path);
int get_map_lenght(char **map);

#endif /* !RUNNER_H */