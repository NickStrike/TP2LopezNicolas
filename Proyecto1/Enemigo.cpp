#include "Enemigo.h"

Enemigo::Enemigo()
{
	textura.loadFromFile("enemy1.png");
	sprite.setTexture(textura);
	sprite.setPosition(700, 500);
	sprite.setOrigin(14, 35);
	sprite.setScale(2.f, 2.f);
}
Enemigo::Enemigo(int x, int y)
{
	textura.loadFromFile("enemy1.png");
	sprite.setTexture(textura);
	sprite.setPosition(x, y);
	sprite.setOrigin(14, 35);
	sprite.setScale(2.f, 2.f);
}
Enemigo::Enemigo(int skin, int x, int y)
{
	if (skin == 0)
	{
		textura.loadFromFile("enemy1.png");
		sprite.setTexture(textura);
		sprite.setPosition(x, y);
		sprite.setOrigin(14,35);
		sprite.setScale(2.f, 2.f);
	}

	if (skin == 1)
	{
		textura.loadFromFile("enemy2.png");
		sprite.setTexture(textura);
		sprite.setPosition(x, y);
		sprite.setOrigin(12, 19);
		sprite.setScale(2.f, 2.f);
	}

	if (skin == 2)
	{
		textura.loadFromFile("enemy3.png");
		sprite.setTexture(textura);
		sprite.setPosition(x, y);
		sprite.setOrigin(20, 22);
		sprite.setScale(2.f, 2.f);
	}

	if (skin == 3)
	{
		textura.loadFromFile("enemy4.png");
		sprite.setTexture(textura);
		sprite.setPosition(x, y);
		sprite.setOrigin(15, 24);
		sprite.setScale(2.f, 2.f);
	}

	if (skin == 4)
	{
		textura.loadFromFile("enemy5.png");
		sprite.setTexture(textura);
		sprite.setPosition(x, y);
		sprite.setOrigin(9, 27);
		sprite.setScale(2.f, 2.f);
	}
}
Enemigo::~Enemigo()
{
	sprite.setScale(0, 0);
	alive = false;
}

Sprite Enemigo::GetSprite()
{
	return sprite;
}

bool Enemigo::GetAlive()
{
	return alive;
}

void Enemigo::Colision(Sprite player, bool armed)
{
	if (armed == true)
	{
		if (sprite.getGlobalBounds().intersects(player.getGlobalBounds()))	
			{
				Enemigo::~Enemigo();
			}
	}
}

void Enemigo::ChasePlayer(Sprite player, bool armed, float elapsed) 
{	
	if (armed == false && alive == true){
		if (player.getPosition().x > sprite.getPosition().x && sprite.getPosition().x + 40 < 800)
		{
			sprite.move(100 * elapsed, 0);
			sprite.setScale(2.f, 2.f);
		}
		if (player.getPosition().y > sprite.getPosition().y && sprite.getPosition().y + 20 < 600)
		{
			sprite.move(0, 100 * elapsed);
		}
		if (player.getPosition().x < sprite.getPosition().x && sprite.getPosition().x - 40 > 0)
		{
			sprite.move(-100 * elapsed, 0);
			sprite.setScale(-2.f, 2.f);
		}
		if (player.getPosition().y < sprite.getPosition().y && sprite.getPosition().y - 40 > 0)
		{
			sprite.move(0, -100 * elapsed);
		}
	}

	if (armed == true && alive == true) {
		if (player.getPosition().x > sprite.getPosition().x && sprite.getPosition().x - 40 > 0)
		{
			sprite.move(-100 * elapsed, 0);
			sprite.setScale(2.f, 2.f);
		}
		if (player.getPosition().y > sprite.getPosition().y && sprite.getPosition().y - 40 > 0)
		{
			sprite.move(0, -100 * elapsed);
		}
		if (player.getPosition().x < sprite.getPosition().x && sprite.getPosition().x + 40 < 800)
		{
			sprite.move(100 * elapsed, 0);
			sprite.setScale(-2.f, 2.f);
		}
		if (player.getPosition().y < sprite.getPosition().y && sprite.getPosition().y + 20 < 600)
		{
			sprite.move(0, 100 * elapsed);
		}
	}
	
}

//JUMP AROUND  

void Enemigo::JUMPUPJUMPUPANDGETDOWN(float elapsed) 
{
	//JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP JUMP
	timer += elapsed;
	if (alive == true)
	{
		if (timer < 0.5)
		{
			sprite.move(0, 500 * elapsed);
		}
		if (timer > 0.5)
		{
			sprite.move(0, -500 * elapsed);
		}
		if (timer >= 1)
			timer = 0;
	}
}
