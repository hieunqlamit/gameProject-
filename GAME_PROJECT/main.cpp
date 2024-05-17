#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "Character.h"
#include <ctime>
#include <cmath>
#include <SDL_ttf.h>
#include "Menu.h"
#include "Score.h";
using namespace std;


int main(int argc, char *argv[])
{
    srand(time(nullptr));
    Graphics graphics;
    graphics.init();
    Menu menu;
    Mix_Music *gMusic = graphics.loadMusic("Assest//Music//SoundTrack.mp3");
    Mix_Music *gGame = graphics.loadMusic("Assest//Music//musicMenu.mp3");
    Mix_Chunk *gSelectFruit = graphics.loadSound("Assest//Music//SelectFruit.mp3");
    Mix_Chunk *gSelectTime = graphics.loadSound("Assest//Music//SelectTime.mp3");
    Mix_Chunk *gBom = graphics.loadSound("Assest//Music//Fail.mp3");
    Mix_Chunk *gPick = graphics.loadSound("Assest//Music//Pick.mp3");
    Mix_Chunk *gClick = graphics.loadSound("Assest//Music//Click.mp3");
    Mix_Chunk *gPoison = graphics.loadSound("Assest//Music//Poison.mp3");
    SDL_Texture* basket1 = graphics.loadTexture("Assest//Image//Basket1.png");
    SDL_Texture* basket2 = graphics.loadTexture("Assest//Image//Basket2.png");
    SDL_Texture* fruitTexture1 = graphics.loadTexture("Assest//Image//Watermelon.png");
    SDL_Texture* fruitTexture2 = graphics.loadTexture("Assest//Image//Banana.png");
    SDL_Texture* fruitTexture3 = graphics.loadTexture("Assest//Image//Bom.png");
    SDL_Texture* fruitTexture4 = graphics.loadTexture("Assest//Image//Strawberry.png");
    SDL_Texture* fruitTexture5 = graphics.loadTexture("Assest//Image//Grape.png");
    SDL_Texture* fruitTexture6 = graphics.loadTexture("Assest//Image//Time.png");
    SDL_Texture* fruitTexture7 = graphics.loadTexture("Assest//Image//Poison.png");
    SDL_Texture* backgroundMenu = graphics.loadTexture("Assest//Image//backgroundMenu.png");
    SDL_Texture* backgroundHighscore = graphics.loadTexture("Assest//Image//backgroundHighscore.png");
    SDL_Texture* selectMode = graphics.loadTexture("Assest//Image//selectMode.png");
    SDL_Texture* Winner = graphics.loadTexture("Assest//Image//Winner.png");
    SDL_Texture* Gameover = graphics.loadTexture("Assest//Image//Gameover.png");
    SDL_Texture* Instruction = graphics.loadTexture("Assest//Image//Instruction.png");
    SDL_Texture* Back = graphics.loadTexture("Assest//Image//Back.png");
    SDL_Texture* Pause = graphics.loadTexture("Assest//Image//Pause.png");
    SDL_Texture* Pause2 = graphics.loadTexture("Assest//Image//Pause2.png");
    SDL_Texture* quitWinner = graphics.loadTexture("Assest//Image//quitWinner.png");

    Basket basket_1(500, 400,100, 66, basket1);
    Basket basket_2(100, 400, 100, 75, basket2);
    Fruit Watermelon(SCREEN_WIDTH / 2, -2500, fruitTexture1);
    Fruit Banana(100, -2000, fruitTexture2);
    Fruit Bom(400, -3000, fruitTexture3);
    Fruit Strawberry(300, -1000, fruitTexture4);
    Fruit Grape(700, -2300, fruitTexture5);
    Fruit Time(200, -4000, fruitTexture6);
    Fruit Poison(500, -3500, fruitTexture7);

    SDL_Texture* background = NULL;
    SDL_Color colorText;
    if (!fruitTexture1 || !fruitTexture2 || !fruitTexture3  ||!fruitTexture4 || !fruitTexture5 || !fruitTexture6) {
        graphics.quit();
        return 1;
    }
    while(isRunning){
    if(isRestart)
    {
        isLosegame = true;
        isRestart = false;
    }
    if (isLosegame == true)
    {
        Mix_PlayMusic(gGame, -1);
        double retMenu = menu.runMenu(graphics, gPick, gClick, backgroundMenu);
        if ( retMenu == 4 || retMenu == -1) isRunning = false;
        else if (retMenu == 1)
        {
            while (open1){
                retMenu = menu.rungameMode(graphics, gPick, gClick, selectMode, Back);
                if (retMenu == 1.1){
                    showBasket_2 = false;
                    open1 = false;
                }else if (retMenu == 1.2){
                    showBasket_2 = true;
                    open1 = false;
                }
            }
        }
        else if (retMenu == 2)
        {
            graphics.renderClear();
            while (open2){
                 graphics.prepareScene(Instruction);
                 menu.renderMenu(graphics, Back, 680, 60, 120, 41);
                 graphics.presentScene();
                 if (menu.clickBack(graphics, gClick, Back) == 1){
                    open2 = false;
                 }
            }
        }
        else if (retMenu == 3)
        {
             graphics.renderClear();
             while(open3){
                menu.renderMenu(graphics, backgroundHighscore,0, 0, 800, 600);
                menu.renderMenu(graphics, Back, 680, 60, 120, 41);
                graphics.Draw_Font("HIGHSCORE: ",200, 280, 60, colorMenu1,"Assest//Font//iCiel Crocante.otf" );
                ifstream file("Highscore.txt");
                if (file.is_open())
                {
                    if (file.peek() != EOF)
                    {
                        string HIGHSCORE;
                        file >> HIGHSCORE;
                        graphics.Draw_Font(HIGHSCORE.c_str(), 570, 280,60 , colorMenu1,"Assest//Font//iCiel Crocante.otf" );
                        file.close();
                    }
                    graphics.presentScene();
                }
                if(menu.clickBack(graphics, gClick, Back) == 1){
                         open3 = false;
                }
            }
        }
    }
    if (isLosegame == false)
    {
        Mix_PlayMusic(gMusic, -1);
        int numberBackground = rand() % 5 ;
        if ( numberBackground == 0) {
            background = graphics.loadTexture("Assest//Image//Background0.jpg");
            colorText = {0, 0, 0};
        }else if (numberBackground == 1) {
            background = graphics.loadTexture("Assest//Image//Background1.jpg");
            colorText = {255, 255, 255};
        }else if (numberBackground == 2) {
            background = graphics.loadTexture("Assest//Image//Background2.jpg");
            colorText = {255, 255, 255};
        }else if (numberBackground == 3){
            background = graphics.loadTexture("Assest//Image//Background3.jpg");
            colorText = {255, 255, 255};
        }else if (numberBackground == 4){
            background = graphics.loadTexture("Assest//Image//Background4.jpg");
            colorText = {255, 255, 255};
        }
        int totalTime = 60;
        int prevTime = SDL_GetTicks() / 1000;
        while (!quit)
        {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT){
                exit(0);
            }
            if(!isPause)
            {
                if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) isPause = true;

                int delayTime = SDL_GetTicks() / 1000 - prevTime;
                prevTime = SDL_GetTicks() / 1000;
                totalTime -= delayTime;

                Watermelon.move();
                Banana.move();
                Bom.move();
                Strawberry.move();
                Grape.move();
                Poison.move();
                if (basket_1.countFruit <= 20) Time.move();
                else
                {
                    Time.moveInSineWave();
                    if (Amplitude <= 100 && basket_1.countFruit  % 10 == 0) Amplitude += 5;
                }
                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                if (currentKeyStates[SDL_SCANCODE_UP]) basket_1.turnNorth();
                if (currentKeyStates[SDL_SCANCODE_DOWN]) basket_1.turnSouth();
                if (currentKeyStates[SDL_SCANCODE_LEFT]) basket_1.turnWest();
                if (currentKeyStates[SDL_SCANCODE_RIGHT]) basket_1.turnEast();

                Touch(graphics,basket_1, Watermelon, gSelectFruit);
                Touch(graphics,basket_1, Banana, gSelectFruit);
                Touch(graphics,basket_1, Strawberry, gSelectFruit);
                Touch(graphics,basket_1, Grape, gSelectFruit);

                if (showBasket_2 == true)
                {
                    if (currentKeyStates[SDL_SCANCODE_W]) basket_2.turnNorth();
                    if (currentKeyStates[SDL_SCANCODE_S]) basket_2.turnSouth();
                    if (currentKeyStates[SDL_SCANCODE_A]) basket_2.turnWest();
                    if (currentKeyStates[SDL_SCANCODE_D]) basket_2.turnEast();
                    Touch(graphics,basket_2, Watermelon, gSelectFruit);
                    Touch(graphics,basket_2, Banana, gSelectFruit);
                    Touch(graphics,basket_2, Strawberry, gSelectFruit);
                    Touch(graphics,basket_2, Grape, gSelectFruit);
                }

                if (basket_1.countFruit <= 20)
                {
                    if (basket_1.canTouch(Time))
                    {
                        totalTime += 3;
                        Time.rect.y = -FRUIT_SIZE;
                        Time.rect.x = rand() % 800;
                        graphics.play(gSelectTime);
                    }
                }
                graphics.renderClear();
                graphics.prepareScene(background);
                Watermelon.draw(graphics.renderer);
                Banana.draw(graphics.renderer);
                Bom.draw(graphics.renderer);
                Strawberry.draw(graphics.renderer);
                Grape.draw(graphics.renderer);
                Time.draw(graphics.renderer);
                Poison.draw(graphics.renderer);
                basket_1.draw(graphics.renderer);
                if (showBasket_2 == true) basket_2.draw(graphics.renderer);
                string number1 = to_string(basket_1.countFruit);
                string number2 = to_string(basket_2.countFruit);
                string str_time = "Time: ";

                if (showBasket_2 == true){
                    if(basket_2.canTouch(Time))
                    {
                        totalTime += 3;
                        Time.rect.y = -FRUIT_SIZE;
                        verticalShift += rand() % 800;
                        graphics.play(gSelectTime);
                    }
                    if (basket_2.canTouch(Bom) || basket_1.canTouch(Bom))
                    {
                        graphics.play(gBom);
                        SDL_Delay(1000);
                        Watermelon.currentRect();
                        Banana.currentRect();
                        Bom.currentRect();
                        Strawberry.currentRect();
                        Grape.currentRect();
                        Time.currentRect();
                        Poison.currentRect();
                        graphics.renderClear();
                        while(openWinner)
                        {
                            graphics.prepareScene(Winner);
                            if(basket_1.countFruit > basket_2.countFruit){
                                graphics.Draw_Font("Winner:", 200, 300 , 40 , {36, 7, 80} ,"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_1", 370, 290 ,50 , {199, 54, 89},"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_1's score:", 200, 360 , 40 , {36, 7, 80},"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font(number1.c_str(), 560, 355 , 45 , {36, 7, 80},"Assest//Font//iCiel Crocante.otf" );

                            }else{
                                graphics.Draw_Font("Winner:", 200, 300 , 40 ,{36, 7, 80},"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_2", 370, 290 ,50 , {199, 54, 89},"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_2's score:", 200, 360 , 40 , {36, 7, 80},"Assest//Font//iCiel Crocante.otf" );
                                graphics.Draw_Font(number2.c_str(), 560, 355 , 45 , {36, 7, 80},"Assest//Font//iCiel Crocante.otf" );

                            }
                            if(menu.clickQuitwinner(graphics, gClick, quitWinner)==1){
                                openWinner = false;
                            }
                            graphics.presentScene();
                        }
                        basket_1.countFruit = 0;
                        basket_2.countFruit = 0;
                        quit = true;
                        isRestart = true;
                    }
                    if(basket_2.canTouch(Poison))
                    {
                        totalTime -= 3;
                        Poison.run();
                        graphics.play(gPoison);
                    }
                    if(basket_1.canTouch(Poison))
                    {
                        totalTime -= 3;
                        Poison.run();
                        graphics.play(gPoison);
                    }

                }else{
                    if (basket_1.canTouch(Time))
                    {
                        totalTime += 3;
                        Time.rect.y = -FRUIT_SIZE;
                        verticalShift += rand() % 800;
                        graphics.play(gSelectTime);
                    }
                    if (basket_1.canTouch(Bom))
                    {
                        graphics.play(gBom);
                        SDL_Delay(1000);
                        Watermelon.currentRect();
                        Banana.currentRect();
                        Bom.currentRect();
                        Strawberry.currentRect();
                        Grape.currentRect();
                        Time.currentRect();
                        Poison.currentRect();
                        graphics.renderClear();
                        openGameover = true;
                        while(openGameover)
                        {

                            string SC = to_string(basket_1.countFruit);

                            int n = menu.clickGameover(graphics, gClick, Gameover,basket_1.countFruit, readHighScore());
                            if (!isHighScoreFileEmpty()) currentScore = basket_1.countFruit;
                            int highScore = readHighScore();
                            if (currentScore > highScore) updateHighScore(currentScore);
                            if ( n == 1){
                                basket_1.countFruit = 0;
                                quit = false;
                                totalTime = 60;
                                prevTime = SDL_GetTicks() / 1000;
                                openGameover = false;
                            }
                            if( n == 2){
                                basket_1.countFruit = 0;
                                quit = true;
                                isRestart = true;
                                openGameover = false;
                            }
                        }

                    }
                    if (basket_1.canTouch(Poison))
                    {
                        totalTime -= 3;
                        Poison.run();
                        graphics.play(gPoison);
                    }
                }
                string str_val = to_string(totalTime);
                str_time += str_val;

                if (showBasket_2 == false)
                {
                    graphics.Draw_Font("Your score: ",10, 10, 35 , colorText,"Assest//Font//True Lies.ttf" );
                    graphics.Draw_Font(number1.c_str(), 230, 10, 35 , colorText,"Assest//Font//True Lies.ttf" );
                    graphics.Draw_Font(str_time.c_str(), 600, 10,40, colorText,"Assest//Font//True Lies.ttf" );
                }
                else {
                     graphics.Draw_Font("Player-2: ",10, 10, 35 , colorText,"Assest//Font//True Lies.ttf" );
                     graphics.Draw_Font(number2.c_str(), 170, 10, 30 , colorText,"Assest//Font//True Lies.ttf" );
                     graphics.Draw_Font("Player-1: ",540, 10, 35 , colorText,"Assest//Font//True Lies.ttf" );
                     graphics.Draw_Font(number1.c_str(),700, 10, 30 , colorText,"Assest//Font//True Lies.ttf" );
                     graphics.Draw_Font(str_time.c_str(), 280, 10,40, colorText,"Assest//Font//True Lies.ttf" );

                }
                if (totalTime == 0)
                {
                    SDL_Delay(300);
                    quit = true;
                    isLosegame = true;
                    basket_1.countFruit = 0;
                    basket_2.countFruit = 0;
                }
            }else {
                prevTime = SDL_GetTicks() / 1000;
                int highScore = readHighScore();
                string hScore = to_string(highScore);
                if ( turnonMusic == true){
                    menu.renderMenu (graphics, Pause, 200, 150, 400, 300);
                    graphics.Draw_Font("High Score: ",240, 220, 40 , colorMenu1,"Assest//Font//iCiel Crocante.otf");
                    graphics.Draw_Font(hScore.c_str(), 480, 220, 40 , colorMenu1,"Assest//Font//iCiel Crocante.otf");

                }else if (turnonMusic == false){
                    menu.renderMenu(graphics, Pause2, 200, 150, 400, 300);
                    graphics.Draw_Font("High Score: ",240, 220, 40 , colorMenu1,"Assest//Font//iCiel Crocante.otf");
                    graphics.Draw_Font(hScore.c_str(), 480, 220, 40 , colorMenu1,"Assest//Font//iCiel Crocante.otf");
                }
                if(event.type == SDL_KEYDOWN)
                {
                    switch(event.key.keysym.sym )
                    {
                        case SDLK_ESCAPE:
                            Watermelon.currentRect();
                            Banana.currentRect();
                            Bom.currentRect();
                            Strawberry.currentRect();
                            Grape.currentRect();
                            Time.currentRect();
                            Poison.currentRect();
                            basket_1.countFruit = 0;
                            basket_2.countFruit = 0;
                            quit = true;
                            isRestart = true;
                            break;
                        case SDLK_i:
                            if( Mix_PlayingMusic() == 0 )
                            {
                                Mix_PlayMusic( gMusic, -1 );
                            }
                            else
                            {
                                if( Mix_PausedMusic() == 1 )
                                {
                                    Mix_ResumeMusic();
                                }
                                else
                                {
                                    Mix_PauseMusic();
                                }
                            }
                            break;
                        case SDLK_p:
                             isPause = false;
                             if ( Mix_PausedMusic() == 1 ){
                                turnonMusic = false;
                             }else{
                                turnonMusic = true;
                             }
                             break;
                }
            }

            }
            graphics.presentScene();
        }
    }
    }

    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    if (gGame != nullptr) Mix_FreeMusic( gGame );
    if (gSelectFruit != nullptr) Mix_FreeChunk( gSelectFruit );
    if (gSelectTime != nullptr) Mix_FreeChunk( gSelectTime );
    if (gBom != nullptr) Mix_FreeChunk( gBom );
    if (gPick != nullptr) Mix_FreeChunk( gPick );
    if (gClick != nullptr) Mix_FreeChunk( gClick );
    if (gPoison != nullptr) Mix_FreeChunk( gPoison );

    SDL_DestroyTexture(basket1);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(fruitTexture1);
    SDL_DestroyTexture(fruitTexture2);
    SDL_DestroyTexture(fruitTexture3);
    SDL_DestroyTexture(fruitTexture4);
    SDL_DestroyTexture(fruitTexture5);
    SDL_DestroyTexture(fruitTexture6);
    graphics.quit();
    return 0;
}






