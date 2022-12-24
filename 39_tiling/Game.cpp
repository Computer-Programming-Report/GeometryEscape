#include "Game.h"
extern SDL_Renderer* gRenderer;
extern LTexture gProTexture; // get Prof_H texture 
extern LTexture gAnswerTexture;
int backgroundOffset_x = 0;
int backgroundOffset_y = 0;

void DemoGame::process(bool start)
{
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
		
		//The Prof_H scrolling offset
		int scrollingOffset = 0;
		// counter for Prof_H moving
		int c = 0; 
		
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
			
			// Prof_H move on his own!
			if ( (c / 100) % 8 < 4) 
			{
				scrollingOffset += 2;
				if( scrollingOffset > 800)
					scrollingOffset = 0;	
			}
			else
			{
				scrollingOffset -= 2;
				if( scrollingOffset < -800 )
					scrollingOffset = 0;
			}
			c+=2;
			
			//Move the dot
			dot.move( blockSet );
			dot.setCamera( camera );
			
			//Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( gRenderer );
			
			// Render Prof_H
			gProTexture.render(scrollingOffset + 800 - backgroundOffset_x , -backgroundOffset_y ); // different height 
			gProTexture.render(scrollingOffset + 2500 - backgroundOffset_x , -backgroundOffset_y + 50); // different height
			gProTexture.render(-(scrollingOffset - 2500) - backgroundOffset_x , -backgroundOffset_y + 30); // different height 
			gProTexture.render(scrollingOffset + 4000 - backgroundOffset_x , -backgroundOffset_y + 50); // different height 
			gProTexture.render(-(scrollingOffset - 6000) - backgroundOffset_x , -backgroundOffset_y + 30); // different height 
			gProTexture.render(-(scrollingOffset - 8300) - backgroundOffset_x , -backgroundOffset_y + 80); // different height 
			gProTexture.render(scrollingOffset + 7100 - backgroundOffset_x , -backgroundOffset_y + 15); // different height
			
			//Render level
			for( int i = 0; i < TOTAL_BLOCKS; ++i )
			{
				blockSet[ i ]->render( camera );
			}
			
			// Render Square
			dot.render( camera );

//			AnswerSheet ans;
//			ans.detect();
			
			//Update screen
			SDL_RenderPresent( gRenderer );			
		}
	}
	//Free resources and close SDL
	close( blockSet );
}
