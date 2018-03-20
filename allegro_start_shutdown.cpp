#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

#include "allegro_start_shutdown.h"




int allegro_startup(void)
{
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_init_image_addon())
			{
				return AL_STARTUP_SUCCESS;
			}
			else
				fprintf(stderr, "ERROR: Failed to load primitives addon\n");
			al_shutdown_primitives_addon();
		}
		else
			fprintf(stderr, "ERROR: Failed to install keyboard\n");
		al_uninstall_system();
	}
	else
		fprintf(stderr, "ERROR: Failed to initialize allegro system\n");
	return AL_STARTUP_ERROR;
}

void allegro_shut_down(void)
{
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_uninstall_system();
}