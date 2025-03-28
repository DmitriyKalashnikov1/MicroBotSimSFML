#include "Walls.h"

Walls::Walls(const char* pathToWallsTexture, int screenW, int screenH)
{
	wallsTexture.loadFromFile(pathToWallsTexture);

	numOfPoints = (size_t)(screenW/10);
	scrW = screenW;
	scrH = screenH;


	upWall.setPointCount(numOfPoints);
	downWall.setPointCount(numOfPoints);

	upWall.setPoint(0, {0.0f, 0.0f});
	upWall.setPoint(1, Vector2f(screenW, 0.f));

	downWall.setPoint(numOfPoints - 1, Vector2f(0, screenH));
	downWall.setPoint(numOfPoints - 2, Vector2f(screenW, screenH));

	upWall.setTexture(&wallsTexture);
	downWall.setTexture(&wallsTexture);

	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_real_distribution<> angleDistr{ 0.f, 6.28 };
	std::uniform_int_distribution<> ampDistr{100, 300};
	
	float OFFSETup = 0.2 * scrH;
	float OFFSETdown = 0.8 * scrH;

	float angle = angleDistr(gen);

	float upWallXDec = 0;

	for (int f = 0; f < mapLenght; f++) {
		int AMPup = ampDistr(gen);
		int AMPdown = ampDistr(gen);
		upMap[f] = AMPup * sin(0.01*f) + OFFSETup;
		downMap[f] = AMPdown * cos(0.01*f) + OFFSETdown;

	}

	upWallXDec = 0;
	stepCounter = mapLenght;

	
	int offset = 0;
	for (int f = 2; f < numOfPoints; f++) {

		upWall.setPoint(f, Vector2f(scrW - upWallXDec, upMap[stepCounter-offset]));
	    upWallXDec += 10;
		offset--;
	}

	upWall.setPoint(numOfPoints, Vector2f(0.f, 0.2 * scrH));

	upWallXDec = 0;

	offset = 0;
	for (int f = numOfPoints - 3; f > 0 ; f--) {

		downWall.setPoint(f, Vector2f(scrW - upWallXDec, downMap[stepCounter - offset]));
		upWallXDec += 10;
		offset--;
	}
	stepCounter -= offset;

}

void Walls::resolveCollisions(Vector2f botPos)
{
}

void Walls::update(Vector2f magnitPos, int32_t ms)
{
	if (magnitPos.x - prevMagnitPos.x > 10) {
		

		
		float upWallXDec = 0;
		int offset = 0;
		for (int f = 2; f < numOfPoints; f++) {

			upWall.setPoint(f, Vector2f(scrW - upWallXDec, upMap[stepCounter - offset]));
			upWallXDec += 10;
			offset--;
		}
		upWallXDec = 0;
		stepCounter -= 1;

		
		prevMagnitPos.x = magnitPos.x;
	}

	
}

void Walls::testUpdate(int screenW, int screenH)
{
	upWall.setPoint(2, Vector2f(screenH, 0.2*screenW));
	upWall.setPoint(3, Vector2f(0.f, 0.2 * screenW));
	
	downWall.setPoint(0, Vector2f(0.f, 0.8*screenW));
	downWall.setPoint(1, Vector2f(screenH, 0.8 * screenW));
	//downWall.setPoint();
}

void Walls::calcCollisions(Vector2f botPos)
{
}

void Walls::calcReations()
{
}

int Walls::mapFloatToInt(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (int)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

float Walls::constrain(float x, float out_max, float out_min)
{
	if (x > out_max) {
		return out_max;
	}
	else if (x < out_min) {
		return out_min;
	}
	else {
		return x;
	}
}
