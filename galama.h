#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define GAL_HISCORE_FILE "res/hiscores.dat"

extern uint8_t state, level;
extern int score, lives;
extern SDL_Surface *screen;
