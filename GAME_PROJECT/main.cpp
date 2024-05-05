#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"
#include <ctime>
#include <cmath>
#include <SDL_ttf.h>
#include "Menu.h"
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    Graphics graphics;
    graphics.init();
    Menu menu;
    Mix_Music *gMusic = graphics.loadMusic("Music//SoundTrack.mp3");
    graphics.play(gMusic);
    Mix_Chunk *gSelectFruit = graphics.loadSound("Music//SelectFruit.mp3");
    Mix_Chunk *gSelectTime = graphics.loadSound("Music//SelectTime.mp3");
    Mix_Chunk *gBom = graphics.loadSound("Music//Fail.mp3");
    Mix_Chunk *gPick = graphics.loadSound("Music//Pick.mp3");
    Mix_Chunk *gClick = graphics.loadSound("Music//Click.mp3");
    Mix_Chunk *gPoison = graphics.loadSound("Music//Poison.mp3");

    SDL_Texture* backgroundMenu = graphics.loadTexture("Image//bgMenu.png");
    SDL_Texture* Instruction = graphics.loadTexture("Image//Instruction.jpg");

    int numberBackground = rand() % 3 ;
    SDL_Texture* background = NULL;
    SDL_Color colorText;
    if ( numberBackground == 0) {
        background = graphics.loadTexture("Image//Background0.jpg");
         colorText = {255, 255, 255};
    }else if (numberBackground == 1) {
        background = graphics.loadTexture("Image//Background1.jpg");
         colorText= {255, 255, 255};
    }
     else if (numberBackground == 2) {
        background = graphics.loadTexture("Image//Background2.jpg");
         colorText = {0, 0, 0};
     }

    SDL_Texture* basket1 = graphics.loadTexture("Image//Basket1.png");
    SDL_Texture* basket2 = graphics.loadTexture("Image//Basket2.png");
    SDL_Texture* fruitTexture1 = graphics.loadTexture("Image//Watermelon.png");
    SDL_Texture* fruitTexture2 = graphics.loadTexture("Image//Banana.png");
    SDL_Texture* fruitTexture3 = graphics.loadTexture("Image//Bom.png");
    SDL_Texture* fruitTexture4 = graphics.loadTexture("Image//Strawberry.png");
    SDL_Texture* fruitTexture5 = graphics.loadTexture("Image//Grape.png");
    SDL_Texture* fruitTexture6 = graphics.loadTexture("Image//TIME.png");
    SDL_Texture* fruitTexture7 = graphics.loadTexture("Image//Poison.png");
    if (!fruitTexture1 || !fruitTexture2 || !fruitTexture3  ||!fruitTexture4 || !fruitTexture5 || !fruitTexture6) {
        graphics.quit();
        return 1;
    }

    Basket basket_1(100, 400, basket1);
    Basket basket_2(500, 400, basket2);
    Fruit fruit1(SCREEN_WIDTH / 2, -2500, fruitTexture1);
    Fruit fruit2(100, -2000, fruitTexture2);
    Fruit fruit3(400, -3000, fruitTexture3);
    Fruit fruit4(300, -1000, fruitTexture4);
    Fruit fruit5(700, -2300, fruitTexture5);
    Fruit fruit6(200, -4000, fruitTexture6);
    Fruit fruit7(500, -3500, fruitTexture7);

    int retMenu = menu.runMenu(graphics, gPick, gClick, backgroundMenu);
    if (retMenu == -1 || retMenu == 4){
        quit = true;
    }else if (retMenu == 1){
        retMenu = menu.rungameMode(graphics, gPick, gClick, backgroundMenu);
        if (retMenu == -1){
            quit = true;
        }
    }else if (retMenu == 2){
        graphics.renderClear();
        graphics.prepareScene(Instruction);
        graphics.presentScene();
        menu.waitUntilKeyPressed();
    }

        while (!quit) {
          while (SDL_PollEvent(&event)) {
             switch (event.type){
                 case SDL_QUIT:
                    exit(0);
                    break;
           }
        }

        fruit1.move();
        fruit2.move();
        if (countFruit >= 10){
            fruit3.move();
        }

        fruit4.move();
        fruit5.move();
        fruit7.move();
        if (countFruit <= 20){
            fruit6.move();
        }else{
            fruit6.moveInSineWave();

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP]) basket_1.turnNorth();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) basket_1.turnSouth();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) basket_1.turnWest();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) basket_1.turnEast();

       Touch(graphics,basket_1, fruit1, gSelectFruit);
       Touch(graphics,basket_1, fruit2, gSelectFruit);
       Touch(graphics,basket_1, fruit4, gSelectFruit);
       Touch(graphics,basket_1, fruit5, gSelectFruit);

       if (countFruit <= 20){
            if (basket_1.canTouch(fruit6)){
                timePlay += 3;
                fruit6.rect.y = -FRUIT_SIZE;
                fruit6.rect.x = rand() % 800;
                graphics.play(gSelectTime);
            }
    }
        graphics.renderClear();
        graphics.prepareScene(background);
        fruit1.draw(graphics.renderer);
        fruit2.draw(graphics.renderer);
        fruit3.draw(graphics.renderer);
        fruit4.draw(graphics.renderer);
        fruit5.draw(graphics.renderer);
        fruit6.draw(graphics.renderer);
        fruit7.draw(graphics.renderer);
        basket_1.draw(graphics.renderer);
        basket_2.draw(graphics.renderer);

        string number = to_string(countFruit);
        string str_time = "Time: ";

        if (basket_1.canTouch(fruit6)){
        timePlay += 3;
        fruit6.rect.y = -FRUIT_SIZE;
        verticalShift += rand() % 800;
        graphics.play(gSelectTime);
      }
        if (basket_1.canTouch(fruit3)){
        graphics.play(gBom);
        SDL_Delay(1000);
        quit = true;
      }
        if (basket_1.canTouch(fruit7)){
        timePlay -= 3;
        fruit7.run();
        graphics.play(gPoison);
      }
        Uint32 timeDown = timePlay - SDL_GetTicks() / 1000;
        string str_val = to_string(timeDown);
        str_time += str_val;

        graphics.Draw_Font("Your score: ",10, 10, 40 , colorText,"Font//True Lies.ttf" );
        graphics.Draw_Font(number.c_str(), 230, 10, 35 , colorText,"Font//True Lies.ttf" );
        if (timeDown == 0){
            SDL_Delay(800);
            quit = true;
          }
        graphics.Draw_Font(str_time.c_str(), 600, 10,45, colorText,"Font//True Lies.ttf" );
        graphics.presentScene();
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







