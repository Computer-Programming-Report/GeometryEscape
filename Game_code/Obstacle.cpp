#include "Obstacle.h"
extern LTexture gProTexture;
extern LTexture gFireTexture;
extern LTexture gSpringerTexture;

extern int backgroundOffset_x;
extern int backgroundOffset_y;

// Square's position
extern int *sPos_X;
extern int *sPos_Y;

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
	
	// initialize Springer's position
	int srPos_X = 0;
	int srPos_Y = 0;
}

// record Square' position
void Prof_H::detect(int *x, int *y)
{
	sX = *x - backgroundOffset_x;
	sY = *y ; 
}

// attack square
void Prof_H::attack()
{
//	int pCounter = 0;
//	while ((sX >= pPos_X + 60) && (sX <= pPos_X + 360))
//	{
//		
//		if ( (bCounter / 100) % 4 < 2) 
//		{
//			bScrollingOffset += 2;
//			if( bScrollingOffset > 800)
//				bScrollingOffset = 0;	
//		}
//		bCounter+=4;
//		gFireTexture.render(sX - backgroundOffset_x, pPos_Y + bScrollingOffset);
//	}
//	pCounter = 0;
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
	
	pPos_X = scrollingOffset + 800 - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y;
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = scrollingOffset + 2500 - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 50; 
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = -(scrollingOffset - 2500) - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 30;
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = scrollingOffset + 4000 - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 50; 
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = -(scrollingOffset - 6000) - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 30; 
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = -(scrollingOffset - 8300) - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 80; 
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
	
	pPos_X = scrollingOffset + 9000 - backgroundOffset_x;
	pPos_Y = -backgroundOffset_y + 15; 
	gProTexture.render(pPos_X , pPos_Y);
	detect(sPos_X , sPos_Y);
	attack();
}

// render Springer
void Springer::Springer_render()
{
	// Springer move on his own!
	if ( (srCouter / 100) % 4 < 2)  
	{
		scrollingOffset += 3;
		if( scrollingOffset > 800)
		scrollingOffset = 0;	
	}
	else
	{
		scrollingOffset -= 3;
		if( scrollingOffset < -800 )
			scrollingOffset = 0;
	}
	srCouter+=4;
	
	srPos_X = 2240 - backgroundOffset_x;
	srPos_Y = scrollingOffset - backgroundOffset_y; 
	gSpringerTexture.render(srPos_X , srPos_Y + 200);
	
	srPos_X = 3600 - backgroundOffset_x;
	srPos_Y = scrollingOffset - backgroundOffset_y; 
	gSpringerTexture.render(srPos_X , srPos_Y + 100);
	
	srPos_X = 4000 - backgroundOffset_x;
	srPos_Y = scrollingOffset - backgroundOffset_y; 
	gSpringerTexture.render(srPos_X , srPos_Y + 200);
	
	srPos_X = 5400 - backgroundOffset_x;
	srPos_Y = scrollingOffset - backgroundOffset_y; 
	gSpringerTexture.render(srPos_X , srPos_Y + 200);
	
	srPos_X = 6180 - backgroundOffset_x;
	srPos_Y = scrollingOffset - backgroundOffset_y; 
	gSpringerTexture.render(srPos_X , srPos_Y + 200); 
}
// How to detect "touch"?
