#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class MicroBot
{
public:
	MicroBot(const char* pathToMagnitTexture, const char* pathToBotTexture, float initMagnitX, float initMagnitY, float botOffsetX, float botOffsetY, float rigidCoeff);
	void update(float newMagnitX, float newMagnitY, int dt);
	Sprite *magnit;
	Sprite *bot;
private:
	Vector2<float> prevMagnitPos;
	Vector2<float> prevBotPos;
	Vector2<float> magnitPos;
	Vector2<float> botPos;
	Texture magnitTexture;
	Texture botTexture;
	Vector2u mTsize;
	Vector2u bTsize;
	float bOffsetX;
	float bOffsetY;
	float rC;
};

