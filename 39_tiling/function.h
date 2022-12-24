#ifndef funcThis
#define funcThis
#include "Block.h"
#include <SDL.h> // SDL.h
#include "LTexture.h" 
#include "Constant.h"
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia( Block* blocks[] );

//Frees media and shuts down SDL
void close( Block* blocks[] );

//Box collision detector
bool checkCollision( SDL_Rect a, SDL_Rect b );

//Checks collision box against set of tiles
bool touchesWall( SDL_Rect box, Block* blocks[] );

//Sets tiles from tile map
bool setBlocks( Block *blocks[] );
#endif
