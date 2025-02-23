#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Star
{
public:
	Star(Vector2f pos, const char* pathToTexture);
	int scoreIncrement = 50;
	Sprite* shape;
	Vector2f offset{50, 50};
private:
	Texture starTexture;
};

