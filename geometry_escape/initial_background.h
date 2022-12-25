//
// Created by 魏志宇 on 2022/12/9.
//

#ifndef SDL_TEST1_INITIAL_BACKGROUND_H
#define SDL_TEST1_INITIAL_BACKGROUND_H
#include <SDL2/SDL.h>
#include "/Library/frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include "/Library/frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include "/Library/frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#include <string>
#include <cmath>
#include <iostream>
//#include <fstream>

using namespace std;



class Screen_control {
public:

    Screen_control(){};
    bool init();
    virtual SDL_Surface* loadSurface(std::string);
    virtual void SetPath();
    virtual void SetPosition();
    void close();
    void main_display();
    bool loadMusic();
    bool loadChunk();

protected:
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;

    SDL_Surface* gBackground = NULL;
    SDL_Surface* gTitle = NULL;
    SDL_Rect gTitle_dstrect;
    SDL_Surface* gButtonboard = NULL;
    SDL_Rect gButtonboard_dstrect;

    SDL_Surface** gButtons;
    SDL_Surface** colored_gButtons;
    SDL_Rect gButtons_dstrect[5];

    Mix_Music *gMusic;
    Mix_Chunk *gChunk;
};



class Set_Buttons :public Screen_control
{
public:
    Set_Buttons();
    const string Buttons_menu[5]={"gRun","gSetting","gStatistics","gRule","gBest"};
    const int TOTAL_BUTTONS= 5;
    void SetPosition();
    void SetPath();
};

class Button_Event:public Set_Buttons
{
public:
    enum LButtonSprite
    {
        BUTTON_SPRITE_MOUSE_OUT = 0,
        BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
        BUTTON_SPRITE_MOUSE_DOWN = 2,
        BUTTON_SPRITE_MOUSE_UP = 3,
        BUTTON_SPRITE_TOTAL = 4
    };
    void handleEvent(int index,SDL_Event* e );
    void get_lrPosition(int index);
    void react_0(SDL_Event& e);
    bool react_1(SDL_Event& e);
    bool react_2(SDL_Event& e);
    bool react_3(SDL_Event& e);

protected:
    SDL_Point lPosition[5];
    SDL_Point rPosition[5];
    LButtonSprite mCurrentSprite[5];
};


class demo:public Button_Event
{
public:
    void process();
};

#endif //SDL_TEST1_INITIAL_BACKGROUND_H
