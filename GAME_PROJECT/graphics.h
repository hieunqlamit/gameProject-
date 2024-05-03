#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"
#include <SDL_mixer.h>

using namespace std;
struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

	void init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (TTF_Init() == -1) {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
    }

	void prepareScene(SDL_Texture * background)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    void presentScene()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    void renderTexture(SDL_Texture *texture, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;

        SDL_RenderCopy(renderer, texture, src, &dest);
    }

    void quit()
    {
        TTF_Quit();
        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    void renderClear()
    {
        SDL_RenderClear(renderer);
    }

    TTF_Font* loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
    }

    int getTextWidth(const char* text, TTF_Font* font) {
        if (text == nullptr || font == nullptr) {
            return 0;
        }

        int textWidth = 0;
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, {255, 255, 255});
        if (textSurface != nullptr) {
            textWidth = textSurface->w;
            SDL_FreeSurface(textSurface);
        }
        return textWidth;
    }

    int getTextHeight(const char* text, TTF_Font* font) {
        if (text == nullptr || font == nullptr) {
            return 0;
        }

        int textHeight = 0;
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, {255, 255, 255});
        if (textSurface != nullptr) {
            textHeight = textSurface->h;
            SDL_FreeSurface(textSurface);
        }
        return textHeight;
    }
    void Draw_Font(const char* str, int x, int y, int size, SDL_Color color, const char* path) {
     TTF_Font* font = TTF_OpenFont(path, size);
    int textWidth = getTextWidth(str, font);
    int textHeight = getTextHeight(str, font);
     SDL_Surface* message_surf = TTF_RenderText_Blended(font, str, color);
     SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, message_surf);
     SDL_Rect Message_rect = { x, y, textWidth , textHeight };
     SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
     SDL_DestroyTexture(Message);
     SDL_FreeSurface(message_surf);
     TTF_CloseFont(font);
 }

     Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }

};

#endif // _GRAPHICS__H
