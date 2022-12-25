#include "PauseButton.h"

//here begin

extern LTexture gPauseTexture;//pause button
extern LTexture gPauseSceneTexture;
//extern LTexture gBackTexture;
extern LTexture gContinueTexture;
extern LTexture gRenderer;
extern LTexture	gSquareTexture;
extern LTexture gBlockTexture;
extern LTexture	gProTexture;

PauseButton::PauseButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
	
//	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void PauseButton::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

bool PauseButton::handleEvent( SDL_Event* e )
{
	//bool keydown = false;
	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < 800)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > 800 + 100 )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < 30 )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > 30 + 50 )
		{
			inside = false;
		}
	

		//Mouse is outside button
		if( !inside )
		{
		
			loadMediaPauseButton();
			render();
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
	
				loadMediaPauseButtonYellow();
				render();
				break;
			
				case SDL_MOUSEBUTTONDOWN:
			
				return true;
				break;
				
			}
		}
	}
	return false;
}

bool PauseButton::PausehandleEvent(SDL_Event* e)
{

	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
	//	bool binside = true;
		bool cinside = true;

		//determine whether in back button
		//Mouse is left of the button
		/*if( x < 262)
		{
			binside = false;
		}
		//Mouse is right of the button
		else if( x > 262 + 130 )
		{
			binside = false;
		}
		//Mouse above the button
		else if( y < 330 )
		{
			binside = false;
		}
		//Mouse below the button
		else if( y > 330 + 65 )
		{
			binside = false;
		}*/
		
		//determine whether in continue button
		if( x < 417 )
		{
			cinside = false;
		}
		//Mouse is right of the button
		else if( x > 417 + 130 )
		{
			cinside = false;
		}
		//Mouse above the button
		else if( y < 330 )
		{
			cinside = false;
		}
		//Mouse below the button
		else if( y > 330 + 65 )
		{
			cinside = false;
		}

		//Mouse is outside button
		if( !cinside && test)
		{
		//	loadMediaPause_Back();
			loadMediaPause_Continue();
			
			return true;
		}
		//Mouse is inside button
		/*else if(binside && !cinside && test)
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
			
				loadMediaPause_BackYellow();
				break;
				
				case SDL_MOUSEBUTTONDOWN:
				gPauseTexture.free();
				gPauseSceneTexture.free();
				gBackTexture.free();
				gContinueTexture.free();
				gSquareTexture.free();
				gBlockTexture.free();
				gProTexture.free();
				
				extern main_display();
				//back to home
				break;
	
			}
		}*/
		else if( cinside && test)
		{
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
			
				loadMediaPause_ContinueYellow();
			
				break;
			
				case SDL_MOUSEBUTTONDOWN:
				gPauseTexture.free();
				gPauseSceneTexture.free();
				//gBackTexture.free();
				gContinueTexture.free();
				test = false;
				//Continue
				break;
		
			}
		}
	}
	return false;
}
//here end
//here begin
bool PauseButton::loadMediaPauseButton()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gPauseTexture.loadFromFile( "Game_src/scene/pause.png" ) )
	{
		printf( "Failed to load pause texture!\n" );
		success = false;
	}
	else
	{
		Pause.x =   0;
		Pause.y =   0;
		Pause.w = 130;
		Pause.h =  65;
	}

	return success;
}

bool PauseButton::loadMediaPauseButtonYellow()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gPauseTexture.loadFromFile( "Game_src/scene/pause2.png" ) )
	{
		printf( "Failed to load pause2 texture!\n" );
		success = false;
	}
	else
	{
		Pause.x =   0;
		Pause.y =   0;
		Pause.w = 130;
		Pause.h =  65;
	}

	return success;
}

bool PauseButton::loadMediaPauseScene()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gPauseSceneTexture.loadFromFile( "Game_src/scene/PauseScene.jpg" ) )
	{
		printf( "Failed to load pausescene texture!\n" );
		success = false;
	}
	else
	{
		Pause_scene.x =   0;
		Pause_scene.y =   0;
		Pause_scene.w = 960;
		Pause_scene.h = 600;
	}

	return success;
}

/*bool PauseButton::loadMediaPause_Back()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gBackTexture.loadFromFile( "Game_src/scene/back.jpg" ) )
	{
		printf( "Failed to load pause2 texture!\n" );
		success = false;
	}
	else
	{
		PauseBack.x =   0;
		PauseBack.y =   0;
		PauseBack.w = 130;
		PauseBack.h =  65;
	}

	return success;
}

bool PauseButton::loadMediaPause_BackYellow()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gBackTexture.loadFromFile( "Game_src/scene/back1.jpg" ) )
	{
		printf( "Failed to load pause2 texture!\n" );
		success = false;
	}
	else
	{
		PauseBack.x =   0;
		PauseBack.y =   0;
		PauseBack.w = 130;
		PauseBack.h =  65;
	}

	return success;
}*/

bool PauseButton::loadMediaPause_Continue()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gContinueTexture.loadFromFile( "Game_src/scene/continue.png" ) )
	{
		printf( "Failed to load pause2 texture!\n" );
		success = false;
	}
	else
	{
		PauseContinue.x =   0;
		PauseContinue.y =   0;
		PauseContinue.w = 130;
		PauseContinue.h =  65;
	}

	return success;
}

bool PauseButton::loadMediaPause_ContinueYellow()
{
		//Loading success flag
	bool success = true;

	//Load dot texture
	if(!gContinueTexture.loadFromFile( "Game_src/scene/continue2.png" ) )
	{
		printf( "Failed to load pause2 texture!\n" );
		success = false;
	}
	else
	{
		PauseContinue.x =   0;
		PauseContinue.y =   0;
		PauseContinue.w = 130;
		PauseContinue.h =  65;
	}

	return success;
}
bool PauseButton::loadMediaDeathScene()
{
		//Loading success flag
	bool success = true;

	//Load square texture
	if(!gSquareTexture.loadFromFile( "Game_src/scene/DeathScene.jpg" ) )
	{
		printf( "Failed to load square texture!\n" );
		success = false;
	}
	else
	{
		Death.x = 0;
		Death.y = 0;
		Death.w = 960;
		Death.h = 600;
	}

	return success;
}
	
void PauseButton::render()
{
	//Show Pause Button
	gPauseTexture.render(800, 30, &Pause);
}

void PauseButton::renderPauseScene()
{
	gPauseSceneTexture.render(0, 0, &Pause_scene);
}

/*void PauseButton::renderback()
{
	gBackTexture.render(262, 330, &PauseBack);
}*/

void PauseButton::rendercontinue()
{
	gContinueTexture.render(417, 330, &PauseContinue);
}
//here end

