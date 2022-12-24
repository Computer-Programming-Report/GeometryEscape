#ifndef sThis
#define sThis
#include <SDL.h> // SDL.h
#include "LTexture.h"  // LTexture
#include "Constant.h" // Constant.h
#include "function.h" // function.h
#include "Block.h" // Block.h
//The dot that will move around on the screen
class Dot
{
//	friend class AnswerSheet;
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH;
		static const int DOT_HEIGHT;

		//Maximum axis velocity of the dot
		static const int DOT_VEL_X;
		static const int DOT_VEL_Y;
		
		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and check collision against blocks
		void move( Block *blocks[] );

		//Centers the camera over the dot
		void setCamera( SDL_Rect& camera );

		//Shows the dot on the screen
		void render( SDL_Rect& camera );
		
		// 是否在空中 
		bool isjump;

    private:
		//Collision box of the dot
		SDL_Rect mBox;
		
		//The velocity of the dot
		int mVelX; 
		int mVelY;
		
	
		
};
#endif
