#include "galama.h"

//Constants (not all of them)
const int inilives = 3;

//State machine
uint8_t state, level;
int score, lives;

SDL_Surface *screen = NULL;
SDL_Surface *img_player = NULL;
SDL_Surface *img_enemy[GAL_ENEMY_TYP];

TTF_Font *font = NULL;

int gal_load_res() {
    font = TTF_OpenFont(GAL_FONT_FILE, 30);
    if(font == NULL) return 1;

    return 0;
}

int gal_init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return 1;

    SDL_WM_SetCaption(GAL_WIN_NAME, NULL);

    screen = SDL_SetVideoMode(GAL_WIN_W, GAL_WIN_H, 32, SDL_SWSURFACE);
    if(screen == NULL) return 1;

    if(TTF_Init() == -1) return 1;

    score = 0;
    lives = inilives;
    state = 0;

    srand(time(NULL));

    if(gal_load_res() != 0) return 1;

    return 0;
}

int gal_quit() {
    if(font != NULL) {
        TTF_CloseFont(font);
        font = NULL;
    }

    SDL_Quit();
    TTF_Quit();

    return 0;
}

int main(int argc, char **argv) {
    

    gal_init();

    gal_quit();

    return 0;
}
