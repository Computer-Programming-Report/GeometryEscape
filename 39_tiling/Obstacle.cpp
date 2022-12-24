#include "Obstacle.h"
extern LTexture gProTexture;
extern LTexture gElectricTexture;
extern LTexture gSpringerTexture;
extern int backgroundOffset_x;
extern int backgroundOffset_y;
// initialize
Obstacle::Obstacle()
{
	alive = true;
	for(int i = 0; i < 4; i++)
		death_times[i] = 0;
}

Prof_H::Prof_H()
{
	//The Prof_H scrolling offset
	int scrollingOffset = 0;
	// counter for Prof_H moving
	int pCouter = 0; 
	
}

Springer::Springer()
{
	//The Prof_H scrolling offset
	int scrollingOffset = 0;
	// counter for Prof_H moving
	int srCouter = 0; 
}
	
void Prof_H::detect(int x, int y)
{
	pPos_X = x;
	pPos_Y = y;
	
}
void Prof_H::Prof_render()
{
	// Prof_H move on his own!
	if ( (pCouter / 100) % 8 < 4) 
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
	pCouter+=2;
	gProTexture.render(scrollingOffset + 800 - backgroundOffset_x , -backgroundOffset_y ); // different height 
	gProTexture.render(scrollingOffset + 2500 - backgroundOffset_x , -backgroundOffset_y + 50); // different height
	gProTexture.render(-(scrollingOffset - 2500) - backgroundOffset_x , -backgroundOffset_y + 30); // different height 
	gProTexture.render(scrollingOffset + 4000 - backgroundOffset_x , -backgroundOffset_y + 50); // different height 
	gProTexture.render(-(scrollingOffset - 6000) - backgroundOffset_x , -backgroundOffset_y + 30); // different height 
	gProTexture.render(-(scrollingOffset - 8300) - backgroundOffset_x , -backgroundOffset_y + 80); // different height 
	gProTexture.render(scrollingOffset + 7100 - backgroundOffset_x , -backgroundOffset_y + 15); // different height
}

void Springer::Springer_render()
{
	// Prof_H move on his own!
	if ( (srCouter / 100) % 4 < 2) 
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
	srCouter+=2;
	gSpringerTexture.render(scrollingOffset + 2000 - backgroundOffset_x , -backgroundOffset_y + 300); // different height
	gSpringerTexture.render(scrollingOffset + 4000 - backgroundOffset_x , -backgroundOffset_y + 300); // different height 
	gSpringerTexture.render(-(scrollingOffset - 6000) - backgroundOffset_x , -backgroundOffset_y + 300); // different height 
	gSpringerTexture.render(-(scrollingOffset - 8000) - backgroundOffset_x , -backgroundOffset_y + 250); // different height 
	gSpringerTexture.render(scrollingOffset + 7000 - backgroundOffset_x , -backgroundOffset_y + 300); // different height
}
// How to detect "touch"?
