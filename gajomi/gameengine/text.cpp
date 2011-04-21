#include "text.h"
#include <iostream>

using namespace std;

Text::Text(char* text, int x, int y)
{
    TTF_Font *font;
    font = TTF_OpenFont("FreeSerif.ttf", 24);
    if (font == NULL) {
        cout << "Error: " << TTF_GetError() << endl;
    }
    SDL_Color text_color = {0, 0, 0};
    Surf_Entity = TTF_RenderText_Solid(font,text, text_color);

    X = x;
    Y = y;
    Flags = ENTITY_FLAG_MAPONLY | ENTITY_FLAG_GHOST;
    this->AccelX = 0;
    this->AccelY = 0;
    this->Width = strlen(text)*24;
    this->Height = 80;
}

void Text::OnLoop() {
    Entity::OnLoop();
}
