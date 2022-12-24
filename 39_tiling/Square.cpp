#include "Square.h" // Square.h
extern LTexture gDotTexture; // get Square texture 
extern int backgroundOffset_x;
extern int backgroundOffset_y;
Dot::Dot()
{
    //Initialize the collision box
    mBox.x = 300;
    mBox.y = 360;
	mBox.w = DOT_WIDTH;
	mBox.h = DOT_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
				mVelY -= DOT_VEL_Y; 
				break;
			case SDLK_DOWN: 
				mVelY += DOT_VEL_Y; 
				break;
            case SDLK_LEFT: 
				mVelX -= DOT_VEL_X; 
				break;
            case SDLK_RIGHT: 
				mVelX += DOT_VEL_X; 
				break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL_Y;break;
            case SDLK_DOWN: mVelY -= DOT_VEL_Y; break;
            case SDLK_LEFT: mVelX += DOT_VEL_X; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL_X; break;
        }
    }
}

int posX;
int posY;
void Dot::move( Block *blocks[] )
{
    //Move the dot left or right
    mBox.x += mVelX; 
    posX = mBox.x; 

    //If the dot went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + DOT_WIDTH > LEVEL_WIDTH ) || touchesWall( mBox, blocks ) )
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the dot up or down
    mBox.y += mVelY;
    posY = mBox.y; 
	    
    //If the dot went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + DOT_HEIGHT > LEVEL_HEIGHT ) || touchesWall( mBox, blocks ))
    {   
		mBox.y -= mVelY; 
    }  
}

void Dot::setCamera( SDL_Rect& camera )
{
	//Center the camera over the dot
	camera.x = ( mBox.x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
	camera.y = ( mBox.y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if( camera.x < 0 )
	{ 
		camera.x = 0;
	}
	if( camera.y < 0 )
	{
		camera.y = 0;
	}
	if( camera.x > LEVEL_WIDTH - camera.w )
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if( camera.y > LEVEL_HEIGHT - camera.h )
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}
	backgroundOffset_x = camera.x;
	backgroundOffset_y = camera.y;
}

void Dot::render( SDL_Rect& camera )
{
    //Show the dot
	gDotTexture.render( mBox.x - camera.x, mBox.y - camera.y );
	
}

const int Dot::DOT_WIDTH = 60;
const int Dot::DOT_HEIGHT = 60;

//Maximum axis velocity of the dot
const int Dot::DOT_VEL_X = 10;
const int Dot::DOT_VEL_Y = 10;
