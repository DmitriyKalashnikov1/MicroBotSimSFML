#include "Walls.h"

Walls::Walls(const char* pathToWallsTexture, int screenW, int screenH)
{
	wallsTexture.loadFromFile(pathToWallsTexture);

	numOfPoints = (size_t)(screenW/10);
	scrW = screenW;
	scrH = screenH;

	upWall.setPointCount(numOfPoints+1);
	downWall.setPointCount(numOfPoints+1);

	upWall.setPoint(0, {0.0f, 0.0f});
	upWall.setPoint(1, Vector2f(screenW, 0.f));

	downWall.setPoint(numOfPoints, Vector2f(0, screenH));
	downWall.setPoint(numOfPoints - 1, Vector2f(screenW, screenH));

	upWall.setTexture(&wallsTexture);
	downWall.setTexture(&wallsTexture);

	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_real_distribution<> distr{ 0.f, 6.28 };


	 float upWallXDec = 0;

	float OFFSET = 0.2 * scrH;

	float AMP = 100.f; //32767;
	float angle = distr(gen);

	for (int f = 2; f < numOfPoints; f++) {

		upWall.setPoint(f, Vector2f(scrW - upWallXDec, AMP*sin(angle)+OFFSET));
	    upWallXDec += 10;
		angle += (2 * 3.14 * upWallXDec*0.001) / numOfPoints;
	}
	upWall.setPoint(numOfPoints, Vector2f(0.f, 0.2 * scrH));
}

void Walls::resolveCollisions(Vector2f botPos)
{
}

void Walls::update(Vector2f botPos, int32_t ms)
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_real_distribution<> distr{ 0.f, 6.28 };
	//static float angle = 0;

	//static int upWallXDec = 0;

	//float OFFSET = 0.2 * scrH;

	//float AMP = 100.f; //32767;
	//
	//float tmp = constrain(botPos.x, (float)scrW, 0.f);
	//int index = mapFloatToInt(tmp, 0.f, (float)scrW, 2, numOfPoints - 1);

	//upWall.setPoint(index, Vector2f(scrW - upWallXDec, AMP * sin(angle) + OFFSET));
	//if (upWallXDec < scrW) {
	//	upWallXDec += 10;
	//}
	//else {
	//	upWallXDec = 0;
	//	angle = distr(gen);
	//}
	//angle += (2 * 3.14 * upWallXDec * 0.001) / numOfPoints;
	//upWall.setPoint(numOfPoints, Vector2f(0.f, 0.2 * scrH));

	float upWallXDec = 0;

	float OFFSET = 0.2 * scrH;

	float AMP = 100.f; //32767;
	float angle = distr(gen);

	for (int f = 2; f < numOfPoints; f++) {

		upWall.setPoint(f, Vector2f(scrW - upWallXDec, AMP * sin(angle) + OFFSET));
		upWallXDec += 10;
		angle += (2 * 3.14 * upWallXDec * 0.001) / numOfPoints;
	}
	upWall.setPoint(numOfPoints, Vector2f(0.f, 0.2 * scrH));
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
