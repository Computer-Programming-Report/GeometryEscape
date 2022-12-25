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
		bool alive;
		
		// an array to store death times
		int death_times[4];
		 		
	public:
		// default constuctor (main character is alive initially) 
		Obstacle();
		
		// death
		virtual bool sDeath(){return 0;}
		
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
		bool sDeath()
		{ 
			return !alive;
		}
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
		int srPos_X, srPos_Y;
		
		//The Prof_H scrolling offset
		int scrollingOffset;
		// counter for Prof_H moving
		int srCouter; 
		//
		int sX, sY;	
	public:
		// default constuctor
		Springer();
		// death
		bool sDeath()
		{ 
			return !alive;
		}
	
		// Render Springer
		void Springer_render();
};
#endif
