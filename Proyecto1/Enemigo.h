#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "Player.h"
using namespace sf;

class Enemigo
{
private:
	Texture textura;
	Sprite sprite;
	float timer = 0;
	bool alive = true;
public:
	Enemigo();
	Enemigo(int x, int y);
	Enemigo(int skin, int x, int y);
	~Enemigo();
	Sprite GetSprite();
	bool GetAlive();
	void Colision(Sprite player, bool armed);
	void ChasePlayer(Sprite player, bool armed, float elapsed);
	void JUMPUPJUMPUPANDGETDOWN(float elapsed);
};

#endif ENEMIGO_H