#pragma once
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

class cLight
{
public:
	cLight();
	~cLight();

	glm::vec4 position;
	glm::vec4 diffuse;
	glm::vec4 specular;
	glm::vec4 attenuation;
	glm::vec4 direction;
	glm::vec4 param1;
	glm::vec4 param2; 

	int position_location;
	int diffuse_location;
	int specular_location;
	int attenuation_location;
	int direction_location;
	int param1_location;
	int param2_location;

	void setConstantAttenuation(float newConstAtten);
	void setLinearAttenuation(float newLinearAtten);
	void setQuadraticAttenuation(float newQuadAtten);


};

