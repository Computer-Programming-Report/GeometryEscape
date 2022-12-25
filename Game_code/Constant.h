#ifndef cThis
#define cThis 
//Screen dimension constants // camera
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 600;

//The dimensions of the level // all map
const int LEVEL_WIDTH = 960*12; // 960*12/60 = 16*12 = 192
const int LEVEL_HEIGHT = 600; // 600/60 = 10

//Tile constants
const int BLOCK_WIDTH = 60;
const int BLOCK_HEIGHT = 60; 
const int TOTAL_BLOCKS = 1920; // 192 * 10 = 1920
const int TOTAL_BLOCK_SPRITES = 12;



//The different tile sprites
const int BLOCK_WHITE = 0; // air
const int BLOCK_BLACK = 11; // block
const int BLOCK_SPIKE = 01; // type 1 death
const int BLOCK_LAVA = 02; // type 2 death
const int BLOCK_FLAG = 03;

//grvity
const int gravity = 4;

#endif
