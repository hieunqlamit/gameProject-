#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"
#include <ctime>
#include <cmath>

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    SDL_Texture* background = graphics.loadTexture("Image//Background.jpg");
    graphics.prepareScene(background);
    graphics.presentScene();

    SDL_Texture* basket = graphics.loadTexture("Image//Basket.png");

    // Vị trí ban đầu của basket
    // Load texture cho các quả
    SDL_Texture* fruitTexture1 = graphics.loadTexture("Image//Watermelon.png");
    SDL_Texture* fruitTexture2 = graphics.loadTexture("Image//Banana.png");
    SDL_Texture* fruitTexture3 = graphics.loadTexture("Image//Bom.png");
    SDL_Texture* fruitTexture4 = graphics.loadTexture("Image//Strawberry.png");
    SDL_Texture* fruitTexture5 = graphics.loadTexture("Image//Grape.png");
    SDL_Texture* fruitTexture6 = graphics.loadTexture("Image//Enery.png");


    if (!fruitTexture1 || !fruitTexture2 || !fruitTexture3  ||!fruitTexture4 || !fruitTexture5 || !fruitTexture6) {
        graphics.quit();
        return 1;
    }

    // Khởi tạo bộ sinh số ngẫu nhiên với hạt giống từ thời gian hiện tại
    srand(time(nullptr));
    Basket basket1(300, 400, basket);

    // Tạo các đối tượng chuột với các vị trí ban đầu khác nhau
    Fruit fruit1(SCREEN_WIDTH / 2, 0, fruitTexture1);
    Fruit fruit2(100, 200, fruitTexture2);
    Fruit fruit3(400, 50, fruitTexture3);
    Fruit fruit4(300, 100, fruitTexture4);
    Fruit fruit5(700, 300, fruitTexture5);
    Fruit fruit6(200, 0, fruitTexture6);
    int count = 0;

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Di chuyển và vẽ các đối tượng quả
        fruit1.move();
        fruit2.move();
        if (count <= 10){
            fruit3.move();
        }else {
            fruit3.moveInSineWave();
        }
        fruit4.move();
        fruit5.move();
        fruit6.moveInSineWave();
        if ( Amplitude <= 200){
             Amplitude += 0.5;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) basket1.turnNorth();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) basket1.turnSouth();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) basket1.turnWest();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) basket1.turnEast();

        if (basket1.canTouch(fruit1)){
            count ++;
            fruit1.run();
        }
        if (basket1.canTouch(fruit2)){
            count ++;
            fruit2.run();
        }
        if (basket1.canTouch(fruit4)){
            count ++;
            fruit4.run();
        }
        if (basket1.canTouch(fruit5)){
            count ++;
            fruit5.run();
        }
        if (basket1.canTouch(fruit6)){
            count ++;
            fruit6.run();
        }

        // Xóa màn hình
        graphics.renderClear();

        // Vẽ lại background
        graphics.prepareScene(background);


        // Vẽ các đối tượng quả
        fruit1.draw(graphics.renderer);
        fruit2.draw(graphics.renderer);
        fruit3.draw(graphics.renderer);
        fruit4.draw(graphics.renderer);
        fruit5.draw(graphics.renderer);
        fruit6.draw(graphics.renderer);
        basket1.draw(graphics.renderer);

        // Cập nhật màn hình
        graphics.presentScene();
        SDL_Delay(10); // Đợi 10ms
    }

    // Giải phóng texture
    SDL_DestroyTexture(basket);
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






