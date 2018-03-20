#ifndef floor_h
#define floor_h
#include "defines.h"
class FLOOR
{
public:
	FLOOR (int rows_, int columns_,const char * dirtyfile , const char * cleanfile,double widht_x, double height_y);
	//LOOR();
	void clean_tile(int row, int column);
	void all_dirt(void);
	bool is_tile_dirty(int row, int column);
	bool is_floor_dirty();//devuelve 1 si esta todo limpio
	void al_draw();//funcion para dibujar, solo falta eso de aca
	unsigned int max_row();
	unsigned int max_column();
private:
	unsigned int columns;
	unsigned int rows;
	double widht_x;
	double height_y;
	bool *tiles;
	ALLEGRO_BITMAP * bitmap_clean;  //bitmaps de piso luimpio y sucio
	ALLEGRO_BITMAP * bitmap_dirty;
};


#endif