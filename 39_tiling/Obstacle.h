#ifndef oThis
#define oThis 
#include "LTexture.h"
// for obstacles' names
enum enObstacle{prof_h, lava, springer, spike}; 
class Obstacle 
{	
	protected:
		bool alive;
		
		// an array to store death times
		int death_times[4];

		// death
		virtual bool death(){}
		 		
	public:
		// default constuctor (main character is alive initially) 
		Obstacle();
		
		// counter of death times for six obstacles
		virtual void add_times(){}
		
		// return death times to statistic 
		virtual int return_times(){}
		
		// 
		virtual void detect(int x, int y){}
		
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
		int scrollingOffset;
		// counter for Prof_H moving
		int pCouter; 
		int pPos_X, pPos_Y;
	public:
		
		Prof_H();
		// convert protected to public in this class	
		using Obstacle::death;
	
		// death
		bool death()
		{ 
			return !alive;
		}
	
		// counter of death times of main character, killed by prof_hsieh 
		void add_times()
		{
			++death_times[prof_h];
		}
		
		// render Prof_H
		void Prof_render(); 
		
		void detect(int x, int y);
};

class Lava : public Obstacle
{
	/*
	todo :
	5. When character touch it, show death scene (alive = false)
	*/
	public:
		// convert protected to public in this class	
		using Obstacle::death;
		
		// death
		bool death()
		{ 
			return !alive;
		}
	
		// counter of death times of main character, killed by lava 
		void add_times()
		{
			++death_times[lava];
		}
		
//		void detect(int x, int y);
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
			
	public:
		// convert protected to public in this class	
		using Obstacle::death;
		
		Springer();
		// death
		bool death()
		{ 
			return !alive;
		}
	
		// counter of death times of main character, killed by springer 
		void add_times()
		{
			++death_times[springer];
		}
		
		// Render Springer
		void Springer_render();
		
		// detect square
//		void detect(int x, int y);
};

class Spike : public Obstacle
{
	/*
	todo :
	1. When character touch it, show death scene (alive = false)
	*/	
	
	public:
		// convert protected to public in this class	
		using Obstacle::death;
	
		// death
		bool death()
		{ 
			return !alive;
		}
	
		// counter of death times of main character, killed by spike 
		void add_times()
		{
			++death_times[spike];
		}
		
//		void detect(int x, int y);
};

#endif
