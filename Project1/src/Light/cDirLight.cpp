#include "cDirLight.h"

cDirLight::cDirLight()
{
	this->direction = glm::vec4(0.f, 0.f, 0.f, 1.f);
	this->ambient = 1;
	this->diffuse = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->specular = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->turnON = 0;

	this->direction_location = -1;
	this->ambient_location = -1;
	this->diffuse_location = -1;
	this->specular_location = -1;
	this->turnON_location = -1;
}

cDirLight::~cDirLight()
{
}
