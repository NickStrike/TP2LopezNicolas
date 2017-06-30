#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
	
	RenderWindow *window = new RenderWindow(VideoMode(800, 600), "VidyaGmae.exe");

	Menu *menu = new Menu();
	menu->MainMenu(window);

	delete menu;
}