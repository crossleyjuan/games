#include "surface.h"

Surface::Surface()
{
}

SDL_Surface* Surface::loadImage(char* file) {
    SDL_Surface* temp = NULL;
    SDL_Surface* result = NULL;

    if ((temp = IMG_Load(file)) == NULL) {
        return NULL;
    }

    result = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);

    return result;
}

bool Surface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

    return true;
}

bool Surface::OnDraw(SDL_Surface* dest, SDL_Surface* source, int X, int Y, int X2, int Y2, int W, int H) {
    if ((source == NULL) || (dest == NULL)) {
        return false;
    }

    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;

    SDL_Rect sourceRect;
    sourceRect.x = X2;
    sourceRect.y = Y2;
    sourceRect.w = W;
    sourceRect.h = H;

    SDL_BlitSurface(source, &sourceRect, dest, &rect);

    return true;
}

bool Surface::OnDraw(SDL_Surface* dest, SDL_Surface* source, int x, int y) {
    if ((source == NULL) || (dest == NULL)) {
        return false;
    }

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    SDL_BlitSurface(source, NULL, dest, &rect);

    return true;
}

