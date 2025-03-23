#pragma once
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;

class Walls
{
public:
	Walls(const char* pathToWallsTexture, int screenW, int screenH);
	ConvexShape upWall;
	ConvexShape downWall;
	Texture wallsTexture;
	Vector2f coordinatCollision;
	std::vector<Vector2f> idealTrajectory;
	Vector2f collisionOffset;
	Vector2f reactionForces;
	int numOfCollisions = 0;
	void resolveCollisions(Vector2f botPos); // main function for collisions calculation
	void update(Vector2f botPos, int32_t ms);
	void testUpdate(int screenW, int screenH);
private:
	void calcCollisions(Vector2f botPos); // calc 1) coordinats of collisionPoint 2) offest of collision for calculation reaction forces
	void calcReations(); // calculation reaction forces after calculation calculation
	int mapFloatToInt(float x, float in_min, float in_max, float out_min, float out_max);
	float constrain(float x, float out_max, float out_min);
	size_t numOfPoints = 0;
	int scrW, scrH;
};

