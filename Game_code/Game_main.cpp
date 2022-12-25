#include "Menu.h"
#include "Game.h"

int main( int argc, char* args[] )
{
	
	bool gStart = false; // game not starts yet
	bool mBack = false; // back to menu
	DemoMenu mRun; // run the menu
	DemoGame gRun; // run the game
//	do
//	{
		gStart = mRun.process_menu();
		gRun.process_game(gStart);	
		
//	}while(mBack);
		
	return 0;	
}
