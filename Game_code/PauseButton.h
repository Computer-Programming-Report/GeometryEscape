#ifndef zThis
#define zThis
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "Constant.h"
#include "LTexture.h"
#include "Menu.h"
//here begin
class PauseButton 
{
	public:
	PauseButton();
	bool test = false;
	//Sets top left position
	void setPosition( int x, int y );
		
	//Handles mouse event
	bool handleEvent( SDL_Event* e );	
	
	bool loadMediaPauseButton();
	bool loadMediaPauseButtonYellow();
	
	void render();
	
	SDL_Rect Pause;
	
	bool loadMediaPauseScene(); 
	bool loadMediaPause_Back();
	bool loadMediaPause_BackYellow();
	bool loadMediaPause_Continue();
	bool loadMediaPause_ContinueYellow();
	
	bool PausehandleEvent( SDL_Event* e );
	
	void renderPauseScene();
	void renderback();
	void rendercontinue();
	
	SDL_Rect Pause_scene;
	SDL_Rect PauseBack;
	SDL_Rect PauseContinue;
	protected:
	//Top left position
	SDL_Point mPosition;
};
#endif 
//here end
