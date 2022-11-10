#pragma once
#include <glm/glm.hpp>

class cRobot
{
public:
	cRobot();
	~cRobot();

	int id;
	int health;
	glm::vec3 position;

};

