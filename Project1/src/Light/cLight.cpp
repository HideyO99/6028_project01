#include "cLight.h"

cLight::cLight()
{
	this->position = glm::vec4(0.f, 0.f, 0.f, 1.f);
	this->diffuse = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->specular = glm::vec4(1.f, 1.f, 1.f, 1.f);
	this->attenuation = glm::vec4(0.1f, 0.1f, 0.f, 1.f);
	this->direction = glm::vec4(0.f, 0.f, 1.f, 1.f);
	param1 = glm::vec4(0.f, 0.f, 0.f, 1.f);
	param2 = glm::vec4(0.f, 0.f, 0.f, 1.f);

	position_location = -1;
	diffuse_location = -1;
	specular_location = -1;
	attenuation_location = -1;
	direction_location = -1;
}

cLight::~cLight()
{
}

void cLight::setConstantAttenuation(float newConstAtten)
{
	this->attenuation.x = newConstAtten;
}

void cLight::setLinearAttenuation(float newLinearAtten)
{
	this->attenuation.y = newLinearAtten;
}

void cLight::setQuadraticAttenuation(float newQuadAtten)
{
	this->attenuation.z = newQuadAtten;
}
