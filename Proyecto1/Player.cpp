#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	textura.loadFromFile("spritearmed.png");
	textura2.loadFromFile("sprite.png");
	sprite.setTexture(textura);
	sprite.setPosition(0,0);
	sprite.setOrigin(20, 32);
	sprite.setScale(2.f, 2.f);
}

Player::Player(int x, int y)
{
	textura.loadFromFile("spritearmed.png");
	sprite.setTexture(textura);
	sprite.setPosition(x, y);
	sprite.setOrigin(20, 32);
	sprite.setScale(2.f, 2.f);
}

Player::~Player()
{
	sprite.setScale(0, 0);
	alive = false;
}

Sprite Player::GetPos()
{
	return sprite;
}

void Player::Movimiento(float elapsed)
{
	if (alive == true)
	{ 
		if (keyboard.isKeyPressed(keyboard.A) || keyboard.isKeyPressed(keyboard.Left)) 
		{
			sprite.move(-200 * elapsed, 0);
			sprite.setScale(-2.f, 2.f);
		}
		if (keyboard.isKeyPressed(keyboard.D) || keyboard.isKeyPressed(keyboard.Right))
		{
			sprite.move(200 * elapsed, 0);
			sprite.setScale(2.f, 2.f);
		}
		if (keyboard.isKeyPressed(keyboard.W) || keyboard.isKeyPressed(keyboard.Up))
		{
			sprite.move(0, -200 * elapsed);
		}
		if (keyboard.isKeyPressed(keyboard.S) || keyboard.isKeyPressed(keyboard.Down))
		{
			sprite.move(0, 200 * elapsed);
		}

		if (armed == true)
		{
			textura2.loadFromFile("sprite.png");
			sprite.setTexture(textura2);
			sprite.setOrigin(20, 32);
		}
	}
}	

void Player::Colision(Sprite enemigo, Sprite armamento)
{
	if (armed == false) {
		if (sprite.getGlobalBounds().intersects(enemigo.getGlobalBounds()))
			Player::~Player();
	}

	if (sprite.getGlobalBounds().intersects(armamento.getGlobalBounds()))
	{ 
		armed = true;
		cout << "ARMED" << endl;
	}
}

bool Player::GetArmed()
{
	return armed;
}

bool Player::GetAlive()
{
	return alive;
}