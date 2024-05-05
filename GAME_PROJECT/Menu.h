#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include "defs.h"

using namespace std;

struct Menu {
    void renderMenu(Graphics& graphics, SDL_Texture* texture) {
        SDL_Rect rectMenu = {0, 0, 800, 600};
        SDL_RenderCopy(graphics.renderer, texture, NULL, &rectMenu);
    }

    void waitUntilKeyPressed() {
        SDL_Event e;
        while (true) {
            if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
                return;
            SDL_Delay(100);
        }
    }

    int runMenu(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* backgroundMenu) {
        while (true) {
            renderMenu(graphics, backgroundMenu);
            graphics.Draw_Font("Fruits Basket", 200, 100, 80, {21, 52, 72}, "Font//iCiel Crocante.otf");
            int x, y, downx = 0, downy = 0;
            SDL_GetMouseState(&x, &y);
            if (x >= 260 && x <= 481 && y >= 250 && y <= 286) {
                graphics.Draw_Font("New Game", 260, 250, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 260, 410, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 260, 490, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 260 && x <= 535 && y >= 330 && y <= 365) {
                graphics.Draw_Font("INSTRUCTION", 260, 330, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 260, 410, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 260, 490, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 260 && x <= 504 && y >= 410 && y <= 447) {
                graphics.Draw_Font("High score", 260, 410, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 260, 490, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 260 && x <= 479 && y >= 490 && y <= 528) {
                graphics.Draw_Font("Quit game", 260, 490, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 260, 410, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else {
                playgPick = false;
                graphics.Draw_Font("New Game", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 260, 410, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 260, 490, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
            }
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 260 && downx <= 481 && downy >= 250 && downy <= 286) {
                            graphics.play(gClick);
                            return 1;
                        }else if (downx >= 260 && downx <= 479 && downy >= 490 && downy <= 528){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            return 4;
                        }else if (downx >= 260 && downx <= 535 && downy >= 330 && downy <= 365){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            return 2;
                        }
                }
            }
            graphics.presentScene();
        }
    }

    int rungameMode(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* backgroundMenu) {
        int x, y, downx, downy;
        while (true) {
            renderMenu(graphics, backgroundMenu);
            graphics.Draw_Font("Fruits Basket", 200, 100, 80, {21, 52, 72}, "Font//iCiel Crocante.otf");
            SDL_GetMouseState(&x, &y);
            if (x >= 260 && x <= 481 && y >= 250 && y <= 286) {
                graphics.Draw_Font("1 - Player", 260, 250, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 260 && x <= 535 && y >= 330 && y <= 365) {
                graphics.Draw_Font("1 - Player", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 260, 330, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else {
                playgPick = false;
                graphics.Draw_Font("1 - Player", 260, 250, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
            }
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 260 && downx <= 481 && downy >= 250 && downy <= 286) {
                            graphics.play(gClick);
                            return 1;
                        }
                }
            }
            graphics.presentScene();
        }
    }
};

#endif // _MENU__H
