#include <stdio.h>
#include <allegro5/allegro.h>

enum KBRDKEYS {UP, DOWN, LEFT, RIGHT};
enum MOUSEKEYS{LCLCK, RCLCK};
int main()
{
	//Main Display Variables Initialisation
	int width = 640;
	int height = 480;

	//Input Variables Initialisation
	bool KBRDKEYS[4] = { false, false, false, false };
	bool MOUSEKEYS[2] = { false, false };
}