#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class MicroBot
{
public:
	MicroBot(const char* pathToMagnitTexture, const char* pathToBotTexture, float initMagnitX, float initMagnitY, float botOffsetX, float botOffsetY, float rigidCoeff, float velocityCoef, float bMass);
	void update(float newMagnitX, float newMagnitY, uint32_t dt, bool withPhis);
	Sprite *magnit;
	Sprite *bot;
	int botScore;
	Vector2<float> magnitPos;
	Vector2<float> botPos;
private:
	Vector2<float> prevMagnitPos;
	Vector2<float> prevBotPos;
	
	float botMass;
	Texture magnitTexture;
	Texture botTexture;
	Vector2u mTsize;
	Vector2u bTsize;
	float bOffsetX;
	float bOffsetY;
	float rC;
	float vC;
};

