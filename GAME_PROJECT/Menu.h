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

    double runMenu(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* backgroundMenu) {
        while (true){
            renderMenu(graphics, backgroundMenu, 0, 0, 800, 600);
            int x, y, downx = 0, downy = 0;
            SDL_GetMouseState(&x, &y);
            if (x >= 130 && x <= 327 && y >= 253 && y <= 285){
                graphics.Draw_Font("New Game", 130, 250, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 130, 338, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 130, 423, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 130, 510, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 130 && x <= 372 && y >= 338 && y <= 369) {
                graphics.Draw_Font("INSTRUCTION", 130, 335, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 130, 253, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 130, 423, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 130, 510, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 130 && x <= 347 && y >= 423 && y <= 455) {
                graphics.Draw_Font("High score", 130, 420, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 130, 253, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 130, 338, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 130, 510, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 130 && x <= 324 && y >= 510 && y <= 543) {
                graphics.Draw_Font("Quit game", 130, 507, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("New Game", 130, 253, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 130, 338, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 130, 423, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else {
                playgPick = false;
                graphics.Draw_Font("New Game", 130, 253, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("INSTRUCTION", 130, 338, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("High score", 130, 423, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("Quit game", 130, 510, sizeSmall, colorMenu1,  "Assest//Font//iCiel Crocante.otf");
            }
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        return -1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        downx = event.button.x;
                        downy = event.button.y;
                        if (downx >= 130 && downx <= 327 && downy >= 253 && downy <= 285) {
                            graphics.play(gClick);
                            open1 = true;
                            return 1;
                        }else if (downx >= 130 && downx <= 372 && downy >= 338 && downy <= 369){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            open2 = true;
                            return 2;
                        }else if (downx >= 130 && downx <= 347 && downy >= 423 && downy <= 455){
                            graphics.play(gClick);
                            open3 = true;
                            return 3;
                        }else if (downx >= 130 && downx <= 324 && downy >= 510 && downy <= 543){
                            graphics.play(gClick);
                            SDL_Delay(500);
                            return 4;
                        }
                }
            }
            graphics.presentScene();
        }
    }

    double rungameMode(Graphics graphics, Mix_Chunk* gPick, Mix_Chunk* gClick, SDL_Texture* selectMode, SDL_Texture* Back ) {
        int x, y, downx, downy;
        while (true) {
            renderMenu(graphics, selectMode,0 , 0, 800, 600);
            renderMenu(graphics, Back, 680, 145, 120, 41);
            SDL_GetMouseState(&x, &y);
            if (x >= 310 && x <= 492 && y >= 250 && y <= 281) {
                graphics.Draw_Font("1 - Player", 310, 250, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 310, 330, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick)
                {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else if (x >= 310 && x <= 498 && y >= 330 && y <= 362) {
                graphics.Draw_Font("1 - Player", 310, 250, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 310, 330, sizeBig, colorMenu2, "Assest//Font//iCiel Crocante.otf");
                if (!playgPick) {
                    graphics.play(gPick);
                    playgPick = true;
                }
            } else {
                playgPick = false;
                graphics.Draw_Font("1 - Player", 310, 250, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
                graphics.Draw_Font("2 - Player", 310, 330, sizeSmall, colorMenu1, "Assest//Font//iCiel Crocante.otf");
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
                            openGameover = true;
                            return 1.1;
                        }else if (downx >= 260 && downx <= 535 && downy >= 330 && downy <= 365){
                            graphics.play(gClick);
                            isLosegame = false;
                            quit = false;
                            isPause = false;
                            openWinner = true;
                            return 1.2;
                        }else if (downx >= 680 && downx <= 800 && downy >= 145 && downy <= 186){
                            open1 = false;
                            graphics.play(gClick);
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
                            return 1;
                        }
                 }
             }
         graphics.presentScene();
        }

    }
    double clickGameover(Graphics graphics, Mix_Chunk *gClick, SDL_Texture* Gameover, int basket_1_countFruit, int highScore){
        int downx = 0;
        int downy = 0;
        string number1 = to_string(basket_1_countFruit);
        string number2 = to_string(highScore);
        while (true){
            renderMenu(graphics, Gameover, 0, 0, 800, 600);
            graphics.Draw_Font("Your Score: ",255, 300, 40 , colorMenu2,"Assest//Font//iCiel Crocante.otf");
            graphics.Draw_Font(number1.c_str(), 495, 300, 40 , {169, 29, 58},"Assest//Font//iCiel Crocante.otf");
            graphics.Draw_Font("High Score: ",255, 350, 40 , colorMenu2,"Assest//Font//iCiel Crocante.otf");
            graphics.Draw_Font(number2.c_str(), 495, 350, 40 , {169, 29, 58},"Assest//Font//iCiel Crocante.otf");

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
                        if (downx >= 165 && downx <= 313 && downy >= 421 && downy <= 471)
                        {
                            graphics.play(gClick);
                            return 1;
                        }else if (downx >= 486 && downx <= 642 && downy >= 421 && downy <= 471){
                            graphics.play(gClick);
                            return 2;
                        }
                 }
             }
            graphics.presentScene();
        }
    }
};

#endif // _MENU__H
