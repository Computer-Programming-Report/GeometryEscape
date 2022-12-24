#include "initial_background.h"

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 600;

bool Screen_control::loadMusic() {
    bool success = true;
    gMusic = Mix_LoadMUS( "/Initail_environment-Music/sdl_test1/geometry_escape/music/dark_xfile.mp3" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: \n", Mix_GetError() );
        success = false;
    }
    return success;
}

bool Screen_control::init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) < 0)
    {
        cout << "SDL failed to initialize, SDL_error= " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Geometry Escape",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            cout << "Failed to create Window, SDL_error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            int imgFlags = IMG_INIT_JPG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                cout << "SDL_image could not initialize! SDL_image Error: \n" <<  IMG_GetError();
                success = false;
            }
            else
            {
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            {
                cout << "SDL_mixer could not initialize! SDL_mixer Error: \n" << Mix_GetError() ;
                success = false;
            }
            else
            {
                loadMusic();
            }
        }
    }
    return success;
}

SDL_Surface* Screen_control::loadSurface (std::string path)
{
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        cout << "Unable to load image ! SDL_image Error: \n" << path.c_str() <<  IMG_GetError();
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            cout << "Unable to optimize image ! SDL Error: \n" << path.c_str() << SDL_GetError();
        }
        SDL_FreeSurface( loadedSurface );
    }
        return optimizedSurface;
}

void Screen_control::SetPath()
{
    gBackground = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/menu/background.jpg");
    gTitle = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/menu/picture-font.jpg");
    gButtonboard = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/menu/picture-board.jpg");
}

void Screen_control::SetPosition()
{
    gButtonboard_dstrect.x = 570;
    gButtonboard_dstrect.y = 150;
    gTitle_dstrect.x = 570;
    gTitle_dstrect.y = 0;
}
void Screen_control::main_display()
{
    SDL_BlitSurface( gBackground, NULL, gScreenSurface, NULL );
    SDL_BlitSurface( gTitle, NULL, gScreenSurface, &gTitle_dstrect );
    SDL_BlitSurface( gButtonboard, NULL, gScreenSurface, &gButtonboard_dstrect );
    for(int i=0;i<5;i++)
    {
        SDL_BlitSurface(gButtons[i],NULL,gScreenSurface,&gButtons_dstrect[i]);
    }
}

