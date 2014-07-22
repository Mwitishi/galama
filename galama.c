#include "galama.h"

//Constants (not all of them)
const int inilives = 3;

//State machine
uint8_t state, level;
int score, lives;

SDL_Surface *screen = NULL;
SDL_Surface *img_player = NULL;
SDL_Surface *img_enemy[GAL_ENEMY_TYP];

int gal_init() {
    if(SDL_Init(SDL_INIT_EVERYTHING)) return 1;

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    if(screen == NULL) return 1;

    score = 0;
    lives = inilives;
    state = 0;

    return 0;
}

int gal_quit() {
    SDL_Quit();

    return 0;
}

int main(int argc, char **argv) {
    

    gal_init();

    gal_quit();

    return 0;
}
