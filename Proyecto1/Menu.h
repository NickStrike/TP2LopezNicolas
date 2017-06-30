#ifndef MENU_H
#define MENU_H
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "GameLoop.h"
#include <iostream>

using namespace sf;
using namespace std;

class Menu
{
private:
	Texture textura;
	Sprite sprite;
	Keyboard keyboard;
	GameLoop *gameloop;
	bool game = true;
public:
	Menu();
	~Menu();
	void MainMenu(RenderWindow *window);
};

#endif