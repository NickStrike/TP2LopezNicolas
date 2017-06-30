#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "Player.h"
#include "GameLoop.h"
#include "Enemigo.h"
#include "Armamento.h"
#include <iostream>
#include "Credits.h"
using namespace std;
Credits::Credits()
{
	textura.loadFromFile("credits.png");
	sprite.setTexture(textura);
	sprite.setPosition(0, 0);
}


Credits::~Credits()
{
}

void Credits::ShowCreds(RenderWindow *window)
{
	while (game == true)
	{
		Event event;
		
		window->draw(sprite);
		while (window->pollEvent(event));
		{
			if (event.type == Event::Closed)
				window->close();
		}

		window->display();
		window->clear();
	}
}