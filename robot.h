#ifndef robot_h
#define robot_h

#include "point.h"
#include "defines.h"

class ROBOT
{
public:
	ROBOT();
	//ROBOT();
	double get_coordx();
	double get_coordy();
	double get_angle();
	double get_unit();
	void set_coordinates(POINT coordinates);
	void set_coordinates(float x, float y);		//hacen lo mismo pero lo hacemos para varios argumentos de entrada, mas comodo
	void new_angle(void);
	void prevent_crash();
	void al_draw(void);
	bool create_bots(const char * botfile,double radius_, double width, double height);
private:
	POINT p;
	double angle;
	double unit;
	POINT oldp;
	ALLEGRO_BITMAP * bitmap;
};


#endif