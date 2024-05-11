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
    Mix_Music *gMusic = graphics.loadMusic("Music//SoundTrack.mp3");
    Mix_Chunk *gSelectFruit = graphics.loadSound("Music//SelectFruit.mp3");
    Mix_Chunk *gSelectTime = graphics.loadSound("Music//SelectTime.mp3");
    Mix_Chunk *gBom = graphics.loadSound("Music//Fail.mp3");
    Mix_Chunk *gPick = graphics.loadSound("Music//Pick.mp3");
    Mix_Chunk *gClick = graphics.loadSound("Music//Click.mp3");
    Mix_Chunk *gPoison = graphics.loadSound("Music//Poison.mp3");

    SDL_Texture* basket1 = graphics.loadTexture("Image//Basket1.png");
    SDL_Texture* basket2 = graphics.loadTexture("Image//Basket2.png");
    SDL_Texture* fruitTexture1 = graphics.loadTexture("Image//Watermelon.png");
    SDL_Texture* fruitTexture2 = graphics.loadTexture("Image//Banana.png");
    SDL_Texture* fruitTexture3 = graphics.loadTexture("Image//Bom.png");
    SDL_Texture* fruitTexture4 = graphics.loadTexture("Image//Strawberry.png");
    SDL_Texture* fruitTexture5 = graphics.loadTexture("Image//Grape.png");
    SDL_Texture* fruitTexture6 = graphics.loadTexture("Image//Time.png");
    SDL_Texture* fruitTexture7 = graphics.loadTexture("Image//Poison.png");
    SDL_Texture* backgroundMenu = graphics.loadTexture("Image//BgMenu.png");
    SDL_Texture* Winner = graphics.loadTexture("Image//Winner.png");
    SDL_Texture* Instruction = graphics.loadTexture("Image//Instruction.png");
    SDL_Texture* Back = graphics.loadTexture("Image//Back.png");
    SDL_Texture* Pause = graphics.loadTexture("Image//Pause.png");
    SDL_Texture* Pause2 = graphics.loadTexture("Image//Pause2.png");
    SDL_Texture* quitWinner = graphics.loadTexture("Image//quitWinner.png");

    Basket basket_1(500, 400,100, 66, basket1);
    Basket basket_2(100, 400, 100, 75, basket2);
    Fruit Watermelon(SCREEN_WIDTH / 2, -2500, fruitTexture1);
    Fruit Banana(100, -2000, fruitTexture2);
    Fruit Bom(400, -3000, fruitTexture3);
    Fruit Strawberry(300, -1000, fruitTexture4);
    Fruit Grape(700, -2300, fruitTexture5);
    Fruit Time(200, -4000, fruitTexture6);
    Fruit Poison(500, -3500, fruitTexture7);

    int numberBackground = rand() % 3 ;
    SDL_Texture* background = NULL;
    SDL_Color colorText;
    if ( numberBackground == 0) {
        background = graphics.loadTexture("Image//Background0.jpg");
         colorText = {255, 255, 255};
    }else if (numberBackground == 1) {
        background = graphics.loadTexture("Image//Background1.jpg");
         colorText= {255, 255, 255};
    }else if (numberBackground == 2) {
        background = graphics.loadTexture("Image//Background2.jpg");
         colorText = {0, 0, 0};
    }

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
        graphics.play(gMusic);
        double retMenu = menu.runMenu(graphics, gPick, gClick, backgroundMenu);
        if ( retMenu == 4 || retMenu == -1) isRunning = false;
        else if (retMenu == 1)
        {
            while (open1){
                menu.renderMenu(graphics, backgroundMenu,0, 0, 800, 600);
                graphics.presentScene();
                retMenu = menu.rungameMode(graphics, gPick, gClick, backgroundMenu, Back);
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
                menu.renderMenu(graphics, backgroundMenu,0, 0, 800, 600);
                menu.renderMenu(graphics, Back, 680, 60, 120, 41);
                graphics.Draw_Font("HIGHSCORE: ",200, 280, 60, colorMenu1,"Font//iCiel Crocante.otf" );
                ifstream file("Highscore.txt");
                if (file.is_open())
                {
                    if (file.peek() != EOF)
                    {
                        string HIGHSCORE;
                        file >> HIGHSCORE;
                        graphics.Draw_Font(HIGHSCORE.c_str(), 570, 280,60 , colorMenu1,"Font//iCiel Crocante.otf" );
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
                if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) isPause = 1;
                int delayTime = SDL_GetTicks() / 1000 - prevTime;
                prevTime = SDL_GetTicks() / 1000;
                totalTime -= delayTime;
                Watermelon.move();
                Banana.move();
                if (basket_1.countFruit >= 0 || basket_2.countFruit >= 0) Bom.move();
               // if (basket_1.countFruit >= 5 || basket_2.countFruit >= 5) Bom.move();
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
                            graphics.presentScene();
                            if(basket_1.countFruit > basket_2.countFruit){
                                graphics.Draw_Font("Winner:", 200, 300 , 40 , colorMenu1,"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_1", 370, 290 ,50 , {199, 54, 89},"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_1's score:", 200, 360 , 40 , colorMenu1,"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font(number1.c_str(), 560, 355 , 45 , colorMenu1,"Font//iCiel Crocante.otf" );

                            }else{
                                graphics.Draw_Font("Winner:", 200, 300 , 40 , colorMenu1,"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_2", 370, 290 ,50 , {199, 54, 89},"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font("Player_2's score:", 200, 360 , 40 , colorMenu1,"Font//iCiel Crocante.otf" );
                                graphics.Draw_Font(number2.c_str(), 560, 355 , 45 , colorMenu1,"Font//iCiel Crocante.otf" );

                            }
                            if(menu.clickQuitwinner(graphics, gClick, quitWinner)==1){
                                openWinner = false;
                            }
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
                        basket_1.countFruit = 0;
                        basket_2.countFruit = 0;
                        quit = true;
                        isRestart = true;
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
                    graphics.Draw_Font("Your score: ",10, 10, 35 , colorText,"Font//True Lies.ttf" );
                    graphics.Draw_Font(number1.c_str(), 230, 10, 35 , colorText,"Font//True Lies.ttf" );
                    graphics.Draw_Font(str_time.c_str(), 600, 10,40, colorText,"Font//True Lies.ttf" );
                    if (!isHighScoreFileEmpty()) currentScore = basket_1.countFruit;
                    int highScore = readHighScore();
                    if (currentScore > highScore) updateHighScore(currentScore);
                }
                else {
                     graphics.Draw_Font("Player-2: ",10, 10, 35 , colorText,"Font//True Lies.ttf" );
                     graphics.Draw_Font(number2.c_str(), 170, 10, 30 , colorText,"Font//True Lies.ttf" );
                     graphics.Draw_Font("Player-1: ",540, 10, 35 , colorText,"Font//True Lies.ttf" );
                     graphics.Draw_Font(number1.c_str(),700, 10, 30 , colorText,"Font//True Lies.ttf" );
                     graphics.Draw_Font(str_time.c_str(), 280, 10,40, colorText,"Font//True Lies.ttf" );

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
                if (Mix_PausedMusic() == 0 && open == true){
                    menu.renderMenu (graphics, Pause, 100, 150, 600, 300);
                }else if (Mix_PausedMusic() == 1 && open == false){
                    menu.renderMenu(graphics, Pause2, 100, 150, 600, 300);
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
                                //Play the music
                                Mix_PlayMusic( gMusic, -1 );
                            }
                            //If music is being played
                            else
                            {
                                //If the music is paused
                                if( Mix_PausedMusic() == 1 )
                                {
                                    //Resume the music
                                    Mix_ResumeMusic();
                                }
                                //If the music is playing
                                else
                                {
                                    //Pause the music
                                    Mix_PauseMusic();

                                }
                            }
                            break;
                        case SDLK_p:
                             isPause = 0;
                             open = !open;
                             break;
                }

            }

            }
            graphics.presentScene();
            }
        }
    }

    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    if (gSelectFruit != nullptr) Mix_FreeChunk( gSelectFruit );
    if (gSelectTime != nullptr) Mix_FreeChunk( gSelectTime );

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






