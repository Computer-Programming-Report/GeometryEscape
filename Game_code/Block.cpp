#include "Block.h"
#include "function.h"

SDL_Rect gBlockClips[ TOTAL_BLOCK_SPRITES ];
extern LTexture gBlockTexture; // get block texture

Block::Block( int x, int y, int blockType )
{
    //Get the offsets
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = BLOCK_WIDTH;
    mBox.h = BLOCK_HEIGHT;

    //Get the block type
    mType = blockType;
}

void Block::render( SDL_Rect& camera )
{
    //If the block is on screen
    if( checkCollision( camera, mBox ) )
    {
        //Show the block
        gBlockTexture.render( mBox.x - camera.x, mBox.y - camera.y, &gBlockClips[ mType ] );
    }
}

int Block::getType()
{
    return mType;
}

SDL_Rect Block::getBox()
{
    return mBox;
}

