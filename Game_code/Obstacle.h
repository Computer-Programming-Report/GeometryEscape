#ifndef oThis
#define oThis 
#include "LTexture.h"
#include "function.h"
#include "SDL.h"
#include "Block.h"
#include "Square.h"
extern bool death;

class Obstacle 
{	
	protected:
		
		// an array to store death times
		int death_times[4];
		 		
	public:
		// default constuctor (main character is alive initially) 
		Obstacle();
		
		// death
		virtual void sDeath(){}
		
		// counter of death times for six obstacles
		virtual void add_times(){}
		
		// return death times to statistic 
		virtual int return_times(){}
		
		// destructor
		~Obstacle(){}
};

class Prof_H : public Obstacle
{
	/*
	todo: 
	3. Detect main character
	4. If so, eject electric ball to the it.
	5. When character touch the thunder, show death scene (alive = false)
	*/ 
	
	private:
		//The Prof_H scrolling offset
		int scrollingOffset, bScrollingOffset;
		
		// counter for Prof_H moving
		int pCouter, bCounter; 
		
		// Prof_H's position
		int pPos_X; 
		int pPos_Y;
		
		// Electric ball position
		int ePos_X;
		int ePos_Y;
		
		// 
		int sX, sY;
	public:
		// default constuctor
		Prof_H();
		// death
		void sDeath(){}
		// render Prof_H
		void Prof_render(); 
		
		// record square's position
		void detect(int *x, int *y);
		
		// atack square
		void attack();
};

class Springer : public Obstacle
{
	/*
	todo: 
	1. When character touch it, show death scene (alive = false)
	*/	
	private:
		//The Prof_H scrolling offset
		int scrollingOffset;
		
		// counter for Prof_H moving
		int srCouter;
		
	public:
		// default constuctor
		Springer();
		
		//The attributes of the springer
		SDL_Rect mBox;
		
		// death
		void sDeath()
		{ 
			death = true;
		}
	
		// Render Springer
		void Springer_render();
		
		//Get the collision box
		SDL_Rect getBox();
};
#endif
