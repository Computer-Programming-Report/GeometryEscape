#ifndef sThis
#define sThis
#include <SDL.h> // SDL.h
#include "LTexture.h"  // LTexture
#include "Constant.h" // Constant.h
#include "function.h" // function.h
#include "Block.h" // Block.h
#include "Obstacle.h"
//The square that will move around on the screen
class Square
{
//	friend class Obstacle;
    public:
		//The dimensions of the square
		static const int SQUARE_WIDTH = 60;
		static const int SQUARE_HEIGHT = 60;

		//Maximum axis velocity of the square
		static const int SQUARE_VEL_X = 15;
		static const int SQUARE_VEL_Y = 45;
		
		//Initializes the variables
		Square();

		//Takes key presses and adjusts the square's velocity
		void handleEvent( SDL_Event& e );

		//Moves the square and check collision against blocks
		void move( Block *blocks[] );

		//Centers the camera over the square
		void setCamera( SDL_Rect& camera );

		//Shows the square on the screen
		void render( SDL_Rect& camera );
		
		// 是否在空中 
		bool isjump;

    private:
		//Collision box of the square
		SDL_Rect mBox;
		
		//The velocity of the square
		int mVelX; 
		int mVelY;	
};
#endif
