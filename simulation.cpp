#include "simulation.h"
#include <stdio.h>
#include <math.h>
simulation::simulation(unsigned int fil_, unsigned  int col_, const char * dirtyfile, int nbots_, const char * cleanfile, const char * botfile, double width, double height)
{
	double widht_x = width / col_;
	double height_y = height / fil_;
	unit = height_y > widht_x ? widht_x : height_y;
	robs = new ROBOT[nbots_];
	floor = new FLOOR(fil_, col_, dirtyfile, cleanfile, widht_x, height_y);
	ticks = 0;
	for (int i = 0; i < nbots_; i++)
	{
		if (!(robs[i].create_bots(botfile, unit, widht_x, height_y)))
		{
			printf("couldnt craete bots");
		}
	}
	nbots = nbots_;
}

simulation:: ~simulation()
{
	delete[] robs;
	delete[] floor;
}

unsigned int simulation::run()
{
	floor->all_dirt();//funca bien
	while (floor->is_floor_dirty()==SUCIO)
	{
		tick();
		ticks++;
		al_draw();

	}
	return ticks;
}
void simulation::tick()
{
	for (int i = 0; i < nbots; i++)
	{
		floor->clean_tile((int)((robs[i].get_coordx())/unit),(int) ((robs[i].get_coordy())/unit));
	//	printf("x vale %d, y vale %d\n", (int)((robs[i].get_coordy()) / unit), (int)((robs[i].get_coordy()) / unit));
		robs[i].set_coordinates((robs[i].get_coordx()) +cos(robs[i].get_angle()) * unit, (robs[i].get_coordy()) + sin(robs[i].get_angle()) * unit);
	}
	border_fix();
}

void simulation::al_draw()
{
	floor->al_draw();
	for (int i = 0; i < nbots; i++)
	{
		robs->al_draw();
	}

	al_flip_display();
	al_rest(0.1);
}

void simulation::border_fix()
{
	double low_border_x = 0;
	double low_border_y = 0;
	double high_border_x = (floor->max_column()* unit);
	double high_border_y = (floor->max_row()* unit);

	for (int i = 0; i < nbots; i++)
	{
		if ((robs[i].get_coordx() > high_border_x) || robs[i].get_coordx() < low_border_x)
		{
			robs->prevent_crash();
		}
		else if (((robs[i].get_coordy()) > high_border_y) || ((robs[i].get_coordy()) < low_border_y))
		{
			robs->prevent_crash();
		}
	}
}