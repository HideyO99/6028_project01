#pragma once
//#include "cLight.h"
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

class cSpotLight //: public cLight
{
public:
	cSpotLight();
	~cSpotLight();

	glm::vec4 position;
	glm::vec4 direction;
	float ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;
	float constant;
	float linear;
	float quadratic;
	float innerAngle;
	float outerAngle;
	int turnON;

	int position_location;
	int direction_location;
	int ambient_location;
	int diffuse_location;
	int specular_location;
	int constant_location;
	int linear_location;
	int quadratic_location;
	int innerAngle_location;
	int outerAngle_location;
	int turnON_location;
};

