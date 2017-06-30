#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "Enemigo.h"
#include "Armamento.h"
using namespace sf;

class Player
{
private:
	bool alive = true;
	bool armed = false;
	Texture textura;
	Texture textura2;
	Keyboard keyboard;
	Sprite sprite;
public:
	Player();
	Player(int x, int y);
	~Player();
	Sprite GetPos();
	void Movimiento(float elapsed);
	void Colision(Sprite enemigo, Sprite armamento);
	bool GetArmed();
	bool GetAlive();
};
#endif PLAYER_H