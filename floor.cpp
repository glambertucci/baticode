#include "floor.h"
#include "defines.h"

FLOOR::FLOOR(int rows_, int columns_, const char * dirtyfile, const char * cleanfile,double widht_x_,double height_y_)			//inicializamos todas las baldosas como sucias
{
	widht_x = widht_x_;
	height_y = height_y_;
	rows = rows_;
	columns = columns_;
	tiles =(bool *) malloc (rows_ * columns_*sizeof(bool));

	bitmap_dirty = al_load_bitmap(dirtyfile);
	bitmap_clean = al_load_bitmap(cleanfile);
}
/*
FLOOR::~FLOOR()
{ 
	
	free(tiles);
	al_destroy_bitmap(bitmap_dirty);
	al_destroy_bitmap(bitmap_clean);
	
}*/

void FLOOR::all_dirt()
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			tiles[i * max_column() + j] = SUCIO;

		}
	}
}
void FLOOR::clean_tile(int rows, int columns)
{
	tiles[columns * max_column() + rows] = LIMPIO;			//el estado de la columna es ahora limpia
}

bool FLOOR::is_tile_dirty(int row, int column)
{
	return (tiles[row * max_column() + column] == SUCIO);
}

bool FLOOR::is_floor_dirty()	//ve si hay alguna balsoda sucia, si esta sucio -> 1, todo limpio -> 0
{
	int dirty = 1;
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			if (tiles[i * max_column() + j] == SUCIO)
			{// ¿esta sucia esta baldosa?
				dirty = SUCIO;
				return dirty;
			}
		}
	}
	return dirty;				
}

unsigned int FLOOR::max_row()
{
	return rows;
}

unsigned int FLOOR::max_column()
{
	return columns;
}

void FLOOR::al_draw()
{
	double real_width = al_get_bitmap_width(bitmap_clean);
	double real_height = al_get_bitmap_height(bitmap_clean);
	static int onlyonce= 0;
	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int a = 0; a < columns; ++a)
		{
			if (tiles[i * max_column() + a]==LIMPIO)
				al_draw_scaled_bitmap(bitmap_clean, 0, 0, real_width, real_height, a * widht_x, i * height_y, widht_x, height_y, 0);
			else 
				al_draw_scaled_bitmap(bitmap_dirty, 0, 0, real_width, real_height, a * widht_x, i * height_y, widht_x, height_y, 0);
			al_flip_display();
		}
	}
}