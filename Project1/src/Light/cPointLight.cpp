#include "cPointLight.h"

cPointLight::cPointLight()
{
	this->position = glm::vec4(0.f, 0.f, 0.f, 1.f);
	this->ambient = 1;
	this->diffuse = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->specular = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->constant = 0.1f;
    this->linear = 0.1f;
    this->quadratic = 0.f;
	this->turnON = 0;

	this->position_location = -1;
	this->ambient_location = -1;
	this->diffuse_location = -1;
	this->specular_location = -1;
	this->constant_location = -1;
	this->linear_location = -1;
	this->quadratic_location = -1;
	this->turnON_location = -1;
}

cPointLight::~cPointLight()
{
}
