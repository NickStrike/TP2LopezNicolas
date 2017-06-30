#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "Player.h"
#include "GameLoop.h"
#include "Enemigo.h"
#include "Armamento.h"
#include "Credits.h"
#include <iostream>


using namespace sf;
using namespace std;

GameLoop::GameLoop() 
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::Run(RenderWindow *window)
{
	int num = 0;
	bool game = true;
	Credits *credits = new Credits();
	Armamento *armamento = new Armamento(750, 300); //posicion x,y
	Player *player = new Player(20, 300); //posicion x, y
	Enemigo *enemigo1 = new Enemigo(4, 400, 300); //skin, x, y
	Enemigo *enemigo2 = new Enemigo(3, 400, 300); //skin, x, y
	Enemigo *enemigo3 = new Enemigo(0, 700, 300); //skin, x, y
	Enemigo *enemigo4 = new Enemigo(2, 400, 50); //skin, x, y
	Clock clock;
	Time elapsed;
	float score;
	float timeScore = 0;
	
	while (window->isOpen() && game == true)
	{
		elapsed = clock.restart();
		Event event;
		timeScore += elapsed.asSeconds();

		window->draw(armamento->GetSprite());
		window->draw(player->GetPos());
		window->draw(enemigo1->GetSprite());
		window->draw(enemigo2->GetSprite());
		window->draw(enemigo3->GetSprite());
		window->draw(enemigo4->GetSprite());

		player->Movimiento(elapsed.asSeconds());
		enemigo1->ChasePlayer(player->GetPos(), player->GetArmed(), elapsed.asSeconds());
		enemigo3->ChasePlayer(player->GetPos(), player->GetArmed(), elapsed.asSeconds());
		enemigo2->JUMPUPJUMPUPANDGETDOWN(elapsed.asSeconds());
		enemigo4->JUMPUPJUMPUPANDGETDOWN(elapsed.asSeconds());

		enemigo1->Colision(player->GetPos(), player->GetArmed());
		enemigo2->Colision(player->GetPos(), player->GetArmed());
		enemigo3->Colision(player->GetPos(), player->GetArmed());
		enemigo4->Colision(player->GetPos(), player->GetArmed());

		player->Colision(enemigo1->GetSprite(), armamento->GetSprite());
		player->Colision(enemigo2->GetSprite(), armamento->GetSprite());
		player->Colision(enemigo3->GetSprite(), armamento->GetSprite());
		player->Colision(enemigo4->GetSprite(), armamento->GetSprite());
		armamento->Colision(player->GetPos());
		

		if (enemigo1->GetAlive() == false &&
			enemigo2->GetAlive() == false && 
			enemigo3->GetAlive() == false && 
			enemigo4->GetAlive() == false)
			while (num < 1)
			{
				score = timeScore;
				cout << score << endl;
				game = false;
				num++;
			}
		
		if (player->GetAlive() == false)
		{
			game = false;

		}
		if (game == false)
			credits->ShowCreds(window);

		while (window->pollEvent(event));
		{
			if (event.type == Event::Closed)
				window->close();
		}
		
		window->display();
		window->clear();
	}

	delete player;
	delete enemigo1;
	delete enemigo2;
	delete enemigo3;
	delete enemigo4;
	
}