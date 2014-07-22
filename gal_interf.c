#include "galama.h"

int but_getsize(button but1, point *res) {
    int w, h;

    if(font == NULL || but1.text == NULL || strlen(but1.text) <= 0 || res == NULL) return 1;

    if(TTF_SizeText(font, but1.text, &w, &h)) return 1;

    res->x = w + 2*GAL_BUTTON_MARG;
    res->y = h + 2*GAL_BUTTON_MARG;

    return 0;
}
