#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include "defs.h"

using namespace std;

struct Menu{
    void renderMenu(Graphics& graphics, SDL_Texture* texture){
        SDL_Rect rectMenu = {0, 0, 800, 600};
        SDL_RenderCopy(graphics.renderer, texture, NULL, &rectMenu);


    }
    void waitUntilKeyPressed(){
        SDL_Event e;
        while (true) {
            if ( SDL_PollEvent(&e) != 0 &&
                 (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
                return;
            SDL_Delay(100);
        }
    }

};

#endif // _MENU__H
