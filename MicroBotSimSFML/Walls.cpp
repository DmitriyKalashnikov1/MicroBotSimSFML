#include "Walls.h"

Walls::Walls(const char* pathToWallsTexture, int screenW, int screenH)
{
	wallsTexture.loadFromFile(pathToWallsTexture);

	upWall.setPointCount(numOfPoints);
	downWall.setPointCount(numOfPoints);

	upWall.setPoint(0, {0.0f, 0.0f});
	upWall.setPoint(1, Vector2f(screenH, 0.f));

	downWall.setPoint(numOfPoints - 1, Vector2f(0, screenW));
	downWall.setPoint(numOfPoints - 2, Vector2f(screenH, screenW));

	upWall.setTexture(&wallsTexture);
	downWall.setTexture(&wallsTexture);
}

void Walls::resolveCollisions(Vector2f botPos)
{
}

void Walls::update(int distForRightEdge)
{
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
