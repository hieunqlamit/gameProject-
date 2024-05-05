#ifndef GAME_H
#define GAME_H
#include <cmath>

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    // Tính toán tâm của hai hình chữ nhật
    int r1_center_x = r1.x + r1.w / 2;
    int r1_center_y = r1.y + r1.h / 2;
    int r2_center_x = r2.x + r2.w / 2;
    int r2_center_y = r2.y + r2.h / 2;

    // Kiểm tra xem tâm của hình chữ nhật thứ nhất có nằm trong hình chữ nhật thứ hai không
    bool r1_inside_r2 = (r1_center_x >= r2.x && r1_center_x <= r2.x + r2.w &&
                         r1_center_y >= r2.y && r1_center_y <= r2.y + r2.h);

    // Kiểm tra xem tâm của hình chữ nhật thứ hai có nằm trong hình chữ nhật thứ nhất không
    bool r2_inside_r1 = (r2_center_x >= r1.x && r2_center_x <= r1.x + r1.w &&
                         r2_center_y >= r1.y && r2_center_y <= r1.y + r1.h);

    // Hai hình chữ nhật overlap nếu tâm của một trong chúng nằm trong hình chữ nhật kia
    return r1_inside_r2 || r2_inside_r1;
}

struct Fruit {
    SDL_Rect rect;
    int dy = 0;
    SDL_Texture* texture;

    Fruit(int x, int y, SDL_Texture* tex) : texture(tex) {
        rect.x = x;
        rect.y = y;
        rect.h = FRUIT_SIZE;
        rect.w = FRUIT_SIZE;

    }

    void draw(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }

    void move() {

        rect.y += FRUIT_SPEED;
        if (rect.y >= SCREEN_HEIGHT) {
            // Đặt lại vị trí của đối tượng ở trên màn hình
            rect.y = -FRUIT_SIZE;
            // Sinh số ngẫu nhiên cho tọa độ x mới
            rect.x = rand() % (SCREEN_WIDTH - FRUIT_SIZE);
        }
    }
    void moveInSineWave() {

    float frequency = 0.03; // Tần số của sóng
    float phaseShift = 10; // Dịch chuyển pha của sóng
    if (Amplitude <= 100 && countFruit  % 10 == 0){
        Amplitude += 5;
    }

    // Tính toán vị trí mới dựa trên hình sin
    rect.x = Amplitude * sin(frequency * rect.y + phaseShift) + verticalShift;
    rect.y += FRUIT_SPEED;

    // Kiểm tra giới hạn cho vật di chuyển
   if (rect.y >= SCREEN_HEIGHT) {
             rect.y = -100;
             verticalShift += rand() % 800;
        }
    if (verticalShift > 800){
        verticalShift = 100;
    }
}
 void run(){
    rect.y = -FRUIT_SIZE;
    SDL_Delay(10);
    rect.x = rand() % 800;

    }
};

struct Basket{
    SDL_Rect rect;
    SDL_Texture* texture;
    Basket(int x, int y, SDL_Texture* tex) : texture(tex){
        rect.x = x;
        rect.y = y;
        rect.h = 66;
        rect.w = 100;
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
void Touch( Graphics graphics, Basket& basket1, Fruit& fruit1, Mix_Chunk *gSelectFruit){
if (basket1.canTouch(fruit1)){
            fruit1.run();
            graphics.play(gSelectFruit);
           countFruit ++;
           if (countFruit % 20 == 0  && countFruit != 0  && FRUIT_SPEED <= 18){
            FRUIT_SPEED += 1 ;
        }
}
}

#endif // GAME_H
