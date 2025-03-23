#include "MicroBot.h"

MicroBot::MicroBot(const char* pathToMagnitTexture, const char* pathToBotTexture, float initMagnitX, float initMagnitY, float botOffsetX, float botOffsetY, float rigidCoeff, float velocityCoef, float bMass)
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
	vC = velocityCoef;
	botScore = 0;
	botMass = bMass;
}

void MicroBot::update(float newMagnitX, float newMagnitY, uint32_t dt, bool withPhis)
{
	prevMagnitPos.x = magnitPos.x;
	prevMagnitPos.y = magnitPos.y;

	magnitPos.x = newMagnitX - (mTsize.x / 2);
	magnitPos.y = newMagnitY - (mTsize.y / 2);

	magnit->setPosition(magnitPos);
	
	if (withPhis) {
		// bot phisics here
		// elastic force calk

		float botTargetX = magnitPos.x - bOffsetX - (bTsize.x / 2);
		float botTargetY = magnitPos.y + bOffsetY + (bTsize.y / 2);

		float botDeltaLX = prevBotPos.x - botTargetX;
		float botDeltaLY = botTargetY - prevBotPos.y;

		float botElasticForceX = rC * botDeltaLX;
		float botElasticForceY = rC * botDeltaLY;

		// velocity resistance force
		float botElasticForceAX = botElasticForceX / botMass;
		float botElasticForceAY = botElasticForceY / botMass;

		float botElasticForceVX = botElasticForceAX * dt;
		float botElasticForceVY = botElasticForceAY * dt;

		float botVelocityResistanceForceX = vC * botElasticForceVX;
		float botVelocityResistanceForceY = vC * botElasticForceVY;
		// offsets calk
		float botForcesAX = (botElasticForceX - botVelocityResistanceForceX) / botMass;
		float botForcesAY = (botElasticForceY - botVelocityResistanceForceY) / botMass;

		float offsetX = (botForcesAX * dt * dt) / 2;
		float offsetY = (botForcesAY * dt * dt) / 2;

		botPos.x = prevBotPos.x - offsetX;
		botPos.y = prevBotPos.y + offsetY;
		bot->setPosition(botPos);


		prevBotPos.x = botPos.x;
		prevBotPos.y = botPos.y;

	}
	else {
		botPos.x = newMagnitX - (bTsize.x / 2) - bOffsetX;
		botPos.y = newMagnitY + (bTsize.y / 2) + bOffsetY;

		prevBotPos.x = botPos.x;
		prevBotPos.y = botPos.y;
		bot->setPosition(botPos);
	}
}

