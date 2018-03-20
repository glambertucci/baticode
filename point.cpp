#include "point.h"


POINT::~POINT()
{
}

float
POINT::get_x_coord()
{
	return x;
}

float
POINT::get_y_coord()
{
	return y;
}

void
POINT::set_x_coord(float x)
{
	this->x = x;
}

void
POINT::set_y_coord(float y)
{
	this->y = y;
}