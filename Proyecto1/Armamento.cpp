#include "Armamento.h"



Armamento::Armamento()
{
	textura.loadFromFile("epee.png");
	sprite.setTexture(textura);
	sprite.setPosition(400, 300);
	sprite.setScale(1.5f, 1.5f);
}

Armamento::Armamento(int x, int y)
{
	textura.loadFromFile("epee.png");
	sprite.setTexture(textura);
	sprite.setPosition(x, y);
	sprite.setScale(1.5f, 1.5f);
}

Armamento::~Armamento()
{
}

Sprite Armamento::GetSprite()
{
	return sprite;
}

void Armamento::Colision(Sprite player)
{
	if (sprite.getGlobalBounds().intersects(player.getGlobalBounds()))
		sprite.setScale(0, 0);
}