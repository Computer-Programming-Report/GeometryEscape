#include "function.h" 

extern SDL_Rect gBlockClips[ TOTAL_BLOCK_SPRITES ];
//The window we'll be rendering to
extern SDL_Window* gWindow;
//The window renderer
extern SDL_Renderer* gRenderer;

extern LTexture gSquareTexture; // get Square texture 
extern LTexture gBlockTexture; // get block texture
extern LTexture gProTexture; // get Prof_H texture 
extern LTexture gSpringerTexture; // get AnswerSheet texture
extern LTexture gPauseTexture;//pause button
extern LTexture gPauseSceneTexture;
extern LTexture gBackTexture;
extern LTexture gContinueTexture;
extern LTexture gFireTexture;

bool death = false;

bool setBlocks( Block* blocks[] )
{
	//Success flag
	bool blocksLoaded = true;

    //The block offsets
    int x = 0, y = 0;

    //Open the map
    std::ifstream map( "Game_code/block.map" );

    //If the map couldn't be loaded
    if( map.fail() )
    {
		printf( "Unable to load map file!\n" );
		blocksLoaded = false;
    }
	else
	{
		//Initialize the blocks
		for( int i = 0; i < TOTAL_BLOCKS; ++i )
		{
			//Determines what kind of block will be made
			int blockType = -1;

			//Read block from map file
			map >> blockType;

			//If the was a problem in reading the map
			if( map.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				blocksLoaded = false;
				break;
			}

			//If the number is a valid block number
			if( ( blockType >= 0 ) && ( blockType < TOTAL_BLOCK_SPRITES ) )
			{
				blocks[ i ] = new Block( x, y, blockType );
			}
			//If we don't recognize the block type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid block type at %d!\n", i );
				blocksLoaded = false;
				break;
			}

			//Move to next block spot
			x += BLOCK_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += BLOCK_HEIGHT;
			}
		}
		
		//Clip the sprite sheet
		if( blocksLoaded )
		{	
			// black block
			gBlockClips[ BLOCK_BLACK ].x = 0;
			gBlockClips[ BLOCK_BLACK ].y = 0;
			gBlockClips[ BLOCK_BLACK ].w = BLOCK_WIDTH;
			gBlockClips[ BLOCK_BLACK ].h = BLOCK_HEIGHT;
			
			// white block
			gBlockClips[ BLOCK_WHITE ].x = 0;
			gBlockClips[ BLOCK_WHITE ].y = 60;
			gBlockClips[ BLOCK_WHITE ].w = BLOCK_WIDTH;
			gBlockClips[ BLOCK_WHITE ].h = BLOCK_HEIGHT;
			
			// spike
			gBlockClips[ BLOCK_SPIKE ].x = 0;
			gBlockClips[ BLOCK_SPIKE ].y = 120;
			gBlockClips[ BLOCK_SPIKE ].w = BLOCK_WIDTH;
			gBlockClips[ BLOCK_SPIKE ].h = BLOCK_HEIGHT;
			
			// lava
			gBlockClips[ BLOCK_LAVA ].x = 0;
			gBlockClips[ BLOCK_LAVA ].y = 240;
			gBlockClips[ BLOCK_LAVA ].w = BLOCK_WIDTH;
			gBlockClips[ BLOCK_LAVA ].h = BLOCK_HEIGHT;
			
			// flag
			gBlockClips[ BLOCK_FLAG ].x = 0;
			gBlockClips[ BLOCK_FLAG ].y = 420;
			gBlockClips[ BLOCK_FLAG ].w = BLOCK_WIDTH;
			gBlockClips[ BLOCK_FLAG ].h = BLOCK_HEIGHT;
			
		}
	}

    //Close the file
    map.close();

    //If the map was loaded fine
    return blocksLoaded;
}


bool touchesWall( SDL_Rect box, Block* blocks[] )
{
    //Go through the blocks
    for( int i = 0; i < TOTAL_BLOCKS; ++i )
    {
        //If the block is a wall type block
        if( blocks[ i ]->getType() >= BLOCK_BLACK )
        {
            //If the collision box touches the wall block
            if( checkCollision( box, blocks[ i ]->getBox() ) )
            {
                return true;
            }
        }
        else if ( ( blocks[ i ]->getType() == BLOCK_SPIKE ) ) // touch the spike and death 
    	{
            //If the collision box touches the spike block
            if( checkCollision( box, blocks[ i ]->getBox() ) )
            {
            	death = true;
                return death;
            }
        }
        else if ( ( blocks[ i ]->getType() == BLOCK_LAVA ) ) // touch the lava and death
    	{
            //If the collision box touches the lava block 
            if( checkCollision( box, blocks[ i ]->getBox() ) )
            {
            	death = true;
                return death;
            }
        }
	}

    //If no wall blocks were touched
    return false;
}


bool loadMedia( Block* blocks[] )
{
	//Loading success flag
	bool success = true;

	//Load square texture
	if( !gSquareTexture.loadFromFile( "Game_code/picture/square-1.jpg" ) )
	{
		printf( "Failed to load square texture!\n" );
		success = false;
	}

	//Load block texture
	if( !gBlockTexture.loadFromFile( "Game_code/picture/block_spike_lava.png" ) )
	{
		printf( "Failed to load block set texture!\n" );
		success = false;
	}

	//Load block map
	if( !setBlocks( blocks ) )
	{
		printf( "Failed to load block set!\n" );
		success = false;
	}
	
	//Load Prof_H
	if( !gProTexture.loadFromFile( "Game_code/picture/Prof_H.png" ) )
	{
		printf( "Failed to load block set texture!\n" );
		success = false;
	}
	
	//Load Springer
	if( !gSpringerTexture.loadFromFile( "Game_code/picture/springer.png" ) )
	{
		printf( "Failed to load springer set texture!\n" );
		success = false;
	}
	
	if( !gFireTexture.loadFromFile( "Game_code/picture/fire_ball.png" ) )
	{
		printf( "Failed to load fireball set texture!\n" );
		success = false;
	}
	
	if(!gFireTexture.loadFromFile( "Game_code/picture/fire_ball.png" ))
	{
		printf( "Failed to load end set texture!\n" );
		success = false;
	}
	
	return success;
}

bool loadMediaRight()
{
	//Loading success flag
	bool success = true;

	//Load square texture
	if(!gSquareTexture.loadFromFile( "Game_code/picture/square-1.jpg" ) )
	{
		printf( "Failed to load square texture!\n" );
		success = false;
	}

	return success;
}

bool loadMediaLeft()
{
	//Loading success flag
	bool success = true;

	//Load square texture
	if(!gSquareTexture.loadFromFile( "Game_code/picture/square-2.jpg" ) )
	{
		printf( "Failed to load square texture!\n" );
		success = false;
	}

	return success;
}

bool loadMediaTouchWall()
{
	//Loading success flag
	bool success = true;

	//Load square texture
	if(!gSquareTexture.loadFromFile( "Game_code/picture/square-3.jpg" ) )
	{
		printf( "Failed to load square texture!\n" );
		success = false;
	}

	return success;
}

void close( Block* blocks[] )
{
	//Deallocate blocks
	for( int i = 0; i < TOTAL_BLOCKS; ++i )
	{
		 if( blocks[ i ] != NULL )
		 {
			delete blocks[ i ];
			blocks[ i ] = NULL;
		 }
	}

	//Free loaded images
	gSquareTexture.free();
	gBlockTexture.free();
	gProTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
