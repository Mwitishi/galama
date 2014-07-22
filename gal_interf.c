#include "galama.h"

int but_getsize(button but1, point *res) {
    int w, h;

    if(font == NULL || but1.text == NULL || strlen(but1.text) <= 0 || res == NULL) return 1;

    if(TTF_SizeText(font, but1.text, &w, &h)) return 1;

    //Add margins
    res->x = w + 2*GAL_BUTTON_MARG;
    res->y = h + 2*GAL_BUTTON_MARG;

    return 0;
}

int but_draw(button but1) {
    int res = 0;
    SDL_Rect r1;
    SDL_Surface *img = NULL;

    //Render the text
    img = TTF_RenderText_Solid(font, but1.text, color_menutext);
    if(img == NULL) res = 1;

    //Draw background (TO-DO)

    //Draw the text
    r1.x = but1.pos.x + GAL_BUTTON_MARG;
    r1.y = but1.pos.y + GAL_BUTTON_MARG;
    if(SDL_BlitSurface(img, NULL, screen, &r1) != 0) res = 1;

    //Free memory
    if(img != NULL) {
        SDL_FreeSurface(img);
        img = NULL;
    }

    return res;
}
