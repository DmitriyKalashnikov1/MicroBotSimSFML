#include "MicroBot.h"

MicroBot::MicroBot(const char* pathToMagnitTexture, const char* pathToBotTexture, float initMagnitX, float initMagnitY, float botOffsetX, float botOffsetY, float rigidCoeff)
{
	magnitTexture.loadFromFile(pathToMagnitTexture);
	botTexture.loadFromFile(pathToBotTexture);
	
	mTsize = magnitTexture.getSize();
	bTsize = botTexture.getSize();

	magnitPos.x = initMagnitX - (mTsize.x / 2);
	magnitPos.y = initMagnitY - (mTsize.y / 2);

	botPos.x = initMagnitX - (bTsize.x / 2) - botOffsetX;
	botPos.y = initMagnitY + (bTsize.y / 2) + botOffsetY;

	bOffsetX = botOffsetX;
	bOffsetY = botOffsetY;

	prevBotPos.x = botPos.x;
	prevBotPos.y = botPos.y;

	prevMagnitPos.x = magnitPos.x;
	prevMagnitPos.y = magnitPos.y;

	magnit = new Sprite(magnitTexture);
	bot = new Sprite(botTexture);

	magnit->setPosition(magnitPos);
	bot->setPosition(botPos);

	rC = rigidCoeff;
}

void MicroBot::update(float newMagnitX, float newMagnitY, int dt)
{
	prevMagnitPos.x = magnitPos.x;
	prevMagnitPos.y = magnitPos.y;

	prevBotPos.x = botPos.x;
	prevBotPos.y = botPos.y;

	magnitPos.x = newMagnitX - (mTsize.x / 2);
	magnitPos.y = newMagnitY - (mTsize.y / 2);

	magnit->setPosition(magnitPos);
	// bot phisics here
	// tmp code
	botPos.x = magnitPos.x - bOffsetX - (bTsize.x / 2);
	botPos.y = magnitPos.y + bOffsetY + (bTsize.y / 2);

	bot->setPosition(botPos);
}

