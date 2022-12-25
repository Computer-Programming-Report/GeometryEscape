#include "Square.h" // Square.h
extern LTexture gSquareTexture; // get Square texture 
extern int backgroundOffset_x;
extern int backgroundOffset_y;
int *sPos_X = NULL;
int *sPos_Y = NULL;
extern bool death;
Springer *boom;

Square::Square() : isjump(false)
{
    //Initialize the collision box
    mBox.x = 300;
    mBox.y = 300;
	mBox.w = SQUARE_WIDTH;
	mBox.h = SQUARE_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Square::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: 
				mVelX -= SQUARE_VEL_X; 
				break;
            case SDLK_RIGHT: 
				mVelX += SQUARE_VEL_X; 
				break;
        }
        if(e.key.keysym.sym == SDLK_SPACE && !isjump)
        {
        	mVelY -= SQUARE_VEL_Y; 
			isjump = true ;
		}
		else
		{
			mVelY -= gravity;
		}
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX += SQUARE_VEL_X; break;
            case SDLK_RIGHT: mVelX -= SQUARE_VEL_X; break;
        }
    }
}

void Square::move( Block *blocks[] )
{
    //Move the square left or right
    if(mVelX < 0)
    {
    	loadMediaLeft();
	}
	else if(mVelX > 0)
	{
		loadMediaRight();
	}
    mBox.x += mVelX; 

    //If the square went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + SQUARE_WIDTH > LEVEL_WIDTH ) || touchesWall( Square::mBox, blocks ) )
    {
        //move back
        loadMediaTouchWall();
        mBox.x -= mVelX;
    }

    //Move the square up or down
    mVelY += gravity;
    mBox.y += mVelY;
    
    //If the square went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + SQUARE_HEIGHT > LEVEL_HEIGHT ) || touchesWall( Square::mBox, blocks ))
    {   
		mBox.y -= mVelY; 
		mVelY = 0 ;
        isjump = false;
    } 
    
//    if(checkCollision( Square::mBox, boom->mBox ) )
//    {
//    	boom->sDeath();
//	}
    
    sPos_X = &mBox.x;
	sPos_Y = &mBox.y;
}

void Square::setCamera( SDL_Rect& camera )
{
	//Center the camera over the square
	camera.x = ( mBox.x + SQUARE_WIDTH / 2 ) - SCREEN_WIDTH / 2;
	camera.y = ( mBox.y + SQUARE_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

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

void Square::render( SDL_Rect& camera )
{
    //Show the square
	gSquareTexture.render( mBox.x - camera.x, mBox.y - camera.y );
	
}
