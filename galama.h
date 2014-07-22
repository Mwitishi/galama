#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define GAL_HISCORE_FILE "res/hiscores.dat"
#define GAL_BUTTON_MAXLEN 30
#define GAL_ENEMY_TYP 1

typedef struct st_point{
    int x;
    int y;
} point;

typedef struct st_button{
    uint8_t state;
    char text[GAL_BUTTON_MAXLEN];
    point pos;
} button;

typedef struct st_enemy{
    uint8_t type;//Type of enemy
    uint8_t state;//State (attacking, passive etc)
    point pos;//Position
    int cooldown;//Shooting cooldown

    uint8_t frame;//Current animation frame
} enemy;

extern uint8_t state, level;
extern int score, lives;
extern SDL_Surface *screen;
extern SDL_Surface *img_player;
extern SDL_Surface *img_enemy[];
