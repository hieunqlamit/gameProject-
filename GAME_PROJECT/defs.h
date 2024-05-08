
#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
int BASKET_SPEED = 20;
int FRUIT_SPEED = 7;
int sizeSmall = 45;
int sizeBig = 55;
int sizeHeader = 80;
SDL_Color colorMenu1 = {21, 52, 72};
SDL_Color colorMenu2 = {196, 12, 12};
const char* WINDOW_TITLE = "FRUIT BASKET";
const int FRUIT_SIZE = 100;
float Amplitude = 40;
float verticalShift = 0;
bool playgPick = false;
bool quitMenu = false;
bool chooseNewgame = false;
static SDL_Event event;
bool showBasket_2 = false;
bool runTime = false;
int currentScore = 100;
bool quit = false;
bool isLosegame = true;
bool isRunning = true;
bool isPause = false;
bool isRestart = false;
bool open2 = true;
bool open3 = true;
bool open1 = true;
bool openPause = true;
bool hieu = true;
#endif
