
#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
int BASKET_SPEED = 20;
int FRUIT_SPEED = 5;
int sizeSmall = 40;
int sizeBig = 50;
int sizeHeader = 80;
SDL_Color colorMenu1 = {255, 255, 255};
SDL_Color colorMenu2 = {0, 0, 0};
const char* WINDOW_TITLE = "FRUITS BASKET";
const int FRUIT_SIZE = 100;
float Amplitude = 40;
float verticalShift = 0;
bool playgPick = false;
static SDL_Event event;
bool showBasket_2 = false;
int currentScore = 0;
bool quit = false;
bool isLosegame = true;
bool isRunning = true;
bool isPause = false;
bool isRestart = false;
bool open2 = true;
bool open3 = true;
bool open1 = true;
bool openPause = true;
bool openWinner = true;
bool turnonMusic = true;
bool openGameover = true;
#endif
