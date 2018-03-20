#include "robot.h"
#include "defines.h"
#include <stdlib.h>

ROBOT::ROBOT()
{
	new_angle();
}
/*
ROBOT::~ROBOT()
{
		al_destroy_bitmap(bitmap);
}
*/
double ROBOT::get_coordx()
{
	return p.get_x_coord();
}

double ROBOT::get_coordy()
{
	return p.get_y_coord();
}
double
ROBOT::get_angle()
{
	return angle;
} 
double ROBOT::get_unit()
{
	return unit;
}

void ROBOT::set_coordinates(POINT coordinates)
{
	oldp.set_x_coord(p.get_x_coord());
	oldp.set_y_coord(p.get_y_coord());
	p.set_x_coord(coordinates.get_x_coord());
	p.set_y_coord(coordinates.get_y_coord());
}

void ROBOT::set_coordinates(float x, float y)
{
	oldp.set_x_coord(p.get_x_coord());
	oldp.set_y_coord(p.get_y_coord());
	p.set_x_coord(x);
	p.set_y_coord(y);
}

void ROBOT::new_angle(void)
{
	angle = (rand() % 360)*3.14/180;
}
void ROBOT::prevent_crash()//basicamente si despues de updetearlo se paso de los limites lo devuelve a la ultima posiucion y le da un nuevo angulo
{
	p.set_x_coord(oldp.get_x_coord());
	p.set_y_coord(oldp.get_y_coord());

	new_angle();
}
void ROBOT :: al_draw() //dibuja el robot
{
	al_draw_scaled_bitmap(bitmap, 0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), oldp.get_x_coord()-unit/2, oldp.get_y_coord()-unit/2 , unit , unit , 0);
}

bool ROBOT::create_bots(const char * botfile, double unit_, double width, double height) //porque no se llamar constructores de los robots:
{
	bool succes = false;
	//p.set_x_coord((rand()%(int)width-1)+1);
	//p.set_y_coord((rand()%(int)height-1)+1);//como voy a iniciar los robots
	unit = unit_;
	p.set_x_coord(unit + (rand() % (int)(display_width - unit)));
	p.set_y_coord(unit + (rand() % (int)(display_height - unit)));
	if (bitmap = al_load_bitmap(botfile))
	{
		succes = true;
	}
	return succes;
}