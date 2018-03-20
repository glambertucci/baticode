#ifndef simulation_h
#define simulation_h

#include "robot.h"
#include "floor.h"

class simulation
{
public:
	simulation(unsigned int fil_, unsigned  int col_, const char * dirtyfile, int nbots_, const char * cleanfile, const char * botfile, double width, double height);//constructor
	unsigned int run();		//devuelve los ticks
	void tick();
	void al_draw();	//dibuja en allegro
	void border_fix(); //corrige esquinas
	~simulation();//destructor

private:
	ROBOT * robs;
	unsigned int ticks;
	FLOOR *floor;
	double unit;
	int nbots;
};

#endif