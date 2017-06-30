#include "Menu.h"



Menu::Menu()
{
	textura.loadFromFile("Menu.png");
	sprite.setTexture(textura);
	sprite.setPosition(0, 0);
}


Menu::~Menu()
{
}

void Menu::MainMenu(RenderWindow *window)
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

		if (keyboard.isKeyPressed(keyboard.P))
		{
			gameloop->Run(window);
			game = false;
		}
		
		window->display();
		window->clear();
	}
	
}