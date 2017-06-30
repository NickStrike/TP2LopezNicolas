#ifndef ARMAMENTO_H
#define ARMAMENTO_H
#include <SFML\Graphics.hpp>
#include "Player.h"
#include <iostream>
using namespace sf;
class Armamento
{
private:
	Texture textura;
	Sprite sprite;

public:
	Armamento();
	Armamento(int x, int y);
	~Armamento();
	Sprite GetSprite();
	void Colision(Sprite player);
};

#endif