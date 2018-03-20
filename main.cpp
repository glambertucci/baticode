#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "simulation.h"
#include "parsecmd.h"
#include "defines.h"
#include "parse_callback.h"
#include "allegro_start_shutdown.h"
#define DIRTYFILE "dirtyfile.png"
#define CLEANFILE "cleanfile.png"
#define BOTFILE "botfile.png"

typedef struct
{
	unsigned int fil;
	unsigned int col;
	unsigned int bots_num;
	unsigned int mode;

}userData;

using namespace std;
int main(int argc, char **argv)
{
	userData * userinfo=NULL;
	userData user;
	userinfo = &user;// ok, me tiraba problemas y al parecer esto lo arreglo
	userinfo->col = 10;
	userinfo->fil = 10;
	userinfo->bots_num = 2;
	userinfo->mode = 1;

	ALLEGRO_DISPLAY * display;
	pCallback pfun = input_check;
	if (parseCmdLine(argc, argv,pfun,(void *) userinfo))
	{
		if(allegro_startup())
		{
			if ((display = al_create_display(display_width, display_height))!= NULL)
			{
				srand(time(NULL));
				//hacer main
				int ticks;
				if (userinfo->mode == 1)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					simulation s(userinfo->fil,userinfo->col,DIRTYFILE,userinfo->bots_num,CLEANFILE,BOTFILE,display_width,display_height);
						ticks = s.run();//falta definir las clases

						
				}
				else if (userinfo->mode==2)
				{
					double tickmedio[MAX_BOTS];
					for (int i = 0; (i < MAX_BOTS) && (tickmedio[i] - tickmedio[i - 1] > 0.1); i++)
					{
						double sum = 0.0;
						for (int a = 0; i < 1000; ++i)
						{
							simulation s( userinfo->fil,userinfo->col, DIRTYFILE, i, CLEANFILE, BOTFILE, userinfo->col * 10, userinfo->fil * 10);

							sum += s.run();

						}
					}
				}
				//getchar();
				al_destroy_display(display);
				allegro_shut_down();

			}
			else
			{
				cout << "Couldnt start display" << endl;
				allegro_shut_down();
			}
		}
		else
		{
			cout << "Couldnt start allegro" << endl;
		}
	}
	else
	{
		cout << "input invalid" << endl;		//mensaje de error de parseo
	}
	return 0;
}
