#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include "defs.h"

using namespace std;

struct Menu {
    void renderMenu(Graphics& graphics, SDL_Texture* texture, int x, int y, int width, int high )
    {
        SDL_Rect rectMenu = {x, y, width, high};
        SDL_RenderCopy(graphics.renderer, texture, NULL, &rectMenu);
    }
//    void waitUntilKeyPressed()
//    {
//        SDL_Event e;
//        while (true)
//        {
//            if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
//                return;
//            SDL_Delay(100);
//        }
//    }

    double runMenu(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* backgroundMenu) {
        while (true){
            renderMenu(graphics, backgroundMenu, 0, 0, 800, 600);
            graphics.Draw_Font("Fruits Basket", 200, 100, 80, {21, 52, 72}, "Font//iCiel Crocante.otf");
            int x, y, downx = 0, downy = 0;
            SDL_GetMouseState(&x, &y);
            if (x >= 260 && x <= 481 && y >= 250 && y <= 286){
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
                            open1 = true;
                            return 1;
                        }else if (downx >= 260 && downx <= 479 && downy >= 490 && downy <= 528){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            return 4;
                        }else if (downx >= 260 && downx <= 535 && downy >= 330 && downy <= 365){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            open2 = true;
                            return 2;
                        }else if (downx >= 260 && downx <= 504 && downy >= 410 && downy <= 447){
                            graphics.play(gClick);
                            open3 = true;
                            return 3;
                        }
                }
            }
            graphics.presentScene();
        }
    }

    double rungameMode(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* backgroundMenu, SDL_Texture* Back ) {
        int x, y, downx, downy;
        while (true) {
            renderMenu(graphics, backgroundMenu,0 , 0, 800, 600);
            renderMenu(graphics, Back, 680, 60, 120, 41);
            graphics.Draw_Font("Fruits Basket", 200, 120, 80, {21, 52, 72}, "Font//iCiel Crocante.otf");
            SDL_GetMouseState(&x, &y);
            if (x >= 260 && x <= 481 && y >= 250 && y <= 286) {
                graphics.Draw_Font("1 - Player", 260, 250, sizeBig, colorMenu2, "Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 260, 330, sizeSmall, colorMenu1, "Font//iCiel Crocante.otf");
                if (!playgPick)
                {
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
                            isLosegame = false;
                            quit = false;
                            isPause = false;
                            openWinner  = true;
                            return 1.1;
                        }else if (downx >= 260 && downx <= 535 && downy >= 330 && downy <= 365){
                            graphics.play(gClick);
                            isLosegame = false;
                            quit = false;
                            isPause = false;
                            openWinner = true;
                            return 1.2;
                        }else if (downx >= 680 && downx <= 800 && downy >= 50 && downy <= 98){
                            open1 = false;
                            return 0;
                        }
                }
            }
            graphics.presentScene();
        }
    }
     double clickBack(Graphics graphics, Mix_Chunk *gClick, SDL_Texture* Back ){
        int downx, downy;
        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 680 && downx <= 800 && downy >= 60 && downy <= 101) {
                            graphics.play(gClick);
                            return 1;
                        }
                }
        }
    }

    double clickPause(Graphics graphics, Mix_Chunk *gClick, SDL_Texture* Resume){
        int downx = 0;
        int downy = 0;
        while(true)
        {
            renderMenu(graphics, Resume, 200, 200, 100 , 100);
             while (SDL_PollEvent(&event))
             {
                switch (event.type)
                {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 200 && downx <= 300 && downy >= 200 && downy <= 300)
                        {
                            graphics.play(gClick);
                            isLosegame = false;
                            quit = false;
                            isPause = false;
                            return 1;
                        }
                 }
             }
         graphics.presentScene();
        }
    }
    double clickQuitwinner(Graphics graphics, Mix_Chunk *gClick, SDL_Texture* quitWinner){
        int downx = 0;
        int downy = 0;
        while(true)
        {
            renderMenu(graphics, quitWinner, 350, 430, 100 , 54);
             while (SDL_PollEvent(&event))
             {
                switch (event.type)
                {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 350 && downx <= 450 && downy >= 430 && downy <= 484)
                        {
                            graphics.play(gClick);
                            isLosegame = false;
                            quit = false;
                            isPause = false;
                            return 1;
                        }
                 }
             }
         graphics.presentScene();
        }

    }
};

#endif // _MENU__H
