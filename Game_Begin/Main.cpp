#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>

enum KBRDKEYS {UP, DOWN, LEFT, RIGHT};
enum MOUSEKEYS{LCLCK, RCLCK};
int main()
{
	//Initialisations and Installations
	//Function Prototype Declarations
	//Control Variable Initialisations
	bool done = true;

	//Allegro Initialisations
	if (!al_init()) return -1;
	al_install_keyboard();
	al_init_primitives_addon();
	
	//Allegro Variable Declarations
	ALLEGRO_DISPLAY *mainDisplay = NULL;
	ALLEGRO_EVENT_QUEUE *mainQueue = NULL;
	ALLEGRO_TIMER *gameLoopTimer = NULL;

	//Display Initialisation
	int width = 640;
	int height = 480;
	mainDisplay = al_create_display(width, height);
	if (!mainDisplay) return -1;

	//SetUp Event Queue
	mainQueue = al_create_event_queue();
	al_register_event_source(mainQueue, al_get_keyboard_event_source());
	al_register_event_source(mainQueue, al_get_display_event_source(mainDisplay));
	al_register_event_source(mainQueue, al_get_mouse_event_source());
	al_register_event_source(mainQueue, al_get_timer_event_source(gameLoopTimer));
	
	//Input Variables Initialisation
	bool KBRDKEYS[4] = { false, false, false, false };
	bool MOUSEKEYS[2] = { false, false };
	
	//Timer Setup
	int FPS = 60;
	gameLoopTimer = al_create_timer(1 / FPS);
	al_start_timer(gameLoopTimer);

	//Main Game Loop
	while (!done)
	{
		ALLEGRO_EVENT gameEvent;
		al_wait_for_event(mainQueue, &gameEvent);
		if (gameEvent.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (gameEvent.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
				case ALLEGRO_KEY_W:
					KBRDKEYS[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
				case ALLEGRO_KEY_S:
					KBRDKEYS[DOWN] = true;
					break;
				case ALLEGRO_KEY_LEFT:
				case ALLEGRO_KEY_A:
					KBRDKEYS[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
				case ALLEGRO_KEY_D:
					KBRDKEYS[RIGHT] = true;
					break;
			}
				
		}
		else if (gameEvent.type == ALLEGRO_EVENT_KEY_DOWN)
			int cat;



	}
}