#ifndef CHARACTER_H
#define CHARACTER_H
#include <cmath>

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    int r1_center_x = r1.x + r1.w / 2;
    int r1_center_y = r1.y + r1.h / 2;
    int r2_center_x = r2.x + r2.w / 2;
    int r2_center_y = r2.y + r2.h / 2;

    bool r1_inside_r2 = (r1_center_x >= r2.x && r1_center_x <= r2.x + r2.w &&
        r1_center_y >= r2.y && r1_center_y <= r2.y + r2.h);
    bool r2_inside_r1 = (r2_center_x >= r1.x && r2_center_x <= r1.x + r1.w &&
        r2_center_y >= r1.y && r2_center_y <= r1.y + r1.h);
    return r1_inside_r2 || r2_inside_r1;
}

struct Fruit {
    SDL_Rect rect;
    int dy = 0;
    SDL_Texture* texture;
    Fruit(int x, int y, SDL_Texture* tex) : texture(tex)
    {
        rect.x = x;
        rect.y = y;
        rect.h = FRUIT_SIZE;
        rect.w = FRUIT_SIZE;
    }
    void currentRect()
    {
        rect.x = rand() % 800;
        rect.y = -(rand() % 3000);
    }

    void draw(SDL_Renderer* renderer)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }

    void move()
    {
        rect.y += FRUIT_SPEED;
        if (rect.y >= SCREEN_HEIGHT)
        {
            rect.y = -FRUIT_SIZE;
            rect.x = rand() % (SCREEN_WIDTH - FRUIT_SIZE);
        }
    }
    void moveInSineWave()
    {
        float frequency = 0.03;
        float phaseShift = 10;

        rect.x = Amplitude * sin(frequency * rect.y + phaseShift) + verticalShift;
        rect.y += FRUIT_SPEED;
        if (rect.y >= SCREEN_HEIGHT) {
             rect.y = -100;
             verticalShift += rand() % 800;
        }
        if (verticalShift > 800) {
             verticalShift = 100;
        }
    }
     void run() {
        rect.y = -FRUIT_SIZE;
        SDL_Delay(10);
        rect.x = rand() % 800;
     }
};

struct Basket{
    SDL_Rect rect;
    SDL_Texture* texture;
    int countFruit = 0;
    Basket(int x, int y, int width, int height, SDL_Texture* tex) : texture(tex) {
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
    }
    void turnNorth() {
        if (rect.y >= 0) rect.y -= BASKET_SPEED;
    }
    void turnSouth() {
        if (rect.y <= SCREEN_HEIGHT - 66) rect.y += BASKET_SPEED;
    }
    void turnWest() {
        if (rect.x >= 0)  rect.x -= BASKET_SPEED;
    }
    void turnEast() {
        if (rect.x <= SCREEN_WIDTH - 100) rect.x += BASKET_SPEED;
    }

    void draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
    bool canTouch(const Fruit& fruit1) {
        return overlap(rect, fruit1.rect);
    }
};

    void Touch( Graphics graphics, Basket& basket1, Fruit& fruit1, Mix_Chunk *gSelectFruit)
    {
        if (basket1.canTouch(fruit1)) {
            fruit1.run();
            graphics.play(gSelectFruit);
            basket1.countFruit ++;
            if(basket1.countFruit % 20 == 0  && basket1.countFruit != 0  && FRUIT_SPEED <= 25) {
                FRUIT_SPEED += 1 ;
            }
        }
    }
#endif // CHARACTER_H
