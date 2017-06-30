#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
using namespace sf;
using namespace std;
class GameLoop
{
public:
	GameLoop();
	~GameLoop();
	void Run(RenderWindow *window);
};
#endif 