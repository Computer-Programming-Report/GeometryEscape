#include "Menu.h"
#include "Game.h"

int main( int argc, char* args[] )
{
	
	bool gStart = false; // game not starts yet
	bool mBack = false; // back to menu
	
	DemoMenu mRun; // run the menu
	gStart = mRun.process_menu();
	
	DemoGame gRun; // run the game
	gRun.process_game(gStart);	

		
	return 0;	
}
