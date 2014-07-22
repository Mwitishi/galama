#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define GAL_WIN_NAME "Galama by Mwitishi"
#define GAL_WIN_W 640
#define GAL_WIN_H 640
#define GAL_HISCORE_FILE "res/hiscores.dat"
#define GAL_FONT_FILE "res/font.ttf"
#define GAL_ENEMY_TYP 1

#define GAL_BUTTON_MARG 4
#define GAL_BUTTON_MAXLEN 30

typedef struct st_point{
    int x;
    int y;
} point;

//A button of a menu
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

extern const int inilives;
extern const SDL_Color color_menutext;

extern uint8_t state, level;
extern int score, lives;
extern SDL_Surface *screen;
extern SDL_Surface *img_player;
extern SDL_Surface *img_enemy[];
extern TTF_Font *font;
