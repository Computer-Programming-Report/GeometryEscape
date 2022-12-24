#include "Menu.h"
#include "Game.h"

int main( int argc, char* args[] )
{
	// game not starts yet
	bool gStart = false;
	
	// run the menu
	DemoMenu mRun;
	gStart = mRun.process();
	
	// run the game	
	DemoGame gRun;
	gRun.process(gStart);
		
	return 0;	
}