void Screen_control::close()
{
    for(int i=0;i<5;i++)
    {
        SDL_FreeSurface(gButtons[i]);
        gButtons[i] = NULL;
    }
    SDL_FreeSurface(gTitle);
    gTitle = NULL;
    SDL_FreeSurface(gButtonboard);
    gButtonboard = NULL;
    SDL_FreeSurface(gBackground);
    gBackground = NULL;
    Mix_FreeMusic( gMusic );
    gMusic = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


Set_Buttons::Set_Buttons()
{
    gButtons=new SDL_Surface* [TOTAL_BUTTONS];
    for(int i=0;i<TOTAL_BUTTONS;i++)
    {
        gButtons[i] = NULL;
    }
    colored_gButtons=new SDL_Surface* [TOTAL_BUTTONS];
    for(int i=0;i<TOTAL_BUTTONS;i++)
    {
        colored_gButtons[i] = NULL;
    }
}

void Set_Buttons::SetPosition()
{
    gButtons_dstrect[0].x = 770; gButtons_dstrect[0].y = 350;

    gButtons_dstrect[1].x = 780; gButtons_dstrect[1].y = 240;

    gButtons_dstrect[2].x = 780; gButtons_dstrect[2].y = 170;

    gButtons_dstrect[3].x = 570; gButtons_dstrect[3].y = 350;

    gButtons_dstrect[4].x = 590; gButtons_dstrect[4].y = 175;
}
void Set_Buttons::SetPath()
{
    const char* button_path[5]={"/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-run.jpg",
                           "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-settings.jpg",
                           "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-statistic.jpg",
                           "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-rule.jpg",
                           "/Initail_environment-Music/sdl_test1/geometry_escape/menu/picture-best.jpg"};

    const char* colored_button_path[5]={"/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-run1.jpg",
                                "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-settings.jpg",
                                "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-statistic.jpg",
                                "/Initail_environment-Music/sdl_test1/geometry_escape/menu/button-rule1.jpg",
                                "/Initail_environment-Music/sdl_test1/geometry_escape/menu/picture-best.jpg"};

    for(int i=0;i<5;i++)
    {
        gButtons[i]=loadSurface( button_path[i]);
        colored_gButtons[i]= loadSurface(colored_button_path[i]);
    }
}

void Button_Event::handleEvent( int index,SDL_Event* e )
{
    mCurrentSprite[index] = BUTTON_SPRITE_MOUSE_OUT;
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        int x, y;
        SDL_GetMouseState( &x, &y );
        get_lrPosition(index);
        bool inside = true;

        if( x < lPosition[index].x || x > rPosition[index].x || y < lPosition[index].y || y > rPosition[index].y)
        {
            inside = false;
        }
        if( !inside )
        {
            mCurrentSprite[index] = BUTTON_SPRITE_MOUSE_OUT;
        }
        else
        {
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                    mCurrentSprite[index] = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    mCurrentSprite[index] = BUTTON_SPRITE_MOUSE_DOWN;
                    break;

                case SDL_MOUSEBUTTONUP:
                    mCurrentSprite[index] = BUTTON_SPRITE_MOUSE_UP;
                    break;
            }
        }
    }
}
void Button_Event::get_lrPosition(int index)
{
    int Button_WH[5][2]={{168,119},
                         {128,64},
                         {130,65},
                         {169,119},
                         {162,126}};
    lPosition[index].x = gButtons_dstrect[index].x;
    lPosition[index].y = gButtons_dstrect[index].y;
    rPosition[index].x = lPosition[index].x + Button_WH[index][0];
    rPosition[index].y = lPosition[index].y + Button_WH[index][1];
}
bool Button_Event::react_1(SDL_Event& e)
{
    SDL_Surface* reactSur = NULL;
    SDL_Surface* back = NULL;
    SDL_Surface* on = NULL;
    SDL_Surface* off = NULL;
    SDL_Rect back_dstrect;
    SDL_Rect onoff_dstrect;

    reactSur = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/setting-scene.jpg");
    back = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/back.jpg");
    on = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/on-button.jpg");
    off = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/off-button.jpg");
    back_dstrect.x =800;
    back_dstrect.y =500;
    onoff_dstrect.x =800;
    onoff_dstrect.y =180;

    SDL_BlitSurface( reactSur, NULL, gScreenSurface, NULL );
    SDL_BlitSurface(back,NULL,gScreenSurface,&back_dstrect);
    if(Mix_PausedMusic()) SDL_BlitSurface(off,NULL,gScreenSurface,&onoff_dstrect);
    else  SDL_BlitSurface(on,NULL,gScreenSurface,&onoff_dstrect);

    SDL_UpdateWindowSurface(gWindow);

    bool _quit = false;
    while( _quit == false )
    {
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT ) _quit = true;

            int x, y;
            LButtonSprite CurrentSprite;
            SDL_GetMouseState( &x, &y );
            bool inside1 = true;
            bool inside2 = true;
            if( x < 800 || x > 935)
            {
                inside1 = false;
                inside2 = false;
            }
            if (y < 180 || y > 310)
            {
                inside1 = false;
            }
            if(y < 500 || y > 565)
            {
                inside2 = false;
            }
            if( !inside1 && !inside2)
            {
                CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            }
            else
            {
                switch( e.type )
                {
                    case SDL_MOUSEMOTION:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                        break;
                }
            }

            if(CurrentSprite == BUTTON_SPRITE_MOUSE_DOWN)
            {
                if(inside1)
                {
                    if(Mix_PausedMusic())
                    {
                        Mix_ResumeMusic();
                        SDL_BlitSurface(on,NULL,gScreenSurface,&onoff_dstrect);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                    else
                    {
                        Mix_PauseMusic();
                        SDL_BlitSurface(off,NULL,gScreenSurface,&onoff_dstrect);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                }
                else
                {
                    if(Mix_PausedMusic())
                    {
                        SDL_FreeSurface(off);
                    }
                    else
                    {
                        SDL_FreeSurface(on);
                    }
                    SDL_FreeSurface(back);
                    SDL_FreeSurface(reactSur);
                    main_display();
                    SDL_UpdateWindowSurface(gWindow);
                    return false;
                }
            }
        }
    }
    close();
    return true;

}
bool Button_Event::react_2(SDL_Event& e)
{
    SDL_Surface* reactSur = NULL;
    SDL_Surface* back = NULL;
    SDL_Rect back_dstrect;

    reactSur = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/statistics-scene.jpg");
    back = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/back.jpg");
    back_dstrect.x =780;
    back_dstrect.y =50;
    SDL_BlitSurface( reactSur, NULL, gScreenSurface, NULL );
    SDL_BlitSurface(back,NULL,gScreenSurface,&back_dstrect);
    SDL_UpdateWindowSurface(gWindow);

    bool _quit = false;
    while( _quit == false )
    {
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT ) _quit = true;

            int x, y;
            LButtonSprite CurrentSprite;
            SDL_GetMouseState( &x, &y );
            bool inside = true;

            if( x < 780 || x > 915 || y < 50 || y > 115)
            {
                inside = false;
            }
            if( !inside )
            {
                CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            }
            else
            {
                switch( e.type )
                {
                    case SDL_MOUSEMOTION:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                        break;
                }
            }

            if(CurrentSprite == BUTTON_SPRITE_MOUSE_DOWN)
            {
                SDL_FreeSurface(back);
                back = NULL;
                SDL_FreeSurface(reactSur);
                reactSur = NULL;
                main_display();
                SDL_UpdateWindowSurface(gWindow);
                return false;
            }
        }
    }
    close();
    return true;

}

