#include "Star.h"

Star::Star(Vector2f pos, const char* pathToTexture)
{
	starTexture.loadFromFile(pathToTexture);
	shape = new Sprite(starTexture);
	
	shape->setPosition(pos);
}
