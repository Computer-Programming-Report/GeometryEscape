#include "Game.h"
extern SDL_Renderer* gRenderer;
extern LTexture gProTexture; // get Prof_H texture 
extern LTexture gSpingerTexture;
int backgroundOffset_x = 0;
int backgroundOffset_y = 0;

void DemoGame::process(bool start)
{
	Obstacle mCharacter;
	Prof_H p; 
	Lava l;
	Springer sr;
	Spike sk;
	Obstacle *dType[] = {&p, &l, &sr, &sk}; // death type pointer
	enObstacle type = prof_h; // enum 
	
	// invoke func. death(), let main character to be not alive (death)	
//	if (dType[type]->death.()) 
//	{
//		/* 
//		todo:
//		1. Scene stop instantly, load death scene(cliche must be included!)
//		2. the scene cotain a button(back to menu)
//		*/ 
//		// invoke func. add_times(), let (death types)++
//		dType[type]->add_times();
//	}

	//The level blocks
	Block* blockSet[ TOTAL_BLOCKS ];
	
	//Load media
	if( !loadMedia( blockSet ) )
	{
		printf( "Failed to load media!\n" );
	}
	else
	{	
		//Main loop flag
		bool quit = false;
		
		//Event handler
		SDL_Event e2;
		//The dot that will be moving around on the screen
		Dot dot;
		
		//Level camera
		SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; // here
		
		//While application is running
		while((start) && (!quit))
		{
			
			//Handle events on queue
			while( SDL_PollEvent( &e2 ) != 0 )
			{
				//User requests quit
				if( e2.type == SDL_QUIT )
				{
					quit = true;
				}
				
				//Handle input for the dot
				dot.handleEvent( e2 );
			}
						
			//Move the dot
			dot.move( blockSet );
			dot.setCamera( camera );
			
			//Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( gRenderer );
			
			
			// Render Prof_H
			Prof_H pShow;
			pShow.Prof_render();
			
			 
			//Render level
			for( int i = 0; i < TOTAL_BLOCKS; ++i )
			{
				blockSet[ i ]->render( camera );
			}
			
			// Render Square
			dot.render( camera );

			// Render Spinger
			Springer srShow;
			srShow.Springer_render();
			
			//Update screen
			SDL_RenderPresent( gRenderer );			
		}
	}
	//Free resources and close SDL
	close( blockSet );
}
