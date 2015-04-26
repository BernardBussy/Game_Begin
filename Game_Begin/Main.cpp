#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "Player.h"

enum KBRDKEYS {UP, DOWN, LEFT, RIGHT};
int main()
{
	//Initialisations and Installations
	
	//Function Prototype Declarations
	void playerUpdate(Player *, bool[]);
	
	
	
	//Variable Initialisations
	int width = 640;
	int height = 480;
	bool done = false;
	bool draw = true;
	int pos_x = width / 2;
	int pos_y = height / 2;
	int FPS = 60;
	bool KBRDKEYS[4] = { false, false, false, false };
	//Glame Variable Initialisations
	Player player1(33, 33, 100, 4, height, width);

	//Allegro Variable Declarations
	ALLEGRO_DISPLAY *mainDisplay = NULL;
	ALLEGRO_EVENT_QUEUE *mainQueue = NULL;
	ALLEGRO_TIMER *gameLoopTimer = NULL;
	ALLEGRO_MOUSE_STATE mouseState;

	//Allegro Initialisations
	if (!al_init())
		return -1;
	mainDisplay = al_create_display(width, height);
	if (!mainDisplay)
		return -1;
	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_image_addon();

	mainQueue = al_create_event_queue();
	gameLoopTimer = al_create_timer(1.0 / FPS);

	al_register_event_source(mainQueue, al_get_keyboard_event_source());
	al_register_event_source(mainQueue, al_get_mouse_event_source());
	al_register_event_source(mainQueue, al_get_display_event_source(mainDisplay));
	al_register_event_source(mainQueue, al_get_timer_event_source(gameLoopTimer));
	al_get_mouse_state(&mouseState);

	//Timer Setup
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
		else if (gameEvent.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (gameEvent.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
			case ALLEGRO_KEY_W:
				KBRDKEYS[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
			case ALLEGRO_KEY_S:
				KBRDKEYS[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
			case ALLEGRO_KEY_A:
				KBRDKEYS[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
			case ALLEGRO_KEY_D:
				KBRDKEYS[RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		else if (gameEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			al_get_mouse_state(&mouseState);
		}
		else if (gameEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			al_get_mouse_state(&mouseState);
		}
		else if (gameEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (gameEvent.type == ALLEGRO_EVENT_TIMER)
		{
			playerUpdate(&player1, KBRDKEYS);
			draw = true;
		}
		if (draw && al_is_event_queue_empty(mainQueue))
		{
			player1.draw();
			draw = false;
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}
}
void playerUpdate(Player *player, bool keys[])
{
	enum Direction {D, L, R, U};
	if (keys[RIGHT])
	{
		player->Update(1, 0, 0);
		player->updateanimation(R);
	}
	if (keys[LEFT])
	{
		player->Update(-1, 0, 0);
		player->updateanimation(L);
	}
	if (keys[DOWN])
	{
		player->Update(0, 1, 0);
		player->updateanimation(D);
	}
	if (keys[UP])
	{
		player->Update(0, -1, 0);
		player->updateanimation(U);
	}
}