bool Button_Event::react_3(SDL_Event& e)
{
    SDL_Surface* reactSur = NULL;
    SDL_Surface* back = NULL;
    SDL_Rect back_dstrect;

    reactSur = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/rule-scene.jpg");
    back = loadSurface("/Initail_environment-Music/sdl_test1/geometry_escape/scene/back.jpg");
    back_dstrect.x =800;
    back_dstrect.y =500;
    SDL_BlitSurface( reactSur, NULL, gScreenSurface, NULL );
    SDL_BlitSurface(back,NULL,gScreenSurface,&back_dstrect);
    SDL_UpdateWindowSurface(gWindow);

    bool _quit = false;
    while( _quit == false )
    {
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT ) _quit = true;

            int x, y;
            LButtonSprite CurrentSprite;
            SDL_GetMouseState( &x, &y );
            bool inside = true;

            if( x < 800 || x > 935 || y < 500 || y > 565)
            {
                inside = false;
            }
            if( !inside )
            {
                CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            }
            else
            {
                switch( e.type )
                {
                    case SDL_MOUSEMOTION:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                        break;
                }
            }

            if(CurrentSprite == BUTTON_SPRITE_MOUSE_DOWN)
            {
                SDL_FreeSurface(back);
                back = NULL;
                SDL_FreeSurface(reactSur);
                reactSur = NULL;
                main_display();
                SDL_UpdateWindowSurface(gWindow);
                return false;
            }
        }
    }
    close();
    return true;

}
void demo::process()
{
    init();
    Set_Buttons();
    Screen_control::SetPath();
    Screen_control::SetPosition();
    Set_Buttons::SetPath();
    Set_Buttons::SetPosition();

    Screen_control::main_display();
    Mix_PlayMusic( gMusic, -1 );
    SDL_UpdateWindowSurface(gWindow);
    SDL_Event e;
    bool quit = false;
    while( quit == false )
    {
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT ) quit = true;

            for(int i=0;i<4;i++)
            {
                handleEvent(i,&e);
                if(mCurrentSprite[i] ==BUTTON_SPRITE_MOUSE_OUT)
                {
                    SDL_BlitSurface(gButtons[i],NULL,gScreenSurface,&gButtons_dstrect[i]);
                    SDL_UpdateWindowSurface(gWindow);
                }
                if(mCurrentSprite[i] == BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                    SDL_BlitSurface(colored_gButtons[i],NULL,gScreenSurface,&gButtons_dstrect[i]);
                    SDL_UpdateWindowSurface(gWindow);
                }
                if(mCurrentSprite[i] == BUTTON_SPRITE_MOUSE_DOWN)
                {
                    bool ret = false;
                    switch(i)
                    {
                        case 0:
                            ret= react_0(e);
                            break;
                        case 1:
                            ret= react_1(e);
                            break;
                        case 2:
                            ret= react_2(e);
                            break;
                        case 3:
                            ret= react_3(e);
                            break;
                        default:break;
                    }
                    if(ret) return;
                }
            }
        }
    }
    close();
}





