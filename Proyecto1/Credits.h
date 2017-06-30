#ifndef CREDITS_H
#define CREDITS_H
class Credits
{
private:
	Texture textura;
	Sprite sprite;
	bool game = true;
public:
	Credits();
	~Credits();
	void ShowCreds(RenderWindow *window);
};

#endif 