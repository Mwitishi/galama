#include "galama.h"

//Constants (not all of them)
const int inilives = 3;

const SDL_Color color_menutext = {0, 0, 0};

//State machine
uint8_t state, level;
int score, lives;

SDL_Surface *screen = NULL;
SDL_Surface *img_player = NULL;
SDL_Surface *img_enemy[GAL_ENEMY_TYP];

TTF_Font *font = NULL;

//Load images, text fonts etc
int gal_load_res() {
    font = TTF_OpenFont(GAL_FONT_FILE, 30);
    if(font == NULL) return 1;

    return 0;
}

int gal_init() {
    //Start up SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return 1;

    SDL_WM_SetCaption(GAL_WIN_NAME, NULL);

    screen = SDL_SetVideoMode(GAL_WIN_W, GAL_WIN_H, 32, SDL_SWSURFACE);
    if(screen == NULL) return 1;

    //Start up SDL_ttf (text rendering)
    if(TTF_Init() == -1) return 1;

    //Start the state machine
    score = 0;
    lives = inilives;
    state = 0;

    srand(time(NULL));

    if(gal_load_res() != 0) return 1;

    return 0;
}

//Process keyboard, mouse & other events
int gal_event() {
    SDL_Event e1;

    while(SDL_PollEvent(&e1) != 0) {
        if(e1.type == SDL_QUIT) return 1;
    }

    return 0;
}

//Update state, positions etc
int gal_update() {
    return 0;
}

//Render everything to screen
int gal_draw() {
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
    int out = 0;

    if(gal_init() != 0) out = 1;

    //Main loop
    while(!out) {
        if(gal_event() != 0) out = 1;

        if(gal_update() != 0) out = 1;

        if(gal_draw() != 0) out = 1;
    }

    gal_quit();

    return 0;
}
