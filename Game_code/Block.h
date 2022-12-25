#ifndef bThis
#define bThis
#include <SDL.h>
#include "LTexture.h" 
#include "Constant.h"
//The block
class Block
{
    public:
		//Initializes position and type
		Block( int x, int y, int blockType );

		//Shows the block
		void render( SDL_Rect& camera );

		//Get the block type
		int getType();

		//Get the collision box
		SDL_Rect getBox();

    private:
		//The attributes of the block
		SDL_Rect mBox;

		//The block type
		int mType;
};



#endif